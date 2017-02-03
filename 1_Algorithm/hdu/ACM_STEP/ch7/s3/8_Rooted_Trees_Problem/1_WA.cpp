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
const int MAXN=41;

typedef long long int ll;
ll dp[2][MAXN][MAXN][MAXN];
ll ans[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    memset(ans,0,sizeof(ans));
    ans[1]=ans[2]=1;
    for(int ni=3;ni<=40;ni++){
        ans[ni]+=ans[ni-1];
        memset(dp,0,sizeof(dp));
        int now=0,la=1;
        for(int j=1;j<ni;j++){
            dp[now][j][j][1]=ans[j];
        }
        for(int i=2;i<ni;i++){
            swap(now,la);
            memset(dp[now],0,sizeof(dp[now]));
            for(int j=1;j<ni;j++){
                for(int t=1;t<=j;t++){
                    for(int l=1;l*t<=j;l++){
                        if(dp[la][j][t][l]==0)continue;
                        int kmax=ni-j;
                        for(int k=t+1;k<kmax;k++){
                            dp[now][j+k][k][1]+=dp[la][j][t][l]*ans[k];
                        }
                        if(j+t<ni)
                            dp[now][j+t][t][l+1]+=dp[la][j][t][l]*ans[t];
                    }
                }
            }
            for(int t=1;t<ni;t++)
                for(int l=1;l*t<ni;l++){
                    ll tmp=dp[now][ni-1][t][l];
                    for(int p=2;p<l;p++){
                         tmp/=p;
                    }
                    ans[ni]+=tmp;
                };

        }
    }
    int n;
    while(EOF!=scanf("%d",&n)){
         printf("%lld\n",ans[n]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
