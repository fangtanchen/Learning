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
const int MAXN=105;
const int MAXM=610;

double dp[MAXN][MAXM];
int N,M;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>M;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<7;i++){
        dp[1][i]=100.0/6;
    }
    for(int i=2;i<=N;i++){
        int jmax=6*i;
        for(int j=i;j<=jmax;j++){
            for(int k=1;k<=6;k++){
                dp[i][j]=dp[i][j]+dp[i-1][j-k]/6;
            }
        }
    }
    printf("%.2lf\n",dp[N][M]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
