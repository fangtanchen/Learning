#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int f[100010][11];
int dp[2][14];


int max2(int x, int y){
	if(x>=y)return x;
	else return y;
}

#define max3(x,y,z) max2(x,max2(y,z))

int main(){
	int n;
	while(EOF!=scanf("%d",&n),n){
		int max_ti=0;
		int a,t;
		memset(f,0,sizeof(f));
		while(n--){
			scanf("%d%d",&a,&t);
			f[t][a]+=1;
			if(t>max_ti)max_ti=t;
		}
		int si=0;
		int di=1;
		memset(dp,0,sizeof(dp));
		for(int ti=max_ti;ti>=0;ti--){
			dp[di][0]=max2(dp[si][0],dp[si][1])+f[ti][0];
			dp[di][10]=max2(dp[si][9],dp[si][10])+f[ti][10];
			for(int posj=1;posj<10;posj++){
				dp[di][posj]=max3(dp[si][posj-1],dp[si][posj],
							dp[si][posj+1])+f[ti][posj];
			}

			si=1-si;
			di=1-di;
		}
		printf("%d\n",dp[si][5]);
	}	

	return 0;
}

