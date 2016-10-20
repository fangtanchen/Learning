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
const int MAXN=10050;
const int INF=0x3f3f3f3f;

int dp[MAXN];
int T,E,F,N,P[1000],W[1000];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         scanf("%d%d",&E,&F);
         F-=E;
         scanf("%d",&N);
         for(int i=0;i<N;i++){
             scanf("%d%d",P+i,W+i);
         }
         memset(dp,0x3f,sizeof(dp));
         for(int i=0;i<N;i++){
             dp[W[i]]=min(dp[W[i]],P[i]);
             for(int j=W[i]+1;j<=F;j++){
                 if(dp[j-W[i]]==INF)continue;
                 dp[j]=min(dp[j-W[i]]+P[i],dp[j]);
             }
         }
         if(dp[F]==INF){
              printf("This is impossible.\n");
         }else{
             printf("The minimum amount of money in the piggy-bank is %d.\n",dp[F]);
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
