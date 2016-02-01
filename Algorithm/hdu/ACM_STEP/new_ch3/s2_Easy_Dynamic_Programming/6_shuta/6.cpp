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

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int C;
	cin>>C;
	while(C--){
		int n;
		int f[101][101];
		
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++)
				cin>>f[i][j];
		}
		int dp[2][101];
		int si=0;
		int di=1;
		dp[si][1]=f[1][1];
		for(int i=2;i<=n;i++){
			dp[di][1]=dp[si][1]+f[i][1];
			for(int j=2;j<i;j++){
				int a=(dp[si][j]>dp[si][j-1])?dp[si][j]:dp[si][j-1];
				dp[di][j]=a+f[i][j];
			}
			dp[di][i]=dp[si][i-1]+f[i][i];
			si=1-si;
			di=1-di;
		}
		int max=dp[si][1];
		for(int i=2;i<=n;i++){
			if(max<dp[si][i]){
				max=dp[si][i];
			}
		}
		printf("%d\n",max);
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
