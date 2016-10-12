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
typedef unsigned long long int ll;
const int MAXN=200010;
const int MAXID=100000010;
const int MINID=-10000000;
const int MAXVAL=10000010;

struct Node{
    int val,id,num;
    ll totalval,lazy;
    Node *left,*right,*fa;
    Node(int i,int v){
        id=i;
        val=v;
        num=1;
        totalval=v;
        lazy=0;
        left=right=fa=NULL;
    }
}*root=NULL;

void Update(Node *x){
    x->num=1;
    x->totalval=x->val;
    if(x->left){
        x->num+=x->left->num;
        x->totalval+=x->left->totalval;
    }
    if(x->right){
        x->num+=x->right->num;
        x->totalval+=x->right->totalval;
    }
}

void Mark(Node *a,long long int lazy){
    a->lazy+=lazy;
    a->totalval+=a->num*lazy;
    a->val+=lazy;
}

void Send(Node *a){
    if(!a->lazy)return;
    if(a->left){
        Mark(a->left,a->lazy);
    }
    if(a->right){
        Mark(a->right,a->lazy);
    }
    a->lazy=0;
    Update(a);
}

void LeftRotate(Node *a){
     Node *b=a->fa;
     Send(b);
     Send(a);
     a->fa=b->fa;
     if(b->fa){
          if(b->fa->left==b)b->fa->left=a;
          else b->fa->right=a;
     }else{
         root=a;
     }
     b->right=a->left;
     if(a->left)a->left->fa=b;
     a->left=b;b->fa=a;

     Update(b);
     Update(a);
}

void RightRotate(Node *a){
    Node *b=a->fa;
    Send(b);
    Send(a);
    a->fa=b->fa;
    if(b->fa){
        if(b->fa->left==b)b->fa->left=a;
        else b->fa->right=a;
    }else{
         root=a;
    }
    b->left=a->right;
    if(a->right)a->right->fa=b;
    a->right=b;b->fa=a;
    Update(b);
    Update(a);
}

void Splay(Node *x, Node *y){
    while(x->fa!=y){
        Node *fx=x->fa;
        if(fx->fa==y){
            if(x==fx->left){
                RightRotate(x);
            }else{
                 LeftRotate(x);
            }
        }else{
             Node *b=fx->fa;
             if(b->left==fx){
                 if(fx->left==x){
                     RightRotate(fx);
                     RightRotate(x);
                 }
                 else{
                     LeftRotate(x) ;
                     RightRotate(x);
                 }
             }else{
                 if(fx->right==x){
                     LeftRotate(fx) ;
                     LeftRotate(x);
                 }
                 else{
                     RightRotate(x);
                     LeftRotate(x);
                 }
             }
        }
    }
}

Node *Insert(Node *node,int id,int val){
    Send(node);
    Node *ret=NULL;
    if(id<node->id){
        if(node->left==NULL){
            ret=new Node(id,val);
            node->left=ret;
            ret->fa=node;
        }else{
             ret=Insert(node->left,id,val);
        }
    }else if(id>node->id){
        if(node->right==NULL){
            node->right=new Node(id,val);
            node->right->fa=node;
            ret=node->right;
        }else{
             ret=Insert(node->right,id,val);
        }
    }else{
        ret=node;
    }
    Update(node);
    return ret;
}


Node *Find(Node *node,int id){
    while(node){
        if(id<node->id){
            node=node->left;
        }else if(id>node->id){
            node=node->right;
        }else{
            return node;
        }
    }
    return NULL;
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

void Free(Node *a){
    if(a->left){
        Free(a->left);
        a->left=NULL;
    }
    if(a->right){
        Free(a->right);
        a->right=NULL;
    }
    free(a);
}

bool Delete(Node *node,int a,int b){
    bool erase_a=false,erase_b=false;
    Node *na=Find(node,a),*nb=Find(node,b);
    while(node->fa)node=node->fa;
    if(!(na)){
         erase_a=true;
         na=Insert(node,a,0);
    }
    while(node->fa)node=node->fa;
    if(!(nb)){
        erase_b=true;
        nb=Insert(node,b,0);
    }
    Node *prev=FindPrev(na);
    Node *nxt=FindNext(nb);
    Splay(prev,NULL);
    Splay(nxt,prev);
    Free(nxt->left);
    nxt->left=NULL;
    Update(nxt);
    Update(prev);
    return true;
}

ll Search(Node *node,int a,int b){
    bool erase_a=false,erase_b=false;
    Node *na=Find(node,a),*nb=Find(node,b);
    while(node->fa)node=node->fa;
    if(!(na)){
         erase_a=true;
         na=Insert(node,a,0);
    }
    while(node->fa)node=node->fa;
    if(!(nb)){
        erase_b=true;
        nb=Insert(node,b,0);
    }
    Node *prev=FindPrev(na);
    Node *nxt=FindNext(nb);
    Splay(prev,NULL);
    Splay(nxt,prev);
    unsigned long long ret=nxt->left->totalval;
    if(erase_a){
         Delete(node,a,a);
    }
    if(erase_b){
        Delete(node,b,b);
    }
    return ret;
}

bool Modify(Node *node,int a,int b,int val){
    bool erase_a=false,erase_b=false;
    Node *na=Find(node,a),*nb=Find(node,b);
    while(node->fa)node=node->fa;
    if(!(na)){
         erase_a=true;
         na=Insert(node,a,0);
    }
    while(node->fa)node=node->fa;
    if(!(nb)){
        erase_b=true;
        nb=Insert(node,b,0);
    }
    Node *prev=FindPrev(na);
    Node *nxt=FindNext(nb);
    Splay(prev,NULL);
    Splay(nxt,prev);
    Mark(nxt->left,val);
    Update(nxt);
    Update(prev);
    if(erase_a){
         Delete(node,a,a);
    }
    if(erase_b){
        Delete(node,b,b);
    }
    return true;
}
void Init(){
     root=new Node(MINID,0);
     Insert(root,MAXID,0);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n;
    Init();
    cin.sync_with_stdio(0);
    cin>>n;
    while(n--){
        char ch;
        int a,b,c;
        cin>>ch;
        while(root->fa)root=root->fa;
        switch(ch){
            case 'I':
                cin>>a>>b;
                Insert(root,a,b);
                break;
            case 'Q':
                cin>>a>>b;
                if(a>b)swap(a,b);
                cout<<Search(root,a,b)<<endl;
                break;
            case 'M':
                cin>>a>>b>>c;
                if(a>b)swap(a,b);
                Modify(root,a,b,c);
                break;
            case 'D':
                cin>>a>>b;
                if(a>b)swap(a,b);
                Delete(root,a,b);
                break;
            default:
                break;
        }
    }
    cout<<flush;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
