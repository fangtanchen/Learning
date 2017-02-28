#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=515;
const int MAXM=2e4+10;
const int INF=0x3f3f3f3f;

int N,M;
int cf[MAXN][MAXN];
vector<int> G[MAXN];
int path[MAXN],pathi;
bool vis[MAXN];


int FindAugmentPath(int st,int ed){
    pathi=0;
    memset(vis,false,sizeof(vis));
    memset(path,-1,sizeof(path));
    queue<int> Q;
    Q.push(st);
    while(!Q.empty()){
        int u=Q.front();
        if(u==ed)break;
        Q.pop();
        vis[u]=true;
        for(int i=0;i<G[u].size();i++){
             int v=G[u][i];
             if(vis[v])continue;
             if(cf[u][v]<=0)continue;
             path[v]=u;
             Q.push(v);
        }
    }
    int ret=INF;
    if(path[ed]==-1)return 0;
    int u=ed;
    while(u!=st){
        ret=min(ret,cf[path[u]][u]);
        u=path[u];
    }

    return ret;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    memset(cf,0,sizeof(cf));
    for(int mi=0;mi<M;mi++){
         int u,v,w;
         scanf("%d%d%d",&u,&v,&w);
         G[u].push_back(v);
         cf[u][v]+=w;
    }
    int ans=0;
    int k;
    while((k=FindAugmentPath(1,N)),k>0){
         ans+=k;
         int u=N;
         while(u!=1){
             cf[path[u]][u]-=k;
              u=path[u];
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
