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
typedef long long ll;


ll Josephus(ll n, ll k){
     if(1==n)return 0;
     ll ret=0;
     if(n<k){
         ret=0;
         for(int i=2;i<=n;i++){
             ret=(ret+k)%i;
         }
         return ret;
     }
     ret=Josephus(n-n/k,k);
     if(ret<n%k)ret=ret-n%k+n;
     else ret=ret-n%k+(ret-n%k)/(k-1);
     return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    while(T--){
         ll n,k;
         ll ans=0;
         scanf("%ld%ld",&n,&k);
         printf("%lld\n",Josephus(n,k));
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
