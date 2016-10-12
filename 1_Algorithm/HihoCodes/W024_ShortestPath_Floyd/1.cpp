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
const int INF=1e8;

int dp[MAXN][MAXN];
int N,M;

void Init(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dp[i][j]=INF;
        }
        dp[i][i]=0;
    }
}

void Floyd(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            if(i==k)continue;
            for(int j=1;j<=N;j++){
                if((i==j)||(k==j))continue;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
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
    cin>>N>>M;
    Init();
    for(int i=0;i<M;i++){
         int u,v,len;
         cin>>u>>v>>len;
         if(len<dp[u][v]){
             dp[u][v]=dp[v][u]=len;
         }
    }
    Floyd();
    for(int i=1;i<=N;i++){
        cout<<dp[i][1];
        for(int j=2;j<=N;j++){
            cout<<" "<<dp[i][j];
        }
        cout<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
