#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<vector>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=2e5+10;

int n,m;
double x[MAXN],y[MAXN];
int u[MAXN],v[MAXN];
int stk[MAXN*2],top;

map<pair<int,int>,int> mp;
vector<int> G1[MAXN],G2[MAXN];
int fa[MAXN];
bool vis[MAXN];

void Init(){
     mp.clear();
     for(int i=0;i<MAXN;i++)G1[i].clear(),G2[i].clear();
     memset(vis,false,sizeof(vis));
}


int Find(int x){
    return x==fa[x]? x: fa[x]=Find(fa[x]);
}

void Tarjan(int u){
    fa[u]=u;vis[u]=true;
    for(int i=0;i<G2[u].size();i++){
        int v=G2[u][i];
        if(vis[v]){
            mp[make_pair(u,v)]=mp[make_pair(v,u)]=Find(v);
        }
    }

    for(int i=0;i<G1[u].size();i++){
        int v=G1[u][i];
        if(!vis[v]){
            Tarjan(v);
            fa[v]=u;
        };
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",x+i,y+i);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",u+i,v+i);
        G2[u[i]].push_back(v[i]);
        G2[v[i]].push_back(u[i]);
    }
    top=0;
    stk[top]=n;
    for(int i=n;i;i--){
        while(top>=1){
            double k1=(y[i]-y[stk[top-1]])/(x[i]-x[stk[top-1]]);
            double k2=(y[i]-y[stk[top]])/(x[i]-x[stk[top]]);
            if(k1<=k2)break;
            top--;
        }
        if(top>=1){
            G1[stk[top]].push_back(i);
            G1[i].push_back(stk[top]);
        }
        stk[++top]=i;
    }
    Tarjan(n);
    for(int i=1;i<=m;i++){
         printf("%d ",mp[make_pair(u[i],v[i])]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
