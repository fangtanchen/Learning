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
#define MAXN 510
#define MAXM 100010

int N,M;
int need[MAXN],val[MAXN];
int dp[MAXM];


void init(){
    memset(need,0,sizeof(need));
    memset(val,0,sizeof(val));
    memset(dp,0,sizeof(dp));
}
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    init();
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d%d",need+i,val+i);
    }
    for(int i=1;i<=N;i++){
        for(int j=need[i];j<=M;j++){
            dp[j]=max(dp[j],dp[j-need[i]]+val[i]);
        }
    }
    int ans=dp[M];
    for(int i=M-1;i>=0;i--){
        if(ans<dp[i])ans=dp[i];
    }
    printf("%d\n",ans);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
