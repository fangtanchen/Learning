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

void Init(){
    root=NULL;
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

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n;
    scanf("%d",&n);
    while(n--){
         char ch;
         cin>>ch;
         switch(ch){
             case 'I':
                 break;
             case 'Q':
                 break;
             case 'D':
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
