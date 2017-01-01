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
const int MAXN=1005;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;

typedef long long int ll;
const int fac[]={2,3,5,7,11,13,17,19,23,29,31,37};

ll ModProd(ll a,ll b,ll p){
    ll ret=0;
    ll tmp=a;
    while(b){
        if(0x1&b)ret=(ret+tmp)%p;
        tmp=(tmp+tmp)%p;
        b>>=1;
    }
    return ret;
}

ll ModExp(ll a,ll b,ll p){
    ll ret=1;
    while(b){
        if(b&0x1)ret=ModProd(ret,a,p);
        a=ModProd(a,a,p);
        b>>=1;
    }
    return ret;
}


bool MillerRabin(ll p){
    if(1==p){
        return false;
    }
    if(2==p)return true;
    if(p%2==0)return false;
    ll xu=p-1;
    while(xu%2==0){
        xu/=2;
    }
    for(int si=0;si<12;si++){
        ll u=xu;
        ll a=fac[si];
        if(a==p)continue;
        ll x=ModExp(a,u,p);
        while(u<p){
            ll y=ModExp(x,2,p);
            if((1==y)&&(1!=x)&&(p-1!=x)){
                 return false;
            }
            x=y;
             u*=2;
        }
        if(x!=1)return false;
    }
    return true;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int N;
    scanf("%d",&N);
    while(N--){
         ll num;
         scanf("%lld",&num);
         if(MillerRabin(num)){
             printf("Yes\n");
         }else{
              printf("No\n");
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
