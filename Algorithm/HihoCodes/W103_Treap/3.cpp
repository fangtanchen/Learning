#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cstdlib>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int  MAXN=100010;
const int  MAXK=1000000010;

struct Node{
    int key,weight;
    Node *left,*right,*fa;

    Node(int k){
         left=right=fa=NULL;
         key=k;
         weight=rand();
    }
};

Node *root;

void Init(){
     root=NULL;
}

Node *Insert(Node *node, int k){
    if(k<node->key){
        if(node->left==NULL){
            node->left=new Node(k);
            node->left->fa=node;
            return node->left;
        }else{
            return Insert(node->left,k);
        }
    }else if(k>node->key){
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

Node *Find(Node *node,int k){
    while(node){
        if(k<node->key){
            node=node->left;
        }else if(k>node->key){
            node=node->right;
        }else{
            return node;
        }

    }
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
     a->fa=b;
     b->left=a;
}

void RightRotate(Node *a){
    Node *b=a->left;
    b->fa=a->fa;
    if(a->fa){
         if(a==a->fa->left)a->fa->left=b;
         else a->fa->right=b;
    }
    a->left=b->right;
    if(b->right){
        b->right->fa=a;
    }
    a->fa=b;
    b->right=a;
}

void Rotate(Node *node){
    while(node->fa){
        Node *fa=node->fa;
        if(node->weight<fa->weight){
            if(node==fa->left){
                RightRotate(fa);
            }else{
                LeftRotate(fa);
            }
        }else{
            break;
        }
    }
}

Node *Search(Node *node,int k){
    Node *ret;
    while(node){
        if(k<node->key){
            node=node->left;
        }else if(k>node->key){
            ret=node;
            node=node->right;
        }else{
             return node;
        }
    }
    return ret;
}

bool Delete(Node *node,int k){
     Node *x=Find(node,k);
     if(x==NULL)return false;
     while((x->left!=NULL)&&(x->right!=NULL)){
         Node *child=x->left;
         if(child->weight>x->right->weight){
              child=x->right;
         }
         if(child==x->left){
             RightRotate(x);
         }else{
              LeftRotate(x);
         }
     }
     Node *fa=x->fa;
     if(x->left!=NULL){
          x->left->fa=fa;
          if(x==fa->left){
              fa->left=x->left;
          }else{
              fa->right=x->left;
          }
     }else if(NULL!=x->right){
          x->right->fa=fa;
          if(x==fa->right){
              fa->right=x->right;
          }else{
              fa->left=x->right;
          }
     }else{
         if(x==fa->left){
             fa->left=NULL;
         }else{
             fa->right=NULL;
         }
     }
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
        char c;
        int k;
        cin>>c>>k;
        switch(c){
            case 'I':
                if(NULL==root){
                    root=new Node(k);
                }else{
                    while(root->fa){
                        root=root->fa;
                    }
                    Rotate(Insert(root,k));
                }
                break;
            case 'Q':
                while(root->fa)root=root->fa;
                printf("%d\n",Search(root,k)->key);
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
