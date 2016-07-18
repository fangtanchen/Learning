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
const int MAXN=1010;
const int MAXV=1e8;
const int MAXM=1e4+10;

bool vis[MAXN];
int dp[MAXN][MAXN];
int N,M,S,T;
void Init(){

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dp[i][j]=MAXV;
        }
    }
    memset(vis,false,sizeof(vis));
}

void Dijkstra(int si,int di){
    vis[si]=true;
    int mini=-1,minv=MAXV;
    do{
        mini=-1,minv=MAXV;
        for(int i=1;i<=N;i++){
            if((!vis[i])&&(dp[si][i]!=MAXV)){
                if(dp[si][i]<minv){
                    minv=dp[si][i];
                    mini=i;
                }
            }
        }
        if(mini==-1)break;
        vis[mini]=true;
        for(int i=1;i<=N;i++){
            if((!vis[i])&&(dp[mini][i]!=MAXV)){
                int tmp=dp[si][mini]+dp[mini][i];
                if(tmp<dp[si][i])dp[si][i]=tmp;
            }
        }
    }while(mini!=di);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M>>S>>T;
    Init();
    for(int i=0;i<M;i++){
         int u,v,len;
         cin>>u>>v>>len;
         if(len<dp[u][v]){
             dp[u][v]=dp[v][u]=len;
         }
    }
    Dijkstra(S,T);
    cout<<dp[S][T]<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
