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
const int MAXN=304;
const int MAXQ=1e6+10;
const int MAXL=9;
int m,n;
int dp[MAXN][MAXN][MAXL][MAXL];
int fac[MAXL];

void Init(){
    fac[0]=1;
    for(int i=1;i<MAXL;i++){
        fac[i]=2*fac[i-1];
    }
}

void RMQ(){
    for(int h=1;h<MAXL;h++){
        for(int ri=1;ri<=m;ri++){
            for(int ci=n-fac[h]+1;ci>=1;ci--){
                dp[ri][ci][0][h]=max(dp[ri][ci][0][h-1],dp[ri][ci+fac[h-1]][0][h-1]);
            }
        }
    }
    for(int h=1;h<MAXL;h++){
        for(int ri=m-fac[h]+1;ri>=1;ri--){
            for(int ci=n;ci>=1;ci--){
                dp[ri][ci][h][0]=max(dp[ri][ci][h-1][0],dp[ri+fac[h-1]][ci][h-1][0]);
            }
        }
    }
    for(int l=1;l<MAXL;l++){
        for(int h=1;h<MAXL;h++){
            for(int ri=m-fac[l]+1;ri>=1;ri--){
                for(int ci=n-fac[h]+1;ci>=1;ci--){
                    dp[ri][ci][l][h]=max(
                             max(dp[ri][ci][l-1][h-1],dp[ri][ci+fac[h-1]][l-1][h-1]),
                             max(dp[ri+fac[l-1]][ci][l-1][h-1],dp[ri+fac[l-1]][ci+fac[h-1]][l-1][h-1])
                            );
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
    cin.sync_with_stdio(false);
    Init();
    while(cin>>m>>n){
        memset(dp,0,sizeof(dp));
        for(int ri=1;ri<=m;ri++){
            for(int ci=1;ci<=n;ci++){
                cin>>dp[ri][ci][0][0];
            }
        }
        RMQ();
        int r1,r2,c1,c2;
        int q;
        cin>>q;
        while(q--){
             cin>>r1>>c1>>r2>>c2;
             int dr=r2-r1+1;
             int dc=c2-c1+1;
             int kr=0,kc=0;
             int tmp=dr;
             while(tmp/2){
                 tmp/=2;
                 kr++;
             }
             tmp=dc;
             while(tmp/2){
                  tmp/=2;
                  kc++;
             }
             tmp=max(
                     max(dp[r1][c1][kr][kc],dp[r1][c2-fac[kc]+1][kr][kc]),
                     max(dp[r2-fac[kr]+1][c1][kr][kc],dp[r2-fac[kr]+1][c2-fac[kc]+1][kr][kc])
                     );
             cout<<tmp;
             if((tmp==dp[r1][c1][0][0])||(tmp==dp[r1][c2][0][0])||
                     (tmp==dp[r2][c1][0][0])||(tmp==dp[r2][c2][0][0])){
                 cout<<" yes\n";
             }else{
                 cout<<" no\n";
             }

        }
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
