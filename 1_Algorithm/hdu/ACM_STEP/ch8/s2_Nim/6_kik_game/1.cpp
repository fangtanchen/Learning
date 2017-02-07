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
const int MAXN=2010;

int dp[MAXN];
int N,M;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d%d",&N,&M),N+M){
             memset(dp,0,sizeof(dp));
             dp[1]=1;
             for(int i=2;i<=M;i++){
                  dp[i]=1-dp[i-1];
             }
             for(int i=2;i<=N;i++){
                 int tmp=dp[1];
                 dp[1]=1-dp[1];
                 for(int j=2;j<=M;j++){
                      int sum=0;
                      sum=sum+dp[j-1]+tmp+dp[j];
                      tmp=dp[j];
                      if(sum)dp[j]=0;
                      else dp[j]=1;
                 }
             }
             if(dp[M])puts("What a pity!");
             else puts("Wonderful!");
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
