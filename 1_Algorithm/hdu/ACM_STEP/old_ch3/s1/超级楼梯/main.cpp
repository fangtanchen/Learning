#include <iostream>
#include<cmath>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	cin>>N;
	
	int dp[40]={0};
	dp[1]=1;dp[2]=2;
	for(int i=3;i<40;i++)
		dp[i]=dp[i-1]+dp[i-2];
	
	while(N--)
	{
		int M;
		cin>>M;
		cout<<dp[M-1]	<<endl;;
	}
	return 0;
}
