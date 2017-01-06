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
const int MAXN=1e6+10;
int primeList[MAXN];
int pcnt;
bool bPrime[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    memset(primeList,0,sizeof(primeList));
    pcnt=0;
    memset(bPrime,true,sizeof(bPrime));
    bPrime[1]=bPrime[0]=false;
    for(int ni=2;ni<MAXN;ni++){
        if(bPrime[ni]) {
            primeList[pcnt++]=ni;
        }
        for(int pi=0;pi<pcnt;pi++){
             int n=primeList[pi]*ni;
             if(n>=MAXN)break;
             bPrime[n]=false;
             if(ni%primeList[pi]==0)break;
        }
    }
    int N;
    while(EOF!=scanf("%d",&N)){
        int pmax=sqrt(N);
        int ans=1;
        for(int pi=0;pi<pcnt;pi++){
            if(primeList[pi]>pmax)break;
            if(N%primeList[pi]==0){
                 ans*=primeList[pi]-1;
                 N/=primeList[pi];
                 while(0==N%primeList[pi]){
                     ans*=primeList[pi];
                     N/=primeList[pi];
                 }
            }
        }
        if(N!=1)ans*=N-1;// if N is a prime
        printf("%d\n",(1+ans)/2);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
