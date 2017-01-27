#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef long long int LL;
const int MAXN=30;
const int MAXH=220;

LL dp[MAXN][MAXH];
LL fish[MAXN][MAXH];
LL pre[MAXN][MAXH];

LL T,N,H;
LL f[MAXN],d[MAXN],t[MAXN];
vector<int> ans;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%lld",&T);
    for(int ti=1;ti<=T;ti++){
         printf("Case %d:\n",ti);
         scanf("%d%d",&N,&H);
         H*=12;
         for(int i=1;i<=N;i++){
             scanf("%d",f+i);
         }
         for(int i=1;i<=N;i++){
             scanf("%d",d+i);
         }
         for(int i=2;i<=N;i++){
             scanf("%d",t+i);
         }
         memset(fish,0,sizeof(fish));
         for(int ni=1;ni<=N;ni++){
             for(int hi=1;hi<=H;hi++){
                 fish[ni][hi]=max((LL)0,f[ni]-(hi-1)*d[ni]);
             }
             for(int hi=1;hi<=H;hi++){
                 fish[ni][hi]+=fish[ni][hi-1];
             }
         }
         memset(dp,-1,sizeof(dp));
         memset(pre,-1,sizeof(pre));
         for(int hi=0;hi<=H;hi++)dp[1][hi]=fish[1][hi];
         for(int ni=2;ni<=N;ni++){
             for(int hi=0;hi<=H;hi++){
                 for(int ki=0;ki<=hi;ki++){
                     if(hi-ki-t[ni]<0)break;
                     if(dp[ni-1][hi-ki-t[ni]]<0)continue;
                     LL tmp=dp[ni-1][hi-ki-t[ni]]+fish[ni][ki];
                     if(tmp>dp[ni][hi]){
                          dp[ni][hi]=tmp;
                          pre[ni][hi]=ki;
                     }
                 }
             }
         }
         int ansi=1;
         for(int i=1;i<=N;i++){
              if(dp[i][H]>=0 && dp[i][H]>dp[ansi][H])ansi=i;
         }
         ans.clear();
         int tmph=H;
         for(int i=ansi;i>=2;i--){
             ans.push_back(pre[i][tmph]);
             tmph=tmph-pre[i][tmph]-t[i];
         }
         ans.push_back(tmph);
         reverse(ans.begin(),ans.end());
         while(ans.size()<N)ans.push_back(0);
         for(int i=0;i<ans.size();i++){
              if(i==0)printf("%d",ans[i]*5);
              else printf(", %d",ans[i]*5);
         }
         printf("\nNumber of fish expected: %lld\n",dp[ansi][H]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
