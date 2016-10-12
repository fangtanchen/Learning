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

int dp[101][1010];
int ti[101];
int val[101];
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int cases;
	scanf("%d",&cases);
	while(cases--){
		int N,M,L;
		scanf("%d%d%d",&N,&M,&L);
		memset(dp,-1,sizeof(dp));
		memset(dp[0],0,sizeof(dp[0]));
		
		for(int i=1;i<=N;i++){
			scanf("%d%d",&ti[i],&val[i]);
		}
		for(int ni=1;ni<=N;ni++){
			for(int mi=M;mi>=1;mi--){
				for(int li=L;li>=ti[ni];li--){
					if(dp[mi-1][li-ti[ni]]!=-1){
						int temp=dp[mi-1][li-ti[ni]]+val[ni];
						if(temp>dp[mi][li]){
							dp[mi][li]=temp;
						}
					}
				}
			}
		}
		if(dp[M][L]==-1){
			printf("0\n");
		}
		else{
			printf("%d\n",dp[M][L]);
		}
		

		{
			
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
