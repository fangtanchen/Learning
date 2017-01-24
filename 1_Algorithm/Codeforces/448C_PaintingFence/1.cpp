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
const int MAXN=5010;
const int INF=0x3f3f3f3f;
int a[MAXN];
int N;
int dp[2][MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

    scanf("%d",&N);
    for(int ni=0;ni<N;ni++){
         scanf("%d",a+ni);
    }
    int now=0,la=1;
    memset(dp,0x3f,sizeof(dp));
    dp[la][0]=0;
    for(int i=0;i<=N;i++){
        memset(dp[now],0x3f,sizeof(dp[now]));
        for(int j=0;j<=N;j++){
            int k=min(j,a[i]);
            dp[now][k]=min(dp[now][k],dp[la][j]+1);
            if(a[i]<=N){
                 dp[now][a[i]]=min(dp[now][a[i]],dp[la][j]+max(0,a[i]-j));
            }
        }
        swap(la,now);
    }
    printf("%d\n",dp[la][0]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
