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
    int N;
    Init();
    while(scanf("%d",&N),N){
         int tmpN=N;
         int p[30],pnum=0;
         int top=sqrt(N)+1;
         for(int pi=0;pi<cnt_prime;pi++){
             if(primeList[pi]>=top)break;
             if(0==tmpN%primeList[pi]){
                 p[pnum++]=primeList[pi];
                 while(0==tmpN%primeList[pi]){
                     tmpN/=primeList[pi];
                 }
                 if(1==tmpN)break;
             }
             top=sqrt(N)+1;
         }
         if(1!=tmpN)p[pnum++]=tmpN;
         int imax=(1<<pnum);
         long long int ans=0;
         for(int i=1;i<imax;i++){// 0 is not needed
             int tmpi=i;
             int numsum=0;
             long long int mul=1;
             for(int j=0;(j<pnum)&& tmpi;j++){
                 if(tmpi&0x01){
                     numsum++;
                     mul*=p[j];
                 }
                 tmpi>>=1;
             }
             long long int tmp=(mul+(N-1)/mul*mul)*((N-1)/mul)/2;
             tmp%=MODU;
             if(numsum&1)ans+=tmp;
             else ans-=tmp;
             ans%=MODU;
             if(ans<0)ans+=MODU;
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
