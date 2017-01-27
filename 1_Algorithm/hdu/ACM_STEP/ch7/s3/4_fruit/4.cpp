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

int N,M;

int dp[2][110];
int A[110],B[110];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d%d",&N,&M)){
            for(int ni=1;ni<=N;ni++){
                scanf("%d%d",A+ni,B+ni);
            }
            memset(dp,0,sizeof(dp));
            int now=0,la=1;
            for(int i=A[1];i<=B[1];i++)
                dp[now][i]=1;
            for(int ni=2;ni<=N;ni++){
                swap(la,now);
                memset(dp[now],0,sizeof(dp[now]));
                for(int j=0;j<=M;j++){
                    if(dp[la][j]==0)continue;
                    for(int k=A[ni];k<=B[ni];k++){
                        dp[now][j+k]+=dp[la][j];
                    }
                }
            }
            printf("%d\n",dp[now][M]);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
