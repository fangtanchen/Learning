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
const int MAXN=200010;
const int MAXK=1000000010;
const int MINK=-100;

struct Node{
    int key;
    Node *left,*right,*father;
    Node(int k){
        key=k;
        left=right=father=NULL;
    }
}*root;

void LeftRotate(Node *a){
    Node *b=a->father;
    a->father=b->father;
    if(b->father){
        if(b==b->father->left)b->father->left=a;
        else b->father->right=a;
    }
    b->right=a->left;
    if(a->left){
        a->left->father=b;
    }
    a->left=b;b->father=a;
}

void RightRotate(Node *a){
     Node *b=a->father;
     a->father=b->father;
     if(b->father){
         if(b->father->left==b)b->father->left=a;
         else b->father->right=a;
     }
     b->left=a->right;
     if(a->right){
          a->right->father=b;
     }
     b->father=a;a->right=b;
}

void Splay(Node *x, Node *y){
    while(x->father!=y){
        Node *fx=x->father;
        if(fx->father==y){
            if(x==fx->left){
                RightRotate(x);
            }else{
                LeftRotate(x);
            }
        }else{
            Node *b=fx->father;
            if(fx->left==x){
                if(b->left==fx){
                    RightRotate(fx);
                    RightRotate(x);
                }else{
                    RightRotate(x);
                    LeftRotate(x);
                }
            }else{
                if(b->right==fx){
                    LeftRotate(fx);
                    LeftRotate(x);
                }else{
                    LeftRotate(x);
                    RightRotate(x);
                }
            }
        }
    }
}

Node *Insert(Node *node,int k){
    if(k<node->key){
        if(node->left==NULL){
            node->left=new Node(k);
            node->left->father=node;
            return node->left;
        }else{
            return Insert(node->left,k);
        }
    }else if(k>node->key){
        if(node->right==NULL){
             node->right=new Node(k);
             node->right->father=node;
             return node->right;
        }else{
            return Insert(node->right,k);
        }
    }else{
         return node;
    }
}

Node *InsertSplay(Node *node,int k){
     Node *b=Insert(node,k);
     Splay(b,NULL);
     return b;
}

Node *Find(Node *node, int k){
    Node *tmp=node;
    while(tmp){
        if(k<tmp->key){
            tmp=tmp->left;
        }else if(k>tmp->key){
             tmp=tmp->right;
        }else{
            return tmp;
        }
    }
    return NULL;
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

Node *FindPrev(Node *a){
    Splay(a,NULL);
    Node *tmp=a->left;
    while(tmp->right){
        tmp=tmp->right;
    }
    return tmp;
}

Node *FindNext(Node *a){
     Splay(a,NULL);
     Node *tmp=a->right;
     while(tmp->left){
         tmp=tmp->left;
     }
     return tmp;
}

bool Delete(Node *node, int a,int b){
     Node *na=Insert(node,a);
     Node *nb=Insert(node,b);
     Node *pre=FindPrev(na);
     Node *nxt=FindNext(nb);
     Splay(pre,NULL);
     Splay(nxt,pre);
     Free(nxt->left);
     nxt->left=NULL;
     return true;
}

Node *Search(Node *root,int k){
    Node *ret=NULL;
    while(root){
        if(k<root->key){
            root=root->left;
        }else if(k>root->key){
            ret=root;
            root=root->right;
        }else{
            return root;
        }
    }
    return ret;
}

void Init(){
    root=new Node(MINK);
    InsertSplay(root,MAXK);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n,k;
    scanf("%d",&n);
    Init();
    char ch;
    while(n--){
        cin>>ch;
        switch(ch){
            case 'I':
                cin>>k;
                while(root->father)root=root->father;
                InsertSplay(root,k);
                break;
            case 'Q':
                cin>>k;
                while(root->father)root=root->father;
                cout<<Search(root,k)->key<<endl;
                break;
            case 'D':
                int a,b;
                cin>>a>>b;
                if(a>b){swap(a,b);}
                while(root->father)root=root->father;
                Delete(root,a,b);
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
