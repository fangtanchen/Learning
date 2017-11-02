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
const int MAXN=1005;

int dp[MAXN][MAXN];
int sum[MAXN],A[MAXN];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);

    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));

    for(int i=1;i<=N;i++){
         scanf("%d",A+i);
         sum[i]=sum[i-1]+A[i];
    }
    for(int l=1;l<=N;l++){
        for(int i=N-l+1;i>=1;i--){
            dp[l][i]=max(
                    sum[i+l-1]-sum[i-1]-dp[l-1][i],
                    sum[i+l-1]-sum[i-1]-dp[l-1][i+1]);
        }
    }
    printf("%d\n",dp[N][1]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
