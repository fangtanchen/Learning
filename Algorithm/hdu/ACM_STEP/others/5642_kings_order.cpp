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

#define MODU 1000000007
#define MAX 26

unsigned int dp[2001][26][3];



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<MAX;i++){
		dp[1][i][0]=1;
	}
	for(int ri=2;ri<2001;ri++){
		for(int ci=0;ci<MAX;ci++){
			for(int wi=0;wi<MAX;wi++){
				if(wi==ci)continue;
				for(int di=0;di<3;di++){
					dp[ri][ci][0]=(dp[ri][ci][0]+dp[ri-1][wi][di])%MODU;
				}
			}
			dp[ri][ci][1]=dp[ri-1][ci][0];
			dp[ri][ci][2]=dp[ri-1][ci][1];
		}
	}
	int T;
	for(scanf("%d", &T);T--;){
		int n;
		scanf("%d", &n);
		unsigned int ans=0;
		for(int ci=0;ci<MAX;ci++){
			for(int di=0;di<3;di++){
				ans=(ans+dp[n][ci][di])%MODU;
			}
		}
		printf("%u\n", ans);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
