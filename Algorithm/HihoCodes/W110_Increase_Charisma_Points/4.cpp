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
const int MAXS=31;
const int MAXN=105;
const int MAXM=1e9+10;
const int INF=0x3f3f3f3f;

int N,M;
int dp[MAXS][MAXN][MAXN];
int dist[MAXN];
int newDist[MAXN];
int fac2[MAXS];


void Init(){
    memset(dp,0x3f,sizeof(dp));
    memset(dist,0,sizeof(dist));
    memset(newDist,0x3f,sizeof(newDist));
    fac2[0]=1;
    for(int i=1;i<MAXS;i++){
         fac2[i]=fac2[i-1]*2;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    Init();
    for(int si=1;si<=N;si++){
        for(int di=1;di<=N;di++){
            cin>>dp[0][si][di];
        }
        dp[0][si][si]=INF;
    }
    for(int chi=1;chi<MAXS;chi++){
        for(int si=1;si<=N;si++){
            for(int di=1;di<=N;di++){
                for(int ki=1;ki<=N;ki++){
                    int tmp=dp[chi-1][si][ki]+dp[chi-1][ki][di];
                    if(tmp<dp[chi][si][di])dp[chi][si][di]=tmp;
                }
            }
        }
    }
    int ans=0;
    for(int chi=MAXS-1;chi>=0;chi--){
        memset(newDist,0x3f,sizeof(newDist));
        for(int si=1;si<=N;si++){
            for(int di=1;di<=N;di++){
                int tmp=dist[si]+dp[chi][si][di];
                if(tmp<newDist[di])newDist[di]=tmp;
            }
        }

        bool flag=false;
        for(int i=1;i<=N;i++){
            if(newDist[i]<=M){
                flag=true;
                break;
            }
        }


        if(flag){
            for(int i=1;i<=N;i++){
                dist[i]=newDist[i];
            }
            ans+=fac2[chi];
        }
    }
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
