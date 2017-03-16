#include<bits/stdc++.h>



#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define lson (rt<<1)
#define rson ((rt<<1)|1)
typedef long long int LL;
const int MAXN=2e5+20;

LL N,M;
LL arr[MAXN];
LL pre[MAXN*2];
LL ans[MAXN];

struct A{
    LL l,r,id;
    bool operator<(const A &b)const{
        return r<b.r;
    }
}itv[MAXN];

struct SegTree{
    LL lazy,prelazy;
    LL sum,presum;
}tr[MAXN<<2];

void PushDown(int rt){
    if(tr[rt].lazy==0 && tr[rt].prelazy==0)return;
    tr[lson].prelazy=max(tr[lson].prelazy,tr[lson].lazy+tr[rt].prelazy);
    tr[lson].presum=max(tr[lson].presum,tr[lson].sum+tr[rt].prelazy);
    tr[lson].lazy+=tr[rt].lazy;
    tr[lson].sum+=tr[rt].lazy;


    tr[rson].prelazy=max(tr[rson].prelazy,tr[rson].lazy+tr[rt].prelazy);
    tr[rson].presum=max(tr[rson].presum,tr[rson].sum+tr[rt].prelazy);
    tr[rson].lazy+=tr[rt].lazy;
    tr[rson].sum+=tr[rt].lazy;
    tr[rt].lazy=tr[rt].prelazy=0;
}

void PushUp(int rt){
     tr[rt].sum=max(tr[lson].sum,tr[rson].sum);
     tr[rt].presum=max(tr[lson].presum,tr[rson].presum);
}


void Update(LL L,LL R,LL add,LL l,LL r,LL rt){
    if(L<=l&&(R>=r)){
        tr[rt].sum+=add;
        tr[rt].lazy+=add;
        tr[rt].presum=max(tr[rt].presum,tr[rt].sum);
        tr[rt].prelazy=max(tr[rt].prelazy,tr[rt].lazy);
        return;
    }
    PushDown(rt);
    LL mid=(l+r)/2;
    if(L<=mid){
         Update(L,R,add,l,mid,lson);
    }
    if(R>mid){
        Update(L,R,add,mid+1,r,rson);
    }
    PushUp(rt);
}

LL Query(LL L,LL R,LL l,LL r,LL rt){
    if(L<=l&&R>=r)return tr[rt].presum;
    PushDown(rt);
    LL ans=0;
    LL mid=(l+r)/2;
    if(L<=mid){
        ans=max(ans,Query(L,R,l,mid,lson));
    }
    if(R>mid){
        ans=max(ans,Query(L,R,mid+1,r,rson));
    }
    return ans;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    for(LL i=1;i<=N;i++){
         cin>>arr[i];
    }
    cin>>M;
    for(LL i=0;i<M;i++){
        cin>>itv[i].l>>itv[i].r;
        itv[i].id=i;
    }
    sort(itv,itv+M);
    LL now=0;
    for(LL i=1;i<=N;i++){
         Update(pre[arr[i]+MAXN]+1,i,arr[i],1,N,1);
         pre[arr[i]+MAXN]=i;
         while(now<M&&(itv[now].r==i)){
             ans[itv[now].id]=Query(itv[now].l,itv[now].r,1,N,1);
             now++;
         }
    }
    for(LL i=0;i<M;i++)printf("%lld%c",ans[i],i==M-1?'\n':' ');


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
