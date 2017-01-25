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
int fac[20];
int dp[2][310];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        for(int i=1;i<=17;i++){
             fac[i]=i*i;
        }
        int N;
        while(scanf("%d",&N),N){
             memset(dp,0,sizeof(dp));
             int now=1,la=0;
             for(int i=0;i<=N;i++){
                 dp[la][i]=1;
             }
             for(int i=2;i<=17;i++){
                  memset(dp[now],0,sizeof(dp[now]));
                  for(int j=0;j<=N;j++){
                      for(int k=0;j+k<=N;k+=fac[i]){
                          dp[now][j+k]+=dp[la][j];
                      }
                  }
                  swap(now,la);
             }
             printf("%d\n",dp[la][N]);
        }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
