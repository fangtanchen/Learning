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
const int MAXN=1e6+10;

bool isPrime[MAXN];
int primeList[MAXN];
int pcnt;

bool Init(){
     memset(isPrime,true,sizeof(isPrime));
     pcnt=0;
     primeList[pcnt++]=2;
     for(int i=3;i<MAXN;i++){
         if(isPrime[i]){
             primeList[pcnt++]=i;
         }
         for(int pi=0;pi<pcnt;pi++){
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
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    int N;
    cin>>N;
    for(int i=2;i<=N-i;i++){
        if(isPrime[i]&&(isPrime[N-i])){
            printf("%d %d\n",i,N-i);
            break;
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
