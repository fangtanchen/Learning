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

int primeList[MAXN];
int pcnt;
bool bPrime[MAXN];
int N;

int Eular(int n){
    memset(primeList,0,sizeof(primeList)) ;
    memset(bPrime,true,sizeof(bPrime));
    pcnt=0;
    bPrime[1]=bPrime[0]=false;
    for(int ni=2;ni<=n;ni++){
        if(bPrime[ni]){
             primeList[pcnt++]=ni;
        }
        for(int pi=0;pi<pcnt;pi++){
            int pp=primeList[pi]*ni;
            if(pp>n)break;
            bPrime[pp]=false;
            if(ni%primeList[pi]==0)break;
        }
    }
    return pcnt;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    printf("%d\n",Eular(N));

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
