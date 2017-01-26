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
typedef long long int ll;
const int MAXN=105;
const int MODU=1e9+7;

long long int dp[MAXN][MAXN],fac[MAXN];
char op[MAXN];
int N;


ll ModExp(ll a,ll b,ll p){
    ll ret=1;
    while(b){
        if(1&b){
            ret=(ret*a)%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    fac[1]=1;
    for(int i=2;i<MAXN;i++){
         fac[i]=fac[i-1]*i%MODU;
    }
    while(EOF!=scanf("%d",&N)){
        memset(dp,0,sizeof(dp));
        for(int ni=1;ni<=N;ni++){
            scanf("%lld",dp[ni]+ni);
        }
        scanf("%s",op+1);
        for(int di=1;di<N;di++){
            int imax=N-di;
            for(int i=1;i<=imax;i++){
                int j=i+di;
                int kmax=i+di-1;
                for(int k=i;k<=kmax;k++){
                    switch(op[k]){
                        case '+':
                            dp[i][j]+=dp[i][k]+dp[k+1][j];
                            break;
                        case '-':
                            dp[i][j]+=dp[i][k]-dp[k+1][j];
                            break;
                        case '*':
                            dp[i][j]+=dp[i][k]*dp[k+1][j];
                            break;
                        default:
                            break;
                    }
                    dp[i][j]%=MODU;
                }
                dp[i][j]=(dp[i][j]*ModExp(di,MODU-2,MODU))%MODU;
                if(dp[i][j]<0)dp[i][j]+=MODU;
            }
        }
        printf("%lld\n",dp[1][N]*fac[N-1]%MODU);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
