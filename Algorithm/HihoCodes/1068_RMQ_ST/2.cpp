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
const int MAXN=1000010;
const int MAXP=1000010;

int N,Q;
int weight[MAXN];
int fac[25];
int dp[MAXN][25];

void Init(){
     fac[0]=1;
     for(int i=1;i<25;i++)
         fac[i]=2*fac[i-1];
     memset(weight,0,sizeof(weight));
     memset(dp,0,sizeof(dp));
}
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",dp[i]);
    }
    for(int k=1;k<25;k++){
        for(int i=N-fac[k]+1;i>=0;i--){
            dp[i][k]=min(dp[i][k-1],dp[i+fac[k-1]][k-1]);
        }
    }
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++){
         int a,b;
         scanf("%d%d",&a,&b);
         int d=b-a+1;
         int k;
         for(k=0;fac[k]<=d;k++);
         k--;
         int ans=min(dp[a][k],dp[b-fac[k]+1][k]);
         printf("%d\n",ans);

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
