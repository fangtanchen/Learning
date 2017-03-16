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

int N,Q;
int pa[MAXN],w[MAXN],down[MAXN],up[MAXN],ma[MAXN],mi[MAXN],ans[MAXN];
bool vis[MAXN];
pii qu[MAXN];
vector<int> a[MAXN];
vector<int> G[MAXN];

struct Edge{
     int to,id;
};
vector<Edge> q[MAXN];

int Find(int x){
    if(x==pa[x])return x;
    int y=pa[x];
    pa[x]=Find(y);
    down[x]=max(max(down[x],down[y]),ma[x]-mi[y]);
    up[x]=max(max(up[x],up[y]),ma[y]-mi[x]);
    ma[x]=max(ma[x],ma[y]);
    mi[x]=min(mi[x],mi[y]);
    return pa[x];
}



void DFS(int u){
    vis[u]=true;
    ma[u]=mi[u]=w[u];
    up[u]=down[u]=0;
    for(int i=0;i<q[u].size();i++){
        Edge r=q[u][i];
        int v=r.to;
        if(vis[v]){
            int y=Find(v);
            a[y].push_back(r.id);
        }
    }
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!vis[v]){
            DFS(v);
            pa[v]=u;
        }
    }
    for(int i=0;i<a[u].size();i++){
         int id=a[u][i];
         int x=qu[id].first,y=qu[id].second;
         Find(x);Find(y);
         ans[id]=max(max(up[x],down[y]),ma[y]-mi[x]);
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
         scanf("%d",w+i);
         pa[i]=i;
    }
    for(int i=1;i<N;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        qu[i].first=u;qu[i].second=v;
        Edge r;
        r.to=v;r.id=i;
        q[u].push_back(r);
        r.to=u;
        q[v].push_back(r);
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
