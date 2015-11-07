#include<iostream>
#include<string.h>
using namespace std;

#define SIZE 1000


int max(int x,int y){
	return x>y?x:y;
}

int main(){
	char X[SIZE],Z[SIZE];
	int xlen,zlen;
	int dp[2][SIZE+1];
	while(cin>>X>>Z){
		int dpi=0;
		memset(dp,0,sizeof(dp));


		xlen=strlen(X);
		zlen=strlen(Z);

		for(int xi=1;xi<=xlen;xi++){
			for(int zi=1;zi<=zlen;zi++){
				if(X[xi-1]==Z[zi-1]){
					dp[1-dpi][zi]=1+dp[dpi][zi-1];
				}
				else{
					dp[1-dpi][zi]=max(dp[dpi][zi],dp[1-dpi][zi-1]);
				}
			}
			dpi=1-dpi;
		}
		cout<<dp[dpi][zlen]<<endl;
	}
	return 0;
}
