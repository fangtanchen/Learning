#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<utility>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=200;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;

vector<pii> G[MAXN];
int N,M;
bool bEdge[MAXN][MAXN];



void Dijkstra(int st,int ed){
    bool vis[MAXN];
    int dist[MAXN];
    int path[MAXN];
    memset(dist,0x3f,sizeof(dist));
    memset(path,0,sizeof(path));
    memset(vis,false,sizeof(vis));
    dist[st]=0;
    path[st]=st;
    do{
        int mini=-1,minv=INF;
        for(int i=1;i<=N;i++){
            if(vis[i])continue;
            if(minv>dist[i]){
                mini=i;
                minv=dist[i];
            }
        }
        if(mini==-1)break;
        vis[mini]=true;
        bEdge[mini][path[mini]]=bEdge[path[mini]][mini]=false;
        for(int i=G[mini].size()-1;i>=0;i--){
             int v=G[mini][i].first;
             if(vis[v])continue;
             int c=G[mini][i].second;
             int tmp=dist[mini]+c;
             if(tmp<dist[v]){
                  path[v]=mini;
                  dist[v]=tmp;
             }
        }
    }while(1);
    return;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    memset(bEdge,false,sizeof(bEdge));
    for(int mi=0;mi<M;mi++){
         int u,v,c;
         scanf("%d%d%d",&u,&v,&c);
         G[u].push_back(make_pair(v,c));
         G[v].push_back(make_pair(u,c));
         bEdge[u][v]=bEdge[v][u]=true;
    }
    for(int ni=1;ni<=N;ni++){
         Dijkstra(ni,-1);
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(bEdge[i][j])ans++;
        }
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
