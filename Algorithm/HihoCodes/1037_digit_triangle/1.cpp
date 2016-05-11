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

#define MAXN 110

int map[MAXN][MAXN];
int dp[2][MAXN];

int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    memset(map,0,sizeof(map));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",map[i]+j);
        }
    }
    memset(dp,0,sizeof(dp));
    dp[0][1]=map[1][1];
    int si=0,di=1;;
    for(int i=2;i<=N;i++){
        for(int j=2;j<i;j++){
             dp[di][j]=max(dp[si][j-1],dp[si][j])
                 +map[i][j];
        }
        dp[di][1]=dp[si][1]+map[i][1];
        dp[di][i]=dp[si][i-1]+map[i][i];
        si=1-si;
        di=1-di;
    }
    int ans=0;
    for(int i=1;i<=N;i++){
         if(dp[si][i]>ans)ans=dp[si][i];
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
