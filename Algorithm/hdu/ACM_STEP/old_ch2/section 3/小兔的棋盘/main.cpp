#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int casei=1;
	long long dp[40][40];
	while(cin>>n,n!=-1)
	{
		for(int i=1;i<40;i++)
			dp[1][i]=1;
		for(int i=2;i<40;i++)
		{
			dp[i][i]=dp[i-1][i];
			for(int j=i+1;j<40;j++)
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
		printf("%d %d %I64d\n",casei++,n,2*dp[n+1][n+1]);
	}
	return 0;
}
