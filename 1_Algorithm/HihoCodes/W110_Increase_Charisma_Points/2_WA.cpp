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
typedef unsigned int ull ;
const ull MAXS=31;
const ull MAXN=105;
const ull MAXM=1e9+10;
const ull INF=0xffffffff;
ull fac2[MAXS+2];
ull dp[MAXS][MAXN][MAXN];
ull dist[MAXN];
ull newDist[MAXN];
ull N,M;

void Init(){
     memset(dist,0,sizeof(dist));
     for(int i=0;i<=MAXS;i++){
         fac2[i]=1<<i;
     }
     memset(dp,0xff,sizeof(dp));
     memset(newDist,0xff,sizeof(newDist));
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    Init();
    cin>>N>>M;
    for(int si=1;si<=N;si++){
        for(int di=1;di<=N;di++){
            cin>>dp[0][si][di];
        }
    }
    for(int chi=1;chi<MAXS;chi++){
        for(int si=1;si<=N;si++) {
            for(int di=1;di<=N;di++){
                for(int ki=1;ki<=N;ki++){
                    if((chi==1)&&((si==ki)||(di==ki)))continue;;
                    dp[chi][si][di]=min(dp[chi][si][di],
                            dp[chi-1][si][ki]+dp[chi-1][ki][di]);
                }
            }
        }
    }
    ull ans=0;
    for(int chi=MAXS-1;chi>=0;chi--){
        memset(newDist,0xff,sizeof(newDist));
        for(int di=1;di<=N;di++){
            for(int ki=1;ki<=N;ki++){
                if((!chi)&&(ki==di))continue;
                ull tmp=dist[ki]+dp[chi][ki][di];
               // if((di!=ki)&&(newDist[di]>tmp)){
                if(newDist[di]>tmp){
                    newDist[di]=tmp;
                }
            }
        }
        bool flag=false;
        for(int i=1;i<=N;i++){
            if(newDist[i]<=M){
                flag=true;
                dist[i]=newDist[i];
            }
        }
        if(flag){
            ans+=fac2[chi];
        }
    }
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
