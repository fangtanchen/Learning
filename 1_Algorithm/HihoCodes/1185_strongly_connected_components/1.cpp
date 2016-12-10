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
#define MEM(x,a) memset(x,a,sizeof(x));
const int MAXN=2e4+10;
const int MAXM=1e5+10;

int top[3],first[3][MAXN],adj[3][MAXM],to[3][MAXM];
long long weight[MAXN];
bool vis[MAXN];
bool instack[MAXN];
int sta[MAXN],tag[MAXN];
int dfn[MAXN],low[MAXN];
int indegree[MAXN];
int N,M;
int num_components=0;
long long newweight[MAXN];
queue<int> Q;

void Init(){
    MEM(first,-1);
    MEM(adj,-1);
    MEM(to,-1);
    MEM(top,0);

    MEM(vis,false);
    MEM(instack,false);
    MEM(tag,-1);
    MEM(indegree,0);
    MEM(newweight,0);
    sta[0]=0;
}

void Stack_Push(int x){
    sta[++sta[0]]=x;
}

int Stack_Top(){
     return sta[sta[0]];
}

void Stack_Pop(){
    sta[0]--;
}

void Add(int u,int v,int c){
        adj[c][top[c]]=first[c][u];
        to[c][top[c]]=v;
        first[c][u]=top[c]++;
}

void Tarjan(int u){
    static int counter=0;
    low[u]=dfn[u]=counter++;
    vis[u]=true;
    Stack_Push(u);
    instack[u]=true;

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
        num_components++;
        int v;
        do{
            v=Stack_Top();
            Stack_Pop();
            instack[v]=false;
            tag[v]=num_components;
        }while(v!=u);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
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
    MEM(indegree,0);
    MEM(newweight,0);
    for(int ni=1;ni<=N;ni++){
        if((tag[ni]!=-1)){
             newweight[tag[ni]]+=weight[ni];
             for(int pos=first[0][ni];pos!=-1;pos=adj[0][pos]){
                  int v=to[0][pos];
                  if(tag[v]!=tag[ni]){
                      Add(tag[ni],tag[v],1);
                      indegree[tag[v]]++;
                      Add(tag[v],tag[ni],2);
                  }
             }
        }
    }
    Q.push(tag[1]);
    long long ans=0;
    while(!Q.empty()){
         int u=Q.front();
         Q.pop();
         long long wm=0;
         for(int pos=first[2][u];pos!=-1;pos=adj[2][pos]){
              int v=to[2][pos];
              wm=max(wm,newweight[v]);
         }
         newweight[u]+=wm;
         ans=max(ans,newweight[u]);
         for(int pos=first[1][u];pos!=-1;pos=adj[1][pos]){
              int v=to[1][pos];
              indegree[v]--;
              if(indegree[v]==0)Q.push(v);
         }
    }
    printf("%lld\n",ans);




	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
