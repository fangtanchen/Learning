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
const int MAXN=55;
const int MAXM=3e5+10;

int N;
int V[MAXN],M[MAXN];
int dp[2][MAXM];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&N),N>0){
            int sum=0;
            for(int ni=1;ni<=N;ni++){
                scanf("%d%d",V+ni,M+ni);
                sum+=V[ni]*M[ni];
            }
            memset(dp,0,sizeof(dp));
            for(int i=0,v=0;i<=M[1];i++,v+=V[1]){
                 dp[0][v]=1;
            }
            int now=0,la=1;
            int jmax=V[1]*M[1];
            for(int ni=2;ni<=N;ni++){
                swap(now,la);
                memset(dp[now],0,sizeof(dp[now]));
                for(int j=0;j<=jmax;j++){
                     if(dp[la][j]==0)continue;
                     for(int k=0,v=0;k<=M[ni];k++,v+=V[ni]){
                         dp[now][j+v]+=dp[la][j];
                     }
                }
                jmax+=V[ni]*M[ni];
            }
            int tmp=(sum+1)/2;
            int ansi=0;
            for(int i=tmp;i<=sum;i++){
                if(dp[now][i]){
                    ansi=i;
                    break;
                }
            }
            printf("%d %d\n",ansi,sum-ansi);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
