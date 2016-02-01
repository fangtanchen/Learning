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

int dp[100010];
int st[100010];
int num[100010];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int casei=1;casei<=T;casei++){
		
		int N;
		scanf("%d",&N);
		
		
		for(int i=1;i<=N;i++){
			scanf("%d",&num[i]);
		}
		
		dp[1]=num[1];
		st[1]=1;
		
		int max=num[1];
		int maxst=1;
		int maxed=1;
		
		
		for(int i=2;i<=N;i++){
			int temp=dp[i-1]+num[i];
			if(num[i]>temp){
				dp[i]=num[i];
				st[i]=i;
			}else{
				dp[i]=temp;
				st[i]=st[i-1];
			}
			if(dp[i]>max){
				max=dp[i];
				maxst=st[i];
				maxed=i;
			}
		}
		
		if(casei!=1)printf("\n");
		printf("Case %d:\n",casei);		
		printf("%d %d %d\n",max,maxst, maxed);
		
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
