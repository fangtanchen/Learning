#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=5e6;
const int MAXM=(1<<14)+10;

int f[MAXM];
int dp[MAXN];//-2: not certificate;  -1: not init    1,2,3...: i-certificate
int ans[MAXN];
int fac[20];
int n;


void Init(){
    memset(f,0,sizeof(f));
    memset(dp,-1,sizeof(dp));
    memset(ans,0,sizeof(ans));
    fac[0]=1;
    for(int i=1;i<20;i++){
        fac[i]=fac[i-1]*3;
    }

    for(int i=0;i<MAXM;i++){
        int digit[20];
        int dlen=0;
        memset(digit,0,sizeof(digit));
        int tmpi=i;
        while(tmpi){
            digit[dlen]=tmpi%2;
            tmpi/=2;
            dlen++;
        }
        for(int di=dlen-1;di>=0;di--){
            f[i]=3*f[i]+digit[di];
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&n);
    Init();
    int imax=1<<n;
    for(int i=0;i<imax;i++){
        scanf("%1d",&dp[f[i]]);
    }

    imax=pow(3,n);
    for(int k=0;k<n;k++){
         for(int i=0;i<imax;i++){
             if(-1==dp[i])continue;
             int pp=(i/fac[k])%3;
             if(pp==2)continue;
             int a=i+(2-pp)*fac[k];
             if(dp[a]==-1){
                  dp[a]=dp[i];
             }else if(dp[a]!=dp[i]){
                 dp[a]=-2;
             }
         }
    }



    imax=pow(3,n);
    for(int i=imax-1;i>=0;i--){
        for(int k=0;k<n;k++) {
            int pp=(i/fac[k])%3;
            if(pp<2)ans[i]++;
        }
    }

    for(int i=imax-1;i>=0;i--){
        for(int k=0;k<n;k++) {
            if(-2==dp[i])continue;
            int pp=(i/fac[k])%3;
            if(pp<2)continue;
            int a=i-pp*fac[k];
            for(int pi=0;pi<2;pi++){
                int tmpa=a+pi*fac[k];
                ans[tmpa]=min(ans[tmpa],ans[i]);
            }
        }
    }

    imax=1<<n;
    printf("%d",ans[f[0]]);
    for(int i=1;i<imax;i++){
         printf(" %d",ans[f[i]]);
    }
    printf("\n");


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
