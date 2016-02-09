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
	scanf("%d",&C);
	int dp[22][1010];
	int f[22][1010];
	while(C--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int ri=1;ri<=n;ri++){			
			for(int ci=1;ci<=m;ci++){
				scanf("%d",&f[ri][ci]);
			}
		}
		memset(dp,-10000000,sizeof(dp));
		dp[1][1]=f[1][1];
		for(int ri=1;ri<=n;ri++){
			for(int ci=1;ci<=m;ci++){
				for(int kk=ci+ci;kk<=m;kk+=ci){
					int temp=dp[ri][ci]+f[ri][kk];
					if(dp[ri][kk]<temp){
						dp[ri][kk]=temp;
					}
				}
				int temp=dp[ri][ci]+f[ri+1][ci];
				if(dp[ri+1][ci]<temp){
					dp[ri+1][ci]=temp;
				}
				temp=dp[ri][ci]+f[ri][ci+1];
				if(dp[ri][ci+1]<temp){
					dp[ri][ci+1]=temp;
				}
			}
		}
		printf("%d\n",dp[n][m]);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
