#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MEM(x,a) memset(x,a,sizeof(x))
const int MAXN=2e4+10;
const int MAXM=1e5+10;
const int MAXS=4;

int first[MAXS][MAXN],adj[MAXS][MAXM],to[MAXS][MAXM],top[MAXS];
int sta[MAXN],tag[MAXN],parent[MAXN],indegree[MAXN];
int low[MAXN],dfn[MAXN];
bool vis[MAXN],instack[MAXN];
int N,M;
long long int weight[MAXN],newweight[MAXN];
int tag_cnt=0;
queue<int> Q;


void Init(){
    MEM(first,-1);
    MEM(adj,-1);
    MEM(to,-1);
    MEM(top,0);

    MEM(sta,0);
    MEM(tag,-1);
    MEM(parent,-1);
    MEM(vis,false);
    MEM(indegree,0);
    MEM(newweight,0);
}

void Add(int u,int v,int c){
     adj[c][top[c]]=first[c][u];
     to[c][top[c]]=v;
    first[c][u]=top[c]++;
}


void Tarjan(int u){
    static int counter=1;
    low[u]=dfn[u]=counter++;
    vis[u]=true;
    instack[u]=true;
    sta[++sta[0]]=u;
    for(int pos=first[0][u];pos!=-1;pos=adj[0][pos]){
         int v=to[0][pos];
         if(!vis[v]){
             Tarjan(v);
             low[u]=min(low[u],low[v]);
         }else if(instack[v]){
             low[u]=min(low[u],dfn[v]);
         }
    }
    if(low[u]==dfn[u]){
        tag_cnt++;
         int p;
         do{
             p=sta[sta[0]];
             sta[0]--;
             instack[p]=false;
             tag[p]=tag_cnt;
             newweight[tag_cnt]+=weight[p];
         }while(p!=u);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);
    for(int ni=1;ni<=N;ni++){
         scanf("%lld",weight+ni);
    }
    for(int mi=0;mi<M;mi++){
        int u,v;
        scanf("%d%d",&u,&v);
        Add(u,v,0);
    }
    Tarjan(1);
    for(int ni=1;ni<=N;ni++){
        int u=tag[ni];
        if(-1!=u){
            for(int pos=first[0][ni];pos!=-1;pos=adj[0][pos]){
                int v=tag[to[0][pos]];
                if(v!=u){
                     Add(u,v,1);
                }
            }
        }
    }
    for(int ni=1;ni<=tag_cnt;ni++){
        {
            MEM(vis,false);
            for(int pos=first[1][ni];pos!=-1;pos=adj[1][pos]){
                int v=to[1][pos];
                if((!vis[v]) ){
                    vis[v]=true;
                    Add(ni,v,2);
                    Add(v,ni,3);
                    indegree[v]++;
                }
            }
        }
    }
    Q.push(tag[1]);
    long long ans=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        long long W=0;
        for(int pos=first[3][u];pos!=-1;pos=adj[3][pos]){
            int v=to[3][pos];
            W=max(W,newweight[v]);
        }
        newweight[u]+=W;
        ans=max(ans,newweight[u]);

        for(int pos=first[2][u];pos!=-1;pos=adj[2][pos]){
            int v=to[2][pos];
            indegree[v]--;
            if(0==indegree[v]){
                 Q.push(v);
            }
        }
    }
    printf("%lld\n",ans);



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
