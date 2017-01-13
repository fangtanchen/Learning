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
const int MODU=1e9+7;
const int MAXN=1e9+7;
const int MAXM=1e5;

int primeList[MAXM];
int cnt_prime;
bool isPrime[MAXM];

void Init(){
    cnt_prime=0;
    memset(isPrime,true,sizeof(isPrime));
    for(int i=2;i<MAXM;i++){
        if(isPrime[i]){
            primeList[cnt_prime++]=i;
        }
        for(int pi=0;pi<cnt_prime;pi++){
            int tmp=primeList[pi]*i;
            if(tmp>=MAXM)break;
            isPrime[tmp]=false;
            if(i%primeList[pi]==0)break;
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    long long int N;
    Init();
    while(scanf("%lld",&N),N){
        if(1==N){
            printf("0\n");
            continue;
        }
         long long int tmpN=N;
         long long int pnum=1;
         long long int top=sqrt(N)+1;
         for(int pi=0;pi<cnt_prime;pi++){
             if(primeList[pi]>=top)break;
             if(0==tmpN%primeList[pi]){
                 pnum*=(primeList[pi]-1);
                 tmpN/=primeList[pi];
                 while(0==tmpN%primeList[pi]){
                     tmpN/=primeList[pi];
                     pnum*=primeList[pi];
                 }
                 if(1==tmpN)break;
             }
             top=sqrt(N)+1;
         }
         if(1!=tmpN)pnum*=tmpN-1;
         long long int ans=(N*(N-1))/2-N*pnum/2;
         ans%=MODU;
         printf("%lld\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
