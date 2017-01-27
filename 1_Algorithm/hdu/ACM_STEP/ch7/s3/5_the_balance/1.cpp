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
const int MAXN=11000;

int N;
int A[110];
int dp[2][10010];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d",&N)){
            for(int ni=1;ni<=N;ni++){
                scanf("%d",A+ni);
            }

            memset(dp,0,sizeof(dp));
            int now=0,la=1;
            dp[now][0]=dp[now][A[1]]=1;
            int jmax=A[1];
            for(int ni=2;ni<=N;ni++){
                 swap(now,la);
                 memset(dp[now],0,sizeof(dp[now]));
                 for(int j=0;j<=jmax;j++){
                     if(dp[la][j]==0)continue;
                     dp[now][j]+=dp[la][j];
                     dp[now][j+A[ni]]+=dp[la][j];
                     int tmp=abs(j-A[ni]);
                     dp[now][tmp]+=dp[la][j];
                 }
                 jmax+=A[ni];
            }
            int cnt=0;
            for(int j=1;j<=jmax;j++){
                 cnt=cnt+(dp[now][j]==0);
            }
            printf("%d\n",cnt);
            for(int j=1,cnti=1;j<=jmax;j++){
                if(dp[now][j]==0){
                     printf("%d%c",j,(cnti==cnt?'\n':' '));
                     cnti++;
                }
            }

        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
