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
#define MAXN 1000010
#define lson (i<<1)
#define rson (i<<1|1)

struct node{
     int l,r;
     int s;
}tree[MAXN*3];
int a[MAXN];


void update(int i){
    tree[i].s=min(tree[lson].s,tree[rson].s);
}

void build(int l,int r,int i){
    tree[i].l=l;
    tree[i].r=r;
    if(l==r){
        tree[i].s=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,lson);
    build(mid+1,r,rson);
    update(i);
}

void change(int l,int r,int i,int num){
    if(l==tree[i].l&&(r==tree[i].r)){
        tree[i].s=num;
        return;
    }
    int mid=(tree[i].l+tree[i].r)/2;
    if(r<=mid)change(l,r,lson,num);
    else if(l>mid) change(l,r,rson,num);
    update(i);
}

int query(int l,int r,int i){
    if(l==tree[i].l&&(r==tree[i].r)){
        return tree[i].s;
    }
    int mid=(tree[i].l+tree[i].r)/2;
    if(r<=mid)return query(l,r,lson);
    else if(l>mid)return query(l,r,rson);
    else return min(query(l,mid,lson),query(mid+1,r,rson));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int N,Q;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
         scanf("%d",a+i);
    }
    int flag,f,t;
    build(1,N,1);
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d%d",&flag,&f,&t);
        if(flag)change(f,f,1,t);
        else printf("%d\n",query(f,t,1));
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
