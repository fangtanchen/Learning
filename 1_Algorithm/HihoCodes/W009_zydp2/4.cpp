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
const int MAXN=1005;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;

int dp[MAXN][MAXM][MAXS];
int N,M;
int fac[20];


void Solve(){
    fac[0]=1;
    for(int i=1;i<20;i++){
        fac[i]=2*fac[i-1];
    }
    memset(dp,0,sizeof(dp));
    int rimax=N-1,cimax=M-1;
    int simax=(1<<(2*M))-1;
    for(int si=0;si<MAXS;si++){
        dp[rimax+1][0][si]=1;
    }
    for(int ri=rimax;ri>=0;ri--){
        for(int ci=cimax;ci>=0;ci--){
            for(int si=simax;si>=0;si--){
                if(((si&fac[ci]))){
                    if(ci==cimax){
                        dp[ri][ci][si]=dp[ri+1][0][si/fac[M]];
                    }else{
                        dp[ri][ci][si]=dp[ri][ci+1][si];
                    }
                }else{
                    if((ri==rimax)||(si&(fac[ci+M]))){
                        if((ci==cimax)||((si&(fac[ci+1])))){
                            dp[ri][ci][si]=0;
                        }else{
                            dp[ri][ci][si]=dp[ri][ci][si|fac[ci]|fac[ci+1]];
                        }
                    }else{
                        if((ci==cimax)||((si&(fac[ci+1])))){
                            dp[ri][ci][si]=dp[ri][ci][si|fac[ci]|fac[ci+M]];
                        }else{
                            dp[ri][ci][si]=(dp[ri][ci][si|fac[ci]|fac[ci+M]]
                                +dp[ri][ci][si|fac[ci]|fac[ci+1]])%MOD;
                        }
                    }
                }
            }
        }
    }

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>M;
    Solve();
    printf("%d\n",dp[0][0][0]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
