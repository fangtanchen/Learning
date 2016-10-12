#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXK=1000000010;
const int MINK=-100;

struct Node{
    int key;
    Node *left,*right,*fa;
    Node(int k){
        left=right=fa=NULL;
        key=k;
    }
};

Node *root;

Node *InsertSplay(Node *x,int y);

void Init(){
    root=new Node(MINK);
    InsertSplay(root,MAXK);
}

void LeftRotate(Node *a){
     Node *b=a->right;
     b->fa=a->fa;
     if(a->fa){
         if(a==a->fa->left)a->fa->left=b;
         else a->fa->right=b;
     }
     a->right=b->left;
     if(b->left){
          b->left->fa=a;
     }
     b->left=a;a->fa=b;
}

void RightRotate(Node *a){
     Node *b=a->left;
     b->fa=a->fa;
     if(a->fa){
         if(a->fa->left==a)a->fa->left=b;
         else a->fa->right=b;
     }
     a->left=b->right;
     if(b->right)b->right->fa=a;
     a->fa=b;b->right=a;
}

void Splay(Node *x, Node *y){
    while(x->fa!=y){
        Node *fx=x->fa;
        if(fx->fa==y){
            if(fx->left==x){
                RightRotate(fx);
            }else{
                LeftRotate(fx);
            }
        }else{
             Node* g=fx->fa;
             if(g->left==fx){
                 if(fx->left==x){
                     RightRotate(g);
                     RightRotate(fx);
                 }else{
                     LeftRotate(x->fa);
                     RightRotate(x->fa);
                 }
             }else{
                 if(fx->right==x){
                    LeftRotate(g);
                    LeftRotate(fx);
                 }else{
                     RightRotate(x->fa);
                     LeftRotate(x->fa);
                 }
             }
        }
    }
}

Node *Insert(Node *node,int k){
    if(k<node->key){
        if(node->left==NULL){
            node->left=new Node(k);
            node->left->fa=node;
            return node->left;
        }else{
             return Insert(node->left,k);
        }
    }else  if(k>node->key){
        if(node->right==NULL){
            node->right=new Node(k);
            node->right->fa=node;
            return node->right;
        }else{
            return Insert(node->right,k);
        }
    }else{
         return node;
    }
}

Node *Find(Node *node, int k){
    while(node){
        if(k<node->key)node=node->left;
        else if(k>node->key){
             node=node->right;
        }else{
            Splay(node,NULL);
            return node;
        }
    }
    return NULL;
}

Node *InsertSplay(Node *node, int k){
    Node *tmp=Insert(node,k);
    Splay(tmp,NULL);// adjust the tree to more balanced
    return tmp;
}

Node *FindPrev(Node *node){
    Splay(node,NULL);
    Node *tmp=node->left;
    while(tmp->right){
        tmp=tmp->right;
    }
    return tmp;
}

Node *FindNext(Node *node){
     Splay(node,NULL);
     Node *tmp=node->right;
     while(tmp->left){
         tmp=tmp->left;
     }
     return tmp;
}

bool Delete(Node *node,int k){
     Node *tmp=Find(node,k);
     if(tmp==NULL)return false;
     Node *prev=FindPrev(tmp);
     Node *nxt=FindNext(tmp);
     Splay(prev,NULL);
     Splay(nxt,prev);
     free(nxt->left);
     nxt->left=NULL;
     return true;
}

void Free(Node *node){
    if(node->left){
        Free(node->left);
        node->left=NULL;
    }
    if(node->right){
        Free(node->right);
        node->right=NULL;
    }
    free(node);
}

bool DeleteInterval(Node *node,int a,int b){
    if(a>b){
        int tmp=a;a=b;b=tmp;
    }
     Node *ap=InsertSplay(node,a);
     Node *prev=FindPrev(ap);
     Node *bp=InsertSplay(ap,b);
     Node *nxt=FindNext(bp);
     Splay(prev,NULL);
     Splay(nxt,prev);
     Free(nxt->left);
     nxt->left=NULL;
     return true;
}
Node *Search(Node *node,int k){
     Node *ret;
     while(node){
         if(k<node->key){
             node=node->left;
//             if(ret)return ret;
         }else if(k>node->key){
            ret=node;
            node=node->right;
         }else{
             return node;
         }
     }
     return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n;
    scanf("%d",&n);
    Init();
    while(n--){
         char ch;
         cin>>ch;
         int ka,kb;
         while(root->fa)root=root->fa;

         switch(ch){
             case 'I':
                 cin>>ka;
                 InsertSplay(root,ka);
                 break;
             case 'Q':
                 cin>>ka;
                 cout<<Search(root,ka)->key<<endl;
                 break;
             case 'D':
                 cin>>ka>>kb;
                 DeleteInterval(root,ka,kb);
                 break;
             default:
                 break;
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
