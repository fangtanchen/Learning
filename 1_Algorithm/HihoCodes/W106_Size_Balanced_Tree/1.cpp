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

#define lson ((id<<1))
#define rson ((id<<1)+1)

const int MAXN=2e5+10;

struct Node{
    Node *right,*left;
    int key;
    int num;
    Node(int _key){
        key=_key;
        left=right=NULL;
        num=1;
    }
};

Node *root;

int Sz(Node *rt){
    if(rt==NULL)return 0;
    else return rt->num;
}

void LeftRotate(Node *&rt){
    Node *p1=rt->right;
    rt->right=p1->left;
    //rt->num=Sz(rt->left)+Sz(rt->right)+1;
    p1->left=rt;
    p1->num=rt->num;
    rt->num=Sz(rt->left)+Sz(rt->right)+1;
    rt=p1;
    //rt->num=Sz(rt->left)+Sz(rt->right)+1;
}

void RightRotate(Node *&rt){
    Node *k=rt->left;
    rt->left=k->right;
    k->right=rt;
    k->num=rt->num;
    rt->num=Sz(rt->left)+Sz(rt->right)+1;
    rt=k;
    //rt->num=Sz(rt->left)+Sz(rt->right)+1;
}


void Maintain(Node *&rt,bool flag){
    if(rt==NULL)return;
    if(flag){
        if(Sz(rt->right->right)>Sz(rt->left)){
            LeftRotate(rt);
        }else if(Sz(rt->right->left) > Sz(rt->left)){
            RightRotate(rt->right);
            LeftRotate(rt);
        }else return;
    }else{
        if(Sz(rt->left->left)>Sz(rt->right)){
            RightRotate(rt);
        }else if(Sz(rt->left->right) > Sz(rt->right)){
            LeftRotate(rt->left);
            RightRotate(rt);
        }else{
            return;
        }
    }
/*    Maintain(rt->left,false);
    Maintain(rt->right,true);
    Maintain(rt,false);
    Maintain(rt,true);
    */
}

Node *Insert(Node *&rt,int key){
    if(rt==NULL){
        rt=new Node(key);
    }else{
        rt->num++;
        if(rt->key<=key){
            Insert(rt->right,key);
        }else{
            Insert(rt->left,key);
        }
        Maintain(rt,key>=rt->key);
    }
    return rt;
}

int Query(Node *rt,int k){
    int num=Sz(rt->left);
    if(num+1==k)return rt->key;
    if(k<=num){
        return Query(rt->left,k);
    }else {
        return Query(rt->right,k-num-1);
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n;
    cin.sync_with_stdio(false);
    cin>>n;
    root=NULL;
    for(int ni=0;ni<n;ni++){
        char op;
        int k;
        cin>>op>>k;
        switch(op){
            case 'I':
                Insert(root,k);
                break;
            case 'Q':
                printf("%d\n",Query(root,k));
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
