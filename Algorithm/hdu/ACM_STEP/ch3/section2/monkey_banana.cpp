/*
 * monkey_banana.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: fangtanchen
 */

#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
using namespace std;


struct block{
	int len;
	int wid;
	int hei;
};


bool cmp(struct block a,struct block b){
	if(a.len>b.len)return true;
	//if(a.len==b.len)return true;
	if(a.len==b.len && a.wid>b.wid)return true;
	else return false;
}


int main(){
	int casei=1;
	int n;

	struct block b[100];
	int dp[100];
	while(cin>>n,n){
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
		int x[3];

		int bi=0;
		for(int i=0;i<n;i++){
			cin>>x[0]>>x[1]>>x[2];
			sort(x,x+3);

			int temp=x[0];
			x[0]=x[2];
			x[2]=temp;
			b[bi].hei=x[0];b[bi].len=x[1];b[bi].wid=x[2];bi++;
			b[bi].hei=x[1];b[bi].len=x[0];b[bi].wid=x[2];bi++;
			b[bi].hei=x[2];b[bi].len=x[0];b[bi].wid=x[1];bi++;
		}
		sort(b,b+3*n,cmp);
/*
		for(int i=0;i<bi;i++)
		{
			cout<<b[i].len<<" "<<b[i].wid<<" "<<b[i].hei<<endl;
		}*/

		int bimax=bi;
		for(int i=0;i<bimax;i++){
			dp[i]=b[0].hei;
		}

		for(int i=1;i<bimax;i++){
			int temp=0;
			for(int k=i-1;k>=0;k--){
				int flag=(b[i].len<b[k].len
						&& b[i].wid<b[k].wid);
				if(flag){
					if(temp<dp[k])temp=dp[k];
				}
			}
			dp[i]=temp+b[i].hei;
		}
		int max=0;
		for(int i=0;i<bimax;i++)
			if(max<dp[i])max=dp[i];
		printf("Case %d: maximum height = %d\n",casei++,max);
	}

	return 0;
}


