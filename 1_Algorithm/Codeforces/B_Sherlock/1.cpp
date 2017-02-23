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
const int MAXN=1e5+10;

bool isPrime[MAXN];
int color[MAXN];
int primeList[MAXN];
int pcnt;
int N;



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    pcnt=0;
    memset(isPrime,true,sizeof(isPrime));
    memset(color,0,sizeof(color));
    for(int i=2;i<MAXN;i++){
        if(isPrime[i]){
            primeList[pcnt++]=i;
            color[i]=1;
        }
        for(int pi=0;pi<pcnt;pi++){
             int tmp=primeList[pi]*i;
             if(tmp>=MAXN)break;
             isPrime[tmp]=false;
             if(i%primeList[pi]==0)break;
        }
    }
    scanf("%d",&N);
    int t=1;
    for(int i=1;i<=N;i++){
        if(!isPrime[i+1]) {
            t++;
            break;
        }
    }
    printf("%d\n",t);
    for(int i=1;i<=N;i++){
        if(isPrime[i+1]){
             printf("1 ");
        }else{
            printf("2 ");
        }
    }



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
