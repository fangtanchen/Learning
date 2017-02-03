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
const int MAXN=1010;
int sum,dp[MAXN];
int N,M,C;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&C);
    while(C--){
        scanf("%d%d",&N,&M);
        sum=0;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=M+1;i<=N;i++){
             if(sum)dp[i]=0;
             else dp[i]=1;
             sum=sum+dp[i]-dp[i-M];
        }
        if(dp[N]==0)puts("first");
        else puts("second");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
