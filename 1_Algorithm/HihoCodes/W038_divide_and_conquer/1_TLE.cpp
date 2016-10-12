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
const int MAXN=10010;
const int MAXM=2e5+10;
const int INF=0x7f7f7f7f;

int first[MAXN];
int to[MAXM];
int adj[MAXM];
int dist[MAXM];
int top;

int N,M,K,T;
bool vis[MAXN];
int result;

void Init(){
     memset(first,-1,sizeof(first));
     memset(to,-1,sizeof(to));
     memset(adj,-1,sizeof(adj));
     memset(dist,0x7f,sizeof(dist));
     top=0;

     result=INF;
     memset(vis,false,sizeof(vis));
}

void Add(int u,int v,int d){
     adj[top]=first[u];
     to[top]=v;
     dist[top]=d;
     first[u]=top++;
}

int DFS(int u,int dest,int cost,int depth){
    if(depth>K)return 0;
    if(cost>result)return 0;
    if((u==dest)){
        result=cost;
        return 0;
    }
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        int w=dist[pos];
        if(vis[v])continue;
        vis[v]=true;
        DFS(v,dest,max(w,cost),depth+1);
        vis[v]=false;
    }
    return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    Init();
    cin>>N>>M>>K>>T;
    for(int i=0;i<M;i++){
         int u,v,w;
         cin>>u>>v>>w;
         Add(u,v,w);
         Add(v,u,w);
    }

    DFS(1,T,0,0);
    cout<<result<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
