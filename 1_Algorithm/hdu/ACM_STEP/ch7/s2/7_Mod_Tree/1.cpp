#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef long long int ll;
const ll MAXN=1e6;
struct Node{
    ll idx;
    ll val;
}nodes[MAXN];

ll K,P,N,D;

ll cnt_nodes;



ll gcd(ll x,ll y){
    if(0==y)return x;
    else return gcd(y,x%y);
}

ll cmp(Node x,Node y){
    if(x.val<y.val)return 1;
    else if((x.val==y.val)&&(x.idx<y.idx))return 1;
    return -1;
}

ll exgcd(ll A,ll B,ll &x,ll &y){
    if(B==1){
        x=0;y=1;
        return 0;
    }
    ll tx,ty;
    exgcd(B,A%B,tx,ty);
    x=ty;
    y=tx-A/B*ty;
    return 0;
}

ll inval(ll A,ll B,ll C){
    ll x,y;
    exgcd(A,B,x,y);
    x=x*C%B;
    if(x<0)x+=B;
    return x;
}

ll BinarySearch(ll x){
    ll l=0,r=cnt_nodes-1;
    while(l<=r){
         ll mid=(l+r)>>1;
         if(nodes[mid].val==x)return mid;
         if(nodes[mid].val<x){
             l=mid+1;
         }else{
            r=mid-1;
         }
    }
    return -1;
}

ll ModExp(ll a,ll b,ll c){
    ll ret=1%c;
    a=a%c;
    while(b){
        if(b&0x1)ret=ret*a%c;
        b>>=1;
        a=a*a%c;
    }
    return ret;
}

ll BabyStep(ll K,ll P,ll N){
    ll tmp=1%P;
    for(ll i=0;i<100;i++){
        if(tmp==N)return i;
        tmp=tmp*K%P;
    }
    ll A=K,B=P,C=N;
    ll D=1%B;
    ll c=0;
    ll g;
    while((g=gcd(N,K))!=1){
        if(C%g)return -1;
        c++;
        C/=g;
        B/=g;
        D=D*A/g%B;
    }
    ll m=ceil(sqrt(B));
    tmp=1%B;
    for(ll i=0;i<=m;i++){
        nodes[i].idx=i;
        nodes[i].val=tmp;
        tmp=tmp*A%B;
    }
    sort(nodes,nodes+m+1,cmp);
    cnt_nodes=1;
    for(ll i=1;i<=m;i++){
        if(nodes[i].val!=nodes[cnt_nodes-1].val ){
            nodes[cnt_nodes++]=nodes[i];
        }
    }
    ll AM=ModExp(A,m,B);
    tmp=D%B;
    for(ll i=0;i<=m;i++){
        ll ans=inval(tmp,B,C);
        if(ans<0)continue;
        ll pos=BinarySearch(ans);
        if(pos!=-1){
            return c+i*m+nodes[pos].idx;
        }
        tmp=tmp*AM%B;
    }
    return -1;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    //CreatePrimeList();
    while(EOF!=scanf("%lld%lld%lld",&K,&P,&N)){
        if(N>=P){
             printf("Orz,I can’t find D!\n");
             continue;
        }
        ll ans=BabyStep(K,P,N);
        if(-1==ans){
             printf("Orz,I can’t find D!\n");
        }else{
            printf("%lld\n",ans);
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
