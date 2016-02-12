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
	int num[1010];
	long long dp[1010]={0};
	int n;
	while(EOF!=scanf("%d",&n),n){
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
		}
		dp[1]=num[1];
		for(int i=2;i<=n;i++){
			dp[i]=num[i];
			for(int j=1;j<i;j++){
				if(num[j]<num[i]){
					long long temp=num[i]+dp[j];
					if(dp[i]<temp){
						dp[i]=temp;
					}
				}
			}
		}
		long long max=dp[1];
		for(int i=2;i<=n;i++){
			if(max<dp[i]){
				max=dp[i];
			}
		}
		printf("%lld\n",max);
	}


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
