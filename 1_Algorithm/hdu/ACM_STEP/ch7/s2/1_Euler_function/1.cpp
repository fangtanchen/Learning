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
const int MAXN=3e6+20;

int dp[MAXN];
int primeList[MAXN];
int cntprime;
bool bPrime[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    memset(dp,0,sizeof(dp));
    cntprime=0;
    memset(bPrime,true,sizeof(bPrime));
    for(int ni=2;ni<MAXN;ni++){
        if(bPrime[ni]){
            primeList[cntprime++]=ni;
            dp[ni]=ni-1;
        }
        for(int pi=0;pi<cntprime;pi++){
            int tmp=ni*primeList[pi];
            if(tmp>=MAXN)break;
            bPrime[tmp]=false;
            if(ni%primeList[pi]==0){
                dp[tmp]=dp[ni]*primeList[pi];
                break;
            }else{
                dp[tmp]=dp[ni]*dp[primeList[pi]];
            }
        }
    }
    int a,b;
    while(EOF!=scanf("%d%d",&a,&b)){
         long long int ans=0;
         for(int i=a;i<=b;i++){
             ans+=dp[i];
         }
         printf("%lld\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
