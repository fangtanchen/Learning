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

#define SIZE 1010

int n;
int dp[SIZE][SIZE][2];
int g[SIZE][SIZE];


void init(){
	memset(dp, 0, sizeof(dp));
	memset(g, 0, sizeof(g));
}

int k;
int path(int ri, int ci){
	if((1==ri)&&(1==ci)){
		return 0;
	}else if(ri==1){
		for(int i=1;i<ci;i++){
			putchar('R');
		}
	}else if(ci==1){
		for(int i=1;i<ri;i++)
			putchar('D');
	}else{
		if(dp[ri-1][ci][k]<dp[ri][ci-1][k]){
			path(ri-1, ci);
			putchar('D');
		}else{
			path(ri, ci-1);
			putchar('R');
		}
	}
	return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	while(EOF!=scanf("%d", &n)){
		init();
		int a;
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d", &a);
				if(!a){
					x=i;
				}
				else{
					while(a%2==0){
						dp[i][j][0]++;
						a/=2;
					}
					while(a%5==0){
						dp[i][j][1]++;
						a/=5;
					}
				}
				for(int k=0;k<2;k++){
					if((1==i)&&(1==j)){
						continue;
					}else if(1==i){
						dp[i][j][k]+=dp[i][j-1][k];
					}else if(1==j){
						dp[i][j][k]+=dp[i-1][j][k];
					}else{
						if(dp[i-1][j][k]>dp[i][j-1][k]){
							dp[i][j][k]+=dp[i][j-1][k];
						}else{
							dp[i][j][k]+=dp[i-1][j][k];
						}
					}
				}
			}

		}

			k=(dp[n][n][0]>dp[n][n][1]);
			if(x&&(dp[n][n][k]>1)){
				printf("1\n");
				for(int i=1;i<x;i++)
					putchar('D');
				for(int i=1;i<n;i++)
					putchar('R');
				for(int i=x;i<n;i++)
					putchar('D');
			}else{
				printf("%d\n", dp[n][n][k]);
				path(n, n );
			}
			putchar('\n');
		
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
