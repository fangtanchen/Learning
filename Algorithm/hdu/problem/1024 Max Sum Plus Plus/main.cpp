#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAXN 1000000
#define INF 0x7fffffff
int dp[MAXN+10];//dp[i] ��ʾǰi�����֣����� i�� �ֳ� j��ʱ�����ֵ 
int maxt[MAXN+10];//max[i]��ʾ  i�����ֳַ�  j-1��  ʱ�����ֵ 

int a[MAXN+10];

int max1(int x,int y)
{
	return (x>=y?x:y);
}
int main(int argc, char** argv) {
	int maxx;
	int n,m;
	while(cin>>m>>n)
	{
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			dp[i]=0;
			maxt[i]=0;
		}
		dp[0]=0;
		maxt[0]=0;
		for(int j=1;j<=m;j++)
		{
			maxx=-INF;
			for(int i=j;i<=n;i++)
			{
				dp[i] = max1(dp[i-1],maxt[i-1])+a[i];
				maxt[i-1]=maxx;
				maxx=max1(dp[i],maxx);
			}
		}
		cout<<maxx<<endl;
		
		
	}
	return 0;
}
