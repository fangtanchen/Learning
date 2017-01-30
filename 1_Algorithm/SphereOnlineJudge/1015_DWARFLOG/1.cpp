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
const int MAXN=2e5+10;
#define lson ((id)<<1)
#define rson ((id<<1)|1)

struct Node{
    int l,r;
    int minv,maxv;
    Node(){
        l=r=minv=maxv=-1;
    }
}tree[MAXN*4];

int a[MAXN];
int N,M;

void BuildTree(int id,int l,int r){
    if(l==r){
        tree[id].minv=tree[id].maxv=l;
        tree[id].l=tree[id].r=l;
        return;
    }
    int mid=(l+r)>>1;
    BuildTree(lson,l,mid);
    BuildTree(rson,mid+1,r);
    tree[id].l=l;tree[id].r=r;
    tree[id].minv=min(tree[lson].minv,tree[rson].minv);
    tree[id].maxv=max(tree[lson].maxv,tree[rson].maxv);
}

void Modify(int id,int v){
    if(tree[id].l==v&&(tree[id].r==v)){
        tree[id].minv=tree[id].maxv=a[v];
        return;
    }
    int mid=(tree[id].l+tree[id].r)>>1;
    if(v<=mid){
        Modify(lson,v);
    }else{
        Modify(rson,v);
    }
    tree[id].minv=min(tree[lson].minv,tree[rson].minv);
    tree[id].maxv=max(tree[lson].maxv,tree[rson].maxv);
}
int FindMin(int id,int l,int r){
    if(tree[id].r==r&&(tree[id].l==l)){
        return tree[id].minv;
    }
    int mid=(tree[id].l+tree[id].r)>>1;
    if(mid<l){
        return FindMin(rson,l,r);
    }
    if(r<=mid){
        return FindMin(lson,l,r);
    }
    return min(FindMin(lson,l,mid),FindMin(rson,mid+1,r));
}

int FindMax(int id,int l,int r){
    if(tree[id].r==r&&(tree[id].l==l)){
        return tree[id].maxv;
    }
    int mid=(tree[id].l+tree[id].r)>>1;
    if(mid<l){
        return FindMax(rson,l,r);
    }
    if(r<=mid){
        return FindMax(lson,l,r);
    }
    return max(FindMax(lson,l,mid),FindMax(rson,mid+1,r));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        a[i]=i;
    BuildTree(1,1,N);
    for(int mi=0;mi<M;mi++){
         int op,A,B;
         scanf("%d%d%d",&op,&A,&B);
         if(op==1){
              swap(a[A],a[B]);
              Modify(1,A);
              Modify(1,B);
         }else{
              int minv=FindMin(1,A,B);
              int maxv=FindMax(1,A,B);
              if(maxv-minv==abs(A-B))printf("YES\n");
              else printf("NO\n");
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
