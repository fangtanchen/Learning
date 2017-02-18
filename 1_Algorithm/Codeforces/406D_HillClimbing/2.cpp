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
typedef pair<int,int> pii;

const int MAXN=2e5;
double x[MAXN],y[MAXN];
int u[MAXN],v[MAXN],N,Q;
int stk[MAXN],top;

vector<int> G1[MAXN],G2[MAXN];
map<pii,int> mp;
bool vis[MAXN];
int pa[MAXN];

void Init(){
    mp.clear();
    for(int i=0;i<MAXN;i++)
        G1[i].clear(),G2[i].clear();
    memset(vis,false,sizeof(vis));
}

int Find(int u){
    if(u==pa[u])return u;
    pa[u]=Find(pa[u]);
    return pa[u];
}

void Tarjan(int u){
    pa[u]=u;vis[u]=true;
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
            pa[v]=u;
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
         scanf("%lf%lf",x+i,y+i);
    }
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++){
        scanf("%d%d",u+i,v+i);
        G2[u[i]].push_back(v[i]);
        G2[v[i]].push_back(u[i]);
    }

    top=0;
    stk[top]=N;
    stk[++top]=N;
    for(int i=N-1;i;i--){
        while(top>=2){
            if((x[stk[top-1]]-x[i])*(y[stk[top]]-y[i])
                        -(x[stk[top]]-x[i])*(y[stk[top-1]]-y[i])>=0){
                break;
            }
            top--;
        }
        G1[i].push_back(stk[top]);
        G1[stk[top]].push_back(i);
        stk[++top]=i;
    }
    Tarjan(N);
    for(int i=1;i<=Q;i++){
         printf("%d ",mp[make_pair(u[i],v[i])]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
