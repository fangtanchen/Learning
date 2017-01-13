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
const int MAXN=1e5;
bool isPrime[MAXN];
int primeList[MAXN];
int cnt_prime;

void Init(){
    cnt_prime=0;
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1]=false;
    for(int i=2;i<MAXN;i++){
        if(isPrime[i]){
            primeList[cnt_prime++]=i;
        }
        for(int pi=0;pi<cnt_prime;pi++){
            int tmp=primeList[pi]*i;
            if(tmp>=MAXN)break;
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
    int T,N;
    scanf("%d",&T);
    Init();
    for(int ti=1;ti<=T;ti++){
        scanf("%d",&N);
        int cnt=1;
        int imax=sqrt(N+1);
        for(int pi=0;pi<cnt_prime;pi++){
            if(primeList[pi]>imax)break;
            if(N%primeList[pi]==0){
                 int tmp=0;
                 while(0==N%primeList[pi]){
                     N/=primeList[pi];
                     tmp++;
                 }
                 cnt=cnt*(1+2*tmp);
                 if(N==1)break;
                 imax=sqrt(N+1);
            }
        }
        if(N!=1)cnt*=3;
        printf("Scenario #%d:\n%d\n\n",ti,(1+cnt)>>1);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
