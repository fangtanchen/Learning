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
typedef long long int LL;
const int MAXN=2e6+5;
const int MAXM=1e9+10;
const int MAXP=2e7+5;

bool isPrime[MAXP];
int primeList[MAXN];
int cntprime;
int fac2[40];

int pnum[100],pcnt[100],plen;


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
         LL tmpN=N;
         plen=0;
         for(int pi=0;pi<cntprime;pi++){
             LL kk=primeList[pi];
             if(kk*kk>tmpN)break;
             if(tmpN%kk==0){
                 pnum[plen]=kk;
                 pcnt[plen]=0;
                 while(tmpN%kk==0){
                      tmpN/=kk;
                      pcnt[plen]++;
                 }
                 plen++;
             }
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
