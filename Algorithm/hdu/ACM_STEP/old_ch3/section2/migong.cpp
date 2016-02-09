/*
 * migong.cpp

 *
 *  Created on: Apr 7, 2015
 *      Author: fangtanchen
 */

//如果当前格子是（x,y），下一步可以是（x+1,y），(x,y+1)或者(x,y*k) 其中k>1。那么对于（x,y）来说，可以由（x，1）跳到
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;


int main(){
	int C;
	cin>>C;
	int num[21][1001];
	int dp[21][1001];
	while(C--){


		int n,m;
		cin>>n>>m;

		memset(dp,-101,sizeof(dp));
		memset(num,-101,sizeof(num));

		for(int i=1;i<=n;i++){

			for(int j=1;j<=m;j++)
				cin>>num[i][j];
		}
		dp[1][1]=num[1][1];
		for(int i=2;i<=n;i++)
			dp[i][1]=dp[i-1][1]+num[i][1];

		for(int j=2;j<=m;j++){
			dp[1][j]=(dp[1][j-1]>dp[1][1]?dp[1][j-1]:dp[1][1])+num[1][j];
			//int pmax=j/2+1;
			for(int p=2;p<=j;p++){
				if(0==j%p){
					int temp=dp[1][j/p]+num[1][j];
					if(temp>dp[1][j])dp[1][j]=temp;
				}
			}
		}

		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				dp[i][j]=(dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1])+num[i][j];
				//int pmax=j/2+1;
				for(int p=2;p<=j;p++){
					if(0==j%p){
						int temp=dp[i][j/p]+num[i][j];
						if(temp>dp[i][j])dp[i][j]=temp;
					}
				}
			}
		}
		cout<<dp[n][m]<<endl;

	}

	return 0;
}



