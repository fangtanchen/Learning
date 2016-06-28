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
const int MAXN=100010;
const int MAXK=1000000010;

struct Node{
    Node *left,*right,*fa;
    int key,weight;
};

Node *root;

void LeftRotate(Node *a);
void RigthRotate(Node *a);

void Init(){
    root=NULL;
}

Node *Find(Node *node,int k){
    while(node!=NULL){
        if(k<node->key)node=node->left;
        else if(k>node->key)node=node->right;
        else break;
    }
    return node;
}

Node *Insert(Node *node,int k){
    if(k<node->key){
        if(node->left==NULL){
            Node *tmp=new Node();
            tmp->key=k;tmp->weight=rand();
            tmp->left=tmp->right=NULL;
            tmp->fa=node;node->left=tmp;
            return node->left;
        }else{
            return Insert(node->left,k);
        }
    }else if(k>node->key){
        if(node->right==NULL){
            Node *tmp=new Node();
            tmp->key=k;tmp->weight=rand();
            tmp->left=tmp->right=NULL;
            tmp->fa=node;node->right=tmp;
            return node->right;
        }else{
            return Insert(node->right,k);
        }
    }else{
         return node;
    }
}

bool Delete( Node *node,int k){
     Node* a=Find(node, k);
     if(a==NULL)return false;
     while((a->left!=NULL)&&(a->right!=NULL)){
         Node *child=a->left;
         if(child->weight>a->right->weight){
             child=a->right;
         }

         if(child==a->left){
             RigthRotate(a);
         }else{
             LeftRotate(a);
         }
     }

     Node *fa=a->fa;
     if(a->left!=NULL){
          a->left->fa=fa;
          if(fa->left==a){
              fa->left=a->left;
          }
          else {
              fa->right=a->left;
          }
     }else if(a->right!=NULL){
         a->right->fa=fa;
         if(fa->left==a){
              fa->left=a->right;
         }else{
             fa->right=a->right;
         }
     }else{
         if(fa->left==a)fa->left=NULL;
         else fa->right=NULL;
     }
}

void LeftRotate(Node *a){
     Node *b=a->right;
     b->fa=a->fa;
     if(a->fa!=NULL){
         if(a->fa->left==a){
             a->fa->left=b;
         }else{
             a->fa->right=b;
         }
     }
     if(b->left!=NULL){
         b->left->fa=a;
     }
     a->right=b->left;
     b->left=a;a->fa=b;
}

void RigthRotate(Node *a){
     Node *b=a->left;
     b->fa=a->fa;
     if(a->fa!=NULL){
         if(a->fa->left==a)a->fa->left=b;
         else a->fa->right=b;
     }
     if(b->right!=NULL){
         b->right->fa=a;
     }
     a->left=b->right;
     b->right=a;a->fa=b;
}

void Rotate(Node *a){
    while(a->fa!=NULL){
        Node *fa=a->fa;
        if(fa->weight<=a->weight)break;
        if(a==fa->left){
            RigthRotate(fa);
        }else{
            LeftRotate(fa);
        }
    }
}

Node *Search(Node *node,int k){
    Node *ret=NULL;
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


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n;
    scanf("%d",&n);
    Init();
    while(n--){
        int k;
        char c;
        cin>>c>>k;
        switch(c){
            case 'I':
                if(root==NULL){
                     root=new Node();
                     root->left=root->right=root->fa=NULL;
                     root->key=k;root->weight=rand();
                }else{
                    while(root->fa!=NULL)root=root->fa;
                     Rotate(Insert(root,k));
                }
                break;
            case 'Q':
                while(root->fa!=NULL)root=root->fa;
                cout<<Search(root,k)->key<<endl;
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
