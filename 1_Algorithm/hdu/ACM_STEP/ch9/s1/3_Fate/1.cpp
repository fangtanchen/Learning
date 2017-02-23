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
const int MAXN=110;
int dp[MAXN][MAXN];
int A[MAXN],B[MAXN];
int N,M,K,S;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    while(EOF!=scanf("%d%d%d%d",&N,&M,&K,&S)){
        for(int ki=1;ki<=K;ki++){
            scanf("%d%d",A+ki,B+ki);
        }
        memset(dp,0,sizeof(dp));
        int st=0,ed=1;
        int ans=-1;
        for(int ki=1;ki<=K;ki++){
            for(int mi=B[ki];mi<=M;mi++){
                for(int si=1;si<=S;si++){
                    dp[mi][si]=max(dp[mi][si],dp[mi-B[ki]][si-1]+A[ki]);
                    if(dp[mi][si]>=N){
                         ans=max(ans,M-mi);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
