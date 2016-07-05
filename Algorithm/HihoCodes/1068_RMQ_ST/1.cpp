#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1000010;
const int MAXQ=1000010;
int N,Q;
int dp[MAXN][25];
int fac[25];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    fac[0]=1;
    for(int i=1;i<25;i++){
         fac[i]=2*fac[i-1];
    }
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
         scanf("%d",dp[i]);
    }

    int kmax=0;
    for(;fac[kmax]<=N;kmax++);

    for(int k=1;k<kmax;k++){
        for(int i=N-fac[k]+1;i>=1;i--){
            dp[i][k]=min(dp[i][k-1],dp[i+fac[k-1]][k-1]);
        }
    }

    scanf("%d",&Q);
    int L,R;
    while(Q--){
         scanf("%d%d",&L,&R);
         if(R>N)R=N;
         if(L<1)L=1;
         double delta=(double)R-L+1;
         int kmax=(int)(log((double)delta)/log(2.0));
         int ans=min(dp[L][kmax],dp[R-fac[kmax]+1][kmax]);
         printf("%d\n",ans);
    }
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
