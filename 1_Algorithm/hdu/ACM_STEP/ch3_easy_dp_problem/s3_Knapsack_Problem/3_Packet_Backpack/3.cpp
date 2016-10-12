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
class Sneakers{
	public:
		int b;
		int c;
};

int dp[11][10010];
Sneakers sn[11][102];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int N,M,K;
	int sn_len[11];
	while(EOF!=scanf("%d%d%d",&N,&M,&K)){

#ifdef U_DEBUG
	for(int i=0;i<4;i++){
		for(int j=0;j<10;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
#endif
		memset(sn_len,0,sizeof(sn_len));
		memset(dp,-1,sizeof(dp));
		memset(dp[0],0,sizeof(dp[0]));
		
		for(int i=0;i<11;i++){
			sn_len[i]++;
		}

		for(int si=0;si<N;si++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			sn[a][sn_len[a]].b=b;
			sn[a][sn_len[a]].c=c;
			sn_len[a]++;
		}
		
		for(int ki=1;ki<=K;ki++){
			for(int si=1;si<sn_len[ki];si++){
				for(int vi=M;vi>=sn[ki][si].b;vi--){
					int temp1=dp[ki-1][vi-sn[ki][si].b];
					int temp2=dp[ki][vi-sn[ki][si].b];
					int max=-1;
					if(temp1>max){
						max=temp1;	
					}
					if(temp2>max){
						max=temp2;
					}
					
					if(max<0)continue;
					else{
						max+=sn[ki][si].c;
						if(max>dp[ki][vi]){
							dp[ki][vi]=max;
						}
					}
				}
			}
		}
		if(dp[K][M]>=0)printf("%d\n",dp[K][M]);
		else{
			printf("Impossible\n");
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
