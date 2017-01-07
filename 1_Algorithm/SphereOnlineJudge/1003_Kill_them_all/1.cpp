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
const int MAXN=1e6+1;
const int MODU=1e9+7;
typedef long long ll;

long long int fac[MAXN];
int T,N;

ll ModExp(ll a,ll b,ll p){
    ll ret=1;
    for(;b;b>>=1,a=(a*a)%p){
        if(b&0x1){
            ret=(ret*a)%p;
        }
    }
    return ret;
}

ll C(ll n,ll m){
    return fac[n]*ModExp(fac[m],MODU-2,MODU)%MODU
        *ModExp(fac[n-m],MODU-2,MODU)%MODU;
}

int scan(){
    int ch;
    int ret=0;
    while((ch=getchar()),ch>'9'||ch<'0')
        ;
    ret=ch-'0';
    while(ch=getchar(),(ch>='0')&&(ch<='9')){
        ret=ret*10+ch-'0';
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    fac[0]=fac[1]=1;
    for(int ni=2;ni<MAXN;ni++){
        fac[ni]=(fac[ni-1]*ni)%MODU;
    }
    T=scan();
    while(T--){
         N=scan();
         printf("%lld\n",C(N-1,N>>1));
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
