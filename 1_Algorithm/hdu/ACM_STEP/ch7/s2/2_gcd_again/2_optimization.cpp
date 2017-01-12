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
const int MAXN=1e8+10;
const int MAXM=1e6+10;

int primeList[MAXM];
int cntPrime;
bool isPrime[MAXM];
int dp[MAXM];

void Init(){
    cntPrime=0;
    memset(isPrime,true,sizeof(isPrime));
    memset(dp,0,sizeof(dp));
    for(int ni=2;ni<MAXM;ni++){
        if(isPrime[ni]){
            primeList[cntPrime++]=ni;
            dp[ni]=ni-1;
        }
        for(int pi=0;pi<cntPrime;pi++){
            int tmp=primeList[pi]*ni;
            if(tmp>MAXM)break;
            isPrime[tmp]=false;
            if(ni%primeList[pi]==0){
                 dp[tmp]=dp[ni]*(primeList[pi]);
                 break;
            }else{
                dp[tmp]=dp[ni]*(dp[primeList[pi]]);
            }
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    int N;
    while(scanf("%d",&N),N){
         if(N<MAXM){
             printf("%d\n",N-1-dp[N]);
             continue;
         };
         int ans=1;
         int tmpN=N;
         for(int pi=0;pi<cntPrime;pi++){
             int imax=sqrt(N)+1;
             if(primeList[pi]>=imax)break;
             if(N%primeList[pi]==0){
                  N/=primeList[pi];
                  ans*=dp[primeList[pi]];
                  while(N%primeList[pi]==0){
                      N/=primeList[pi];
                      ans*=primeList[pi];
                  }
             }
             if(N<MAXM){
                 ans*=dp[N];
                 N=1;
                 break;
             };
         }
         if(N!=1)ans*=(N-1);
         printf("%d\n",tmpN-1-ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
