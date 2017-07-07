#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;
typedef pair<int,int> pii;

int pa[MAXN],k[MAXN];
int depth[MAXN],out[MAXN],pre[MAXN];
int N;
vector<int> G[MAXN];
queue<int> Q;
bool vis[MAXN];


void DFS(int u,int fa,int di){
    depth[u]=di;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        DFS(v,u,di+1);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    memset(out,0,sizeof(out));
    memset(depth,0,sizeof(depth));
    memset(vis,false,sizeof(vis));
    pa[1]=0;
    depth[0]=-10000000;
    vis[0]=true;
    for(int i=2;i<=N;i++){
         scanf("%d",pa+i);
         out[pa[i]]++;
         G[pa[i]].push_back(i);
    }
    for(int i=1;i<=N;i++){
        scanf("%d",k+i);
    }
    DFS(1,0,1);
    for(int i=1;i<=N;i++){
        pre[i]=depth[i]-k[i];
        if(!out[i]){
            Q.push(i);
        }
    }
    int ans=0;
    while(!Q.empty()){
        int u=Q.front();
         Q.pop();
         if(vis[u])continue;
         ans++;
         int v=u;
         while(depth[v]>pre[u]){
             vis[v]=true;
             v=pa[v];
         }
         if(!vis[v])
             Q.push(v);
    }
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
