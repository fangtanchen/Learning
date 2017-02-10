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
typedef long long int LL;
const int MAXN=4e4+5;
const int MAXP=4e4+5;

bool isPrime[MAXN];
LL primeList[MAXN];
int cntprime;
int fac2[40];

LL pnum[100],pcnt[100],plen;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1]=false;
    cntprime=0;
    for(int i=2;i<MAXP;i++){
        if(isPrime[i]){
            primeList[cntprime++]=i;
        }
        for(int pi=0;pi<cntprime;pi++){
            LL tmp=primeList[pi]*i;
            if(tmp>=MAXP)break;
            isPrime[tmp]=false;
            if(i%primeList[pi]==0)break;
        }
    }
    int T,P;
    LL N;
    scanf("%d",&T);
    while(T--){
         scanf("%lld%d",&N,&P);
         if(P==3){
             LL tmp=sqrt(N);
             bool flag=false;
             for(int i=-10;i<11;i++){
                 LL tt=tmp+i;
                 if(tt*tt==N){
                     flag=true;
                     break;
                 }
             }
             if(flag)puts("YES");
             else puts("NO");
             continue;
         }
         LL tmpN=N;
         plen=0;
         for(int pi=0;pi<cntprime;pi++){
              if(primeList[pi]*primeList[pi]>tmpN)break;
              if(tmpN%primeList[pi]==0){
                  pnum[plen]=primeList[pi];
                  pcnt[plen]=0;
                  while(tmpN%primeList[pi]==0){
                      tmpN/=primeList[pi];
                      pcnt[plen]++;
                  }
                  plen++;
              }
         }
         if(tmpN!=1){
              pnum[plen]=tmpN;
              pcnt[plen++]=1;
         }
         bool flag=true;
         LL tmpP=P-1;
         for(int pi=0;pi<plen;pi++){
             if(pcnt[pi]%tmpP){
                 flag=false;
                 break;
             }
         }
         if(flag)printf("YES\n");
         else puts("NO");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
