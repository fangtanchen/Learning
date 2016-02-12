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

int cmp(int x, int y ){
	if(x>=y)return false;
	else return true;
}

int dp[1310];
int val[1310];
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n,m;
	while(EOF!=scanf("%d",&n),n){
		for(int i=1;i<=n;i++){
			scanf("%d",&val[i]);
		}
		scanf("%d",&m);
		if(m<5){
			printf("%d\n",m);
			continue;
		}
		memset(dp,0,sizeof(dp));

		sort(val+1,val+n+1,cmp);

		int max_val=val[n];

		for(int ni=1;ni<n;ni++){
			for(int mi=m-5;mi>=val[ni];mi--){
				int temp=dp[mi-val[ni]]+val[ni];
				if(temp>dp[mi]){
					dp[mi]=temp;
				}
			}
		}
		printf("%d\n",m-max_val-dp[m-5]);
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
