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
const int MAXN=1e5+10;
#define lson (id<<1)
#define rson ((id<<1)|1)

struct Node{
    int l,r;
    int num,total;
    int lazy_set;
    int lazy_add;

    Node(){
        lazy_set=-1;
         l=r=num=total=lazy_add=0;
    }
}tree[3*MAXN];

int N,M;
int val[MAXN];

void Update(int id){
    tree[id].num=tree[lson].num+tree[rson].num;
    tree[id].total=tree[lson].total+tree[rson].total;
}

void Build(int l,int r,int id){
    tree[id].l=l;tree[id].r=r;
    if(l==r){
        tree[id].num=1;
        tree[id].total=val[l];
        return;
    }
    int mid=(l+r)/2;
    Build(l,mid,lson);
    Build(mid+1,r,rson);
    Update(id);
}

void Send(int id){
    if(tree[id].l!=tree[id].r){
        int mid=(tree[id].l+tree[id].r)/2;
        if(tree[id].lazy_set!=-1){
            tree[lson].lazy_set=tree[rson].lazy_set=tree[id].lazy_set;
            tree[lson].total=tree[lson].num*tree[lson].lazy_set;
            tree[rson].total=tree[rson].num*tree[rson].lazy_set;
            tree[lson].lazy_add=tree[rson].lazy_add=0;
            tree[id].lazy_set=-1;
        }
        if(tree[id].lazy_add!=0){
            tree[lson].lazy_add+=tree[id].lazy_add;
            tree[rson].lazy_add+=tree[id].lazy_add;
            tree[lson].total+=tree[lson].num*tree[id].lazy_add;
            tree[rson].total+=tree[rson].num*tree[id].lazy_add;
            tree[id].lazy_add=0;
        }
    }
}

void ModifySet(int l,int r,int lazy,int id){
    Send(id);
    if((tree[id].l==l)&&(tree[id].r==r)){
        tree[id].lazy_set=lazy;
        tree[id].lazy_add=0;
        tree[id].total=tree[id].num*lazy;
        return;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid)ModifySet(l,r,lazy,lson);
    else if(mid<l)ModifySet(l,r,lazy,rson);
    else{
         ModifySet(l,mid,lazy,lson);
         ModifySet(mid+1,r,lazy,rson);
    }
    Update(id);
}

void ModifyAdd(int l,int r,int lazy,int id){
    Send(id);
    if((tree[id].l==l)&&(tree[id].r==r)){
        tree[id].lazy_add+=lazy;
        tree[id].total+=tree[id].num*lazy;
        return;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid)ModifyAdd(l,r,lazy,lson);
    else if(mid<l)ModifyAdd(l,r,lazy,rson);
    else{
         ModifyAdd(l,mid,lazy,lson);
         ModifyAdd(mid+1,r,lazy,rson);
    }
    Update(id);
}

int Query(int l,int r,int id){
    if((tree[id].l==l)&&(tree[id].r==r)){
        return tree[id].total;
    }
    Send(id);
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid)return Query(l,r,lson);
    else if(mid<l)return Query(l,r,rson);
    else return Query(l,mid,lson)+Query(mid+1,r,rson);
}
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<=N;i++){
        cin>>val[i];
    }
    Build(0,N,1);
    for(int i=0;i<M;i++){
         int op,a,b,v;
         cin>>op>>a>>b>>v;
         switch(op){
             case 0:
                 ModifyAdd(a,b,v,1);
                 break;
             case 1:
                 ModifySet(a,b,v,1);
                 break;
             default:
                 break;
         }
         cout<<tree[1].total<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
