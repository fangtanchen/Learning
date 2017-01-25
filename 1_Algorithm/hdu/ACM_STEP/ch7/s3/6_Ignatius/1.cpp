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

int N;
int dp[2][300];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int N;
    while(EOF!=scanf("%d",&N)){
        int now=1,la=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=N;i++)dp[la][i]=1;
        for(int i=2;i<=N;i++){
            memset(dp[now],0,sizeof(dp[now]));
            for(int j=0;j<=N;j++){
                int kmax=N-j;
                for(int k=0;k<=kmax;k+=i){
                    dp[now][k+j]+=dp[la][j];
                }
            }
            swap(la,now);
        }
        printf("%d\n",dp[la][N]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
