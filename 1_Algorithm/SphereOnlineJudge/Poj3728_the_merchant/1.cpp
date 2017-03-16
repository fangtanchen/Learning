#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=5e4+10;
typedef pair<int,int> pii;


int N,Q,w[MAXN],up[MAXN],down[MAXN],ma[MAXN],mi[MAXN];
int pa[MAXN];
int ans[MAXN];
vector<int> G[MAXN],a[MAXN];
bool vis[MAXN];

struct Edge{
    int to,id;
    Edge(){
        to=id=0;
    }
};

vector<Edge> q[MAXN];

pii qu[MAXN];


int Find(int u){
    if(pa[u]==u)return u;
    int fa=pa[u];
    pa[u]=Find(pa[u]);
    up[u]=max(max(up[u],up[fa]),ma[fa]-mi[u]);
    down[u]=max(max(down[u],down[fa]),ma[u]-mi[fa]);
    ma[u]=max(ma[u],ma[fa]);
    mi[u]=min(mi[u],mi[fa]);
    return pa[u];
}

void DFS(int u){
    vis[u]=true;
    ma[u]=mi[u]=w[u];
    down[u]=up[u]=0;

    for(int i=0;i<q[u].size();i++){
        Edge r=q[u][i];
        int v=r.to;
        if(!vis[v])continue;
        int y=Find(v);
        a[y].push_back(r.id);
    }

    for(int i=0;i<G[u].size();i++) {
         int v=G[u][i];
         if(vis[v])continue;
         DFS(v);
         pa[v]=u;
    }

    for(int i=0;i<a[u].size();i++){
         int id=a[u][i];
         int u=qu[id].first,v=qu[id].second;
         Find(u),Find(v);
         ans[id]=max(max(up[u],down[v]),ma[v]-mi[u]);
         ans[id]=max(0,ans[id]);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
         scanf("%d",&w[i]);
         pa[i]=i;
    }
    for(int i=1;i<N;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin>>Q;
    for(int i=1;i<=Q;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        Edge r;
        r.to=v;r.id=i;
        q[u].push_back(r);
        r.to=u;r.id=i;
        q[v].push_back(r);
        qu[i].first=u,qu[i].second=v;
    }
    memset(vis,false,sizeof(vis));
    DFS(1);
    for(int i=1;i<=Q;i++){
        printf("%d\n",ans[i]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
