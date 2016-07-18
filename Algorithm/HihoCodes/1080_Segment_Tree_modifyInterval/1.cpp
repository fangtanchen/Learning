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
#define lson (id<<1)
#define rson ((id<<1)|1)

struct Node{
    int l,r,val;
    int num,dirty;
    Node(){
        l=r=val=dirty=0;
        num=1;
    }
}nodes[3*MAXN];

int N,M;
int a[MAXN];

void Update(int id){
    nodes[id].val=nodes[lson].val+nodes[rson].val;
}

void Build(int l,int r,int id){
    nodes[id].l=l;
    nodes[id].r=r;
    if((l==r)){
         nodes[id].val=a[l];
         return ;
    }
    int mid=(l+r)/2;
    Build(l,mid,lson);
    Build(mid+1,r,rson);
    Update(id);
    nodes[id].num=nodes[lson].num+nodes[rson].num;
    return;
}

void Send(int id){
    if(nodes[id].dirty){
        nodes[lson].dirty=nodes[rson].dirty
            =nodes[id].dirty;
        nodes[id].dirty=0;
        nodes[lson].val=nodes[lson].num*nodes[lson].dirty;
        nodes[rson].val=nodes[rson].num*nodes[rson].dirty;
    }
}

void Modify(int l,int r,int dirty,int id){
    if((l==nodes[id].l)&&(r==nodes[id].r)){
        nodes[id].dirty=dirty;
        nodes[id].val=nodes[id].num*nodes[id].dirty;
        return;
    }
    Send(id);
    int mid=(nodes[id].l+nodes[id].r)/2;
    if(r<=mid)Modify(l,r,dirty,lson);
    else if(l>mid)Modify(l,r,dirty,rson);
    else{
        Modify(l,mid,dirty,lson);
        Modify(mid+1,r,dirty,rson);
    }
    Update(id);
}

int Query(int l, int r,int id){
    if((l==nodes[id].l)&&(r==nodes[id].r)){
        return nodes[id].val;
    }
    int mid=(nodes[id].l+nodes[id].r)/2;
    Send(id);
    if(r<=mid)return Query(l,r,lson);
    else if(l>mid)return Query(l,r,rson);
    else return Query(l,mid,lson)+Query(mid+1,r,rson);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
         scanf("%d",a+i);
    }
    Build(1,N,1);
    scanf("%d",&M);
    while(M--){
         int op,a,b,c;
         scanf("%d",&op);
         if(op){
             scanf("%d%d%d",&a,&b,&c);
             Modify(a,b,c,1);
         }else{
             scanf("%d%d",&a,&b);
             printf("%d\n",Query(a,b,1)) ;
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
