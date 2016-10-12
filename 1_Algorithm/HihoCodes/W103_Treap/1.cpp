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
const int MAXN=100010;fda
const int MAXK=1000000010;

struct Node{
    Node *left,*right;
    Node *fa;
    int key,weight;
};

Node *root;


Node *Insert(Node *node,int key){
    if(key<node.key){
        if(node->left==NULL){
            Node *tmp=new Node();
            tmp->left=tmp->right=NULL;
            tmp->fa=node;
            tmp->key=key;
            tmp->weight=rand();
            node->left=tmp;
            return node->left;
        }else   {
            Insert(node->left,key);
        }
    }else{
        if(node->right==NULL){
            Node *tmp=new Node();
            tmp->left=tmp->right=NULL;
            tmp->fa=node;
            tmp->key=key;
            tmp->weight=rand();
            node->right=tmp;
            return node->right;
        }else{
            return Insert(node->right,key);
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
    root=NULL;
    while(n--){
        int k;
        char c;
        cin>>c>>k;
        Node *tmp;
        switch(c){
            case 'I':
                if(root==NULL){
                     root=new Node();
                     root->left=root->right=root->fa=NULL;
                     root->key=k;
                     root->weight=rand();
                }else{
                    Rotate(Insert(root,k))
                }
                break;
            case 'Q':
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
