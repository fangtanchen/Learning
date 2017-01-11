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
const int MAXN=1050;

int dp[MAXN][MAXN];
char S[MAXN],T[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%s",S+1);
    scanf("%s",T+1);
    memset(dp,0,sizeof(dp));
    int i,j;
    int ans=0;
    for(i=1;T[i];i++){
        for(j=1;S[j];j++){
            dp[i][j]=dp[i][j-1];
            if(S[j]!=T[i])continue;
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            ans=max(ans,dp[i][j]);
        }
    }
    printf("%d\n",i-1-ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
