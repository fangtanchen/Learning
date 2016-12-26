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
const int MAXN=5005;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int dp[MAXN];
int cnt[MAXN];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    memset(cnt,0,sizeof(cnt));
    memset(dp,0x3f,sizeof(dp));
    for(int ni=1;ni<N;ni++){
         int a;
         scanf("%d",&a);
         cnt[a]++;
    }
    dp[1]=0;
    for(int ni=1;ni<=N;ni++){
        for(int ki=N;ki>=1;ki--){
            int tmp=ki+cnt[ni];
            dp[tmp]=min(dp[tmp],dp[ki]+1);
        }
    }
    printf("0");
    for(int ki=2;ki<=N;ki++){
         if(dp[ki]==INF)printf(" -1");
         else{
              printf(" %d",dp[ki]);
         }
    }
    printf("\n");


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
