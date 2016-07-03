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
const int MAXN=100010;
const int MAXK=1000000010;
const int MINK=-1000000010;

struct Node{
    Node *left,*right,*father;
    int key,weight;
    Node(int k){
        key=k;
        weight=rand();
        left=right=father=NULL;
    }
}*root;

void LeftRotate(Node *a){
    Node *b=a->father;
    a->father=b->father;
    if(b->father){
        if(b->father->left==b)b->father->left=a;
        else b->father->right=a;
    }
    b->right=a->left;
    if(a->left)a->left->father=b;
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
    if(a->right)a->right->father=b;
    a->right=b;b->father=a;
}

void Rotate(Node *a){
    while(a->father){
        Node *pa=a->father;
        if(pa->weight<=a->weight)break;
        if(pa->left==a){
            RightRotate(a);
        }else{
             LeftRotate(a);
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
Node *Find(Node *root, int k){
     Node *tmp=root;
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

bool Delete(Node *node,int k){
    Node *a=Find(node,k) ;
    if(!a)return false;
    while(a->left && a->right){
        Node *child=a->left;
        if(child->weight>a->right->weight){
             child=a->right;
        }
        if(child==a->left){
            RightRotate(child);
        }else{
            LeftRotate(child);
        }
    }
    Node *fa=a->father;
    if(a->left){
        a->left->father=fa;
        if(fa->left==a){
            fa->left=a->left;
        }else{
            fa->right=a->left;
        }
    }else if(a->right){
        a->right->father=fa;
        if(fa->left==a){
            fa->left=a->right;
        }else{
             fa->right=a->right;
        }
    }else{
        if(a==fa->left){
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
    cin>>n;
    root=NULL;
    while(n--){
         char ch;
         int k;
         cin>>ch>>k;
         switch(ch){
             case 'I':
                 if(root==NULL)root=new Node(k);
                 else{
                     while(root->father)root=root->father;
                     Insert(root,k);
                 }
                 break;
             case 'Q':
                 while(root->father)root=root->father;
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
