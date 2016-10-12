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
const int MAXN=2e5+20;
const int MAXID=1e8+100;
const int MINID=-1e8-100;

typedef unsigned long long ull;

struct Node{
    int id,val,num;
    ull lazy,total;
    Node *left,*right,*father;
    Node(int i=0,int v=0){
         id=i;
         val=v;
         num=1;
         total=val;
         lazy=0;
         left=right=father=NULL;
    }
}*root=NULL;

void Mark(Node *x,ull lazy){
    x->lazy+=lazy;
    x->val+=lazy;
    x->total+=(x->num*lazy);
}

void Update(Node *x){
    x->total=x->val;
    x->num=1;
    if(x->left){
        x->num+=x->left->num;
        x->total+=x->left->total;
    }
    if(x->right){
        x->num+=x->right->num;
        x->total+=x->right->total;
    }
}

void Send(Node *x){
    if(!x->lazy)return ;
    if(x->left){
        Mark(x->left,x->lazy);
    }
    if(x->right){
        Mark(x->right,x->lazy);
    }
    x->lazy=0;
    Update(x);
}

void UpdateChild(Node *p, Node *x){
    if(p->father->left==p)p->father->left=x;
    else p->father->right=x;

}

void LeftRotate(Node *x){
    Node *p=x->father;
    Send(p);
    Send(x);
    x->father=p->father;
    if(p->father){
        UpdateChild(p,x);
    }
    p->right=x->left;
    if(x->left)x->left->father=p;
    p->father=x;
    x->left=p;
    Update(p);
    Update(x);
}

void RightRotate(Node *x){
     Node *p=x->father;
     Send(p);
     Send(x);
     x->father=p->father;
     if(p->father){
         UpdateChild(p,x);
     }
     p->left=x->right;
     if(x->right)x->right->father=p;
     p->father=x;
     x->right=p;
     Update(p);
     Update(x);
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
            if(b->left==fx){
                if(fx->left==x){
                    RightRotate(fx);
                    RightRotate(x);
                }else{
                    LeftRotate(x);
                    RightRotate(x);
                }
            }else{
                if(fx->right==x){
                    LeftRotate(fx);
                    LeftRotate(x);
                }else{
                    RightRotate(x);
                    LeftRotate(x);
                }
            }
        }
    }
}

Node *BSTInsert(Node *x,int id,int val){
    Send(x);
    Node *ret=NULL;
    if(id==x->id){
        ret=x;
    }else if(id<x->id){
        if(!x->left){
            ret=new Node(id,val);
            ret->father=x;
            x->left=ret;
        }else{
             ret=BSTInsert(x->left,id,val);
        }
    }else{
        if(!x->right){
            ret=new Node(id,val);
            ret->father=x;
            x->right=ret;
        }else{
            ret=BSTInsert(x->right,id,val) ;
        }
    }
    Update(x);
    return ret;
}

Node *Insert(int id,int val){
     while(root->father)root=root->father;
     Node *tmp=BSTInsert(root,id,val);
     Splay(tmp,NULL);
     root=tmp;
     return tmp;
}

Node *Find(int a){
    while(root->father)root=root->father;
    Node *tmp=root;
    while(tmp){
        if(a<tmp->id){
            tmp=tmp->left;
        }else if(a>tmp->id){
            tmp=tmp->right;
        }else{
            return tmp;
        }
    }
    return NULL;
}

Node *FindPrev(Node *x){
    Splay(x,NULL);
    Node *tmp=x->left;
    while(tmp->right){
         tmp=tmp->right;
    }
    return tmp;
}

Node *FindNext(Node *x){
    Splay(x,NULL);
    Node *tmp=x->right;
    while(tmp->left){
         tmp=tmp->left;
    }
    return tmp;
}

void Free(Node *x){
    if(x->left){
        Free(x->left);
        x->left=NULL;
    }
    if(x->right){
        Free(x->right);
        x->right=NULL;
    }
    delete x;
}

bool Delete(int a,int b){
    bool erase_a=false,erase_b=false;
    Node *na=Find(a);
    Node *nb=Find(b);
    if(!na){
        erase_a=true;
        na=Insert(a,0);
    }
    if(!nb){
        erase_b=true;
        nb=Insert(b,0);
    }
    Node *pre=FindPrev(na);
    Node *nxt=FindNext(nb);
    Splay(pre,NULL);
    Splay(nxt,pre);
    Free(nxt->left);
    nxt->left=NULL;
    Update(nxt);
    Update(pre);
}

bool Modify(int a,int b,ull lazy){
    bool erase_a=false,erase_b=false;
    Node *na=Find(a);
    Node *nb=Find(b);
    if(!na){
        erase_a=true;
        na=Insert(a,0);
    }
    if(!nb){
        erase_b=true;
        nb=Insert(b,0);
    }
    Node *pre=FindPrev(na);
    Node *nxt=FindNext(nb);
    if(erase_a)Delete(a,a);
    if(erase_b)Delete(b,b);
    Splay(pre,NULL);
    Splay(nxt,pre);
    Mark(nxt->left,lazy);
    Update(nxt);
    Update(pre);
    return true;
}

ull Query(int a,int b){
    bool erase_a=false,erase_b=false;
    Node *na=Find(a);
    Node *nb=Find(b);
    if(!na){
        erase_a=true;
        na=Insert(a,0);
    }
    if(!nb){
        erase_b=true;
        nb=Insert(b,0);
    }
    Node *pre=FindPrev(na);
    Node *nxt=FindNext(nb);
    if(erase_a)Delete(a,a);
    if(erase_b)Delete(b,b);
    Splay(pre,NULL);
    Splay(nxt,pre);
    Update(nxt);
    Update(pre);
    return nxt->left->total;
}

void Init(){
     root=new Node(MINID,0);
     Insert(MAXID,0);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    int n,a,b,d;
    char op;
    cin>>n;
    Init();
    for(int i=0;i<n;i++){
         cin>>op;
         switch(op){
             case 'I':
                 cin>>a>>b;
                 Insert(a,b);
                 break;
             case 'M':
                 cin>>a>>b>>d;
                 Modify(a,b,d);
                 break;
             case 'D':
                 cin>>a>>b;
                 Delete(a,b);
                 break;
             case 'Q':
                 cin>>a>>b;
                 cout<<Query(a,b)<<endl;
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
