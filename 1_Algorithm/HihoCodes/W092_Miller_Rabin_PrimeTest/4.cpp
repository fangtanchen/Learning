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
const int MAXS=12;
const int MOD=1e9+7;

typedef long long int ll;
const int fac[]={2,3,5,7,11,13,17,19,23,29,31,37};

ll ModMul(ll a,ll b,ll p){
    ll ret=0;
    while(b){
        if(b&0x1){
            ret=(ret+a)%p;
        }
        a=(a+a)%p;
        b>>=1;
    }
    return ret;
}

ll ModExp(ll a,ll u,ll p){
    ll ret=1;
    while(u){
        if(u&0x1)ret=ModMul(ret,a,p);
        a=ModMul(a,a,p);
        u>>=1;
    }
    return ret;
}

bool MillerRabin(ll p){
    if(1==p)return false;
    if(2==p)return true;
    if(0==(p&0x1))return false;

    int xu=p-1;
    while((xu&0x1)==0){
        xu>>=1;
    }

    for(int si=0;si<MAXS;si++){
        int u=xu;
        int a=fac[si];
        if(a>=p)break;
        if(a<2)continue;
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
        ll x;
        scanf("%lld",&x);
        if(MillerRabin(x)){
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
