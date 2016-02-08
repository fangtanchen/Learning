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

int a[10005];
double b[10005];
double dp[10005];//record prob of failure

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int n,m;
	while(EOF!=scanf("%d%d",&n,&m),m||n){
		
		for(int mi=1;mi<=m;mi++){
			scanf("%d%lf",&a[mi],&b[mi]);
			b[mi]=1-b[mi];
		}
		for(int i=0;i<=n;i++){
			dp[i]=1.0;
		}
		//memset(dp,1.0,sizeof(dp));
#ifdef U_DEBUG
for(int i=0;i<11;i++){
	printf("%lf ",dp[i]);
}
#endif
		for(int mi=1;mi<=m;mi++){
			for(int ni=n;ni>=a[mi];ni--){
				double temp=dp[ni-a[mi]]*b[mi];
				if(temp<dp[ni]){
					dp[ni]=temp;
				}
			}
		}
		double min=dp[n];
		for(int i=n-1;i>=0;i--){
			if(min>dp[i])min=dp[i];
		}
		printf("%2.1lf%%\n",(1.0-min)*100);


	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
