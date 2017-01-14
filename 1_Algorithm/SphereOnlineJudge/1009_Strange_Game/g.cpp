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
const int MAXN=1005;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;

int dp[MAXN][MAXM][MAXS];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("in.txt","w",stdout);
	#endif
    srand(time(NULL));
    printf("10\n");
    for(int i=0;i<10;i++){
        int N=rand()%10000;
        int K=(rand()%10000*10000)+rand()%10000;
        int L=rand()%100000;
        int M=rand()%L;
        printf("%d %d %d %d\n",N,K,L,M);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
