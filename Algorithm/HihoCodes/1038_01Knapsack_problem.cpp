#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAX 200000

int dp[2][MAX];
int need[510];
int val[510];

void gao(int& x,int y){
    x=max(x,y);
}
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int N,M;
    scanf("%d%d",&N,&M);
    for(int ni=1;ni<=N;ni++){
         scanf("%d %d",need+ni,val+ni);
    }
    memset(dp,0,sizeof(dp));
    int si=0,di=1;
    for(int i=1;i<=N;i++){
//        memset(dp[di],0,sizeof(dp[di]));
        memcpy(dp[di],dp[si],sizeof(dp[si]));
        for(int j=need[i];j<=M;j++){
            gao(dp[di][j],dp[si][j-need[i]]+val[i]);
        }
        si=1-si;
        di=1-di;
    }
    printf("%d\n",dp[si][M]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
