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
const int MAXN=20010;
const int MAXM=1e5+10;
const int MAXS=3;

#define MEM(x,a) memset(x,a,sizeof(x))
int top[MAXS],first[MAXS][MAXN],adj[MAXS][MAXM],to[MAXS][MAXM];
bool vis[MAXN];
int w[MAXN],nw[MAXN];
int pstack[MAXN],instack[MAXN];
int low[MAXN],dfn[MAXN];
int qcolor[MAXN];
int N,M;

void Init(){
    MEM(top,0);
    MEM(first,-1);
    MEM(adj,-1);
    MEM(to,-1);
    MEM(vis,false);
    MEM(pstack,-1);
    MEM(instack,false);
    MEM(low,0x5f);
    MEM(dfn,0x5f);
    pstack[0]=0;
    MEM(nw,0);
}

void Add(int type,int u,int v){
    adj[type][top[type]]=first[type][u];
    to[type][top[type]]=v;
     first[type][u]=top[type]++;
}

void Tarjan(int u){
    static int counter=0;
    low[u]=dfn[u]=++counter;
    vis[u] =true;
    instack[u]=true;
    pstack[++pstack[0]]=u;
    for(int pos=first[0][u];pos!=-1;pos=adj[0][pos]){
         int v=to[0][pos];
         if(!vis[v]){
             Tarjan(v);
             low[u]=min(low[u],low[v]);
         }else if(instack[v]){
            low[u] =min(low[u],dfn[v]);
         }
    }
    if(low[u]==dfn[u]){
        int tmp;
        do{
            tmp=pstack[pstack[0]--];
            instack[tmp]=false;
            qcolor[tmp]=u;
            nw[u]+=w[tmp];
        }while(tmp!=u);
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
        scanf("%d",w+ni);
    }
    for(int mi=0;mi<M;mi++){
         int u,v;
         scanf("%d%d",&u,&v);
         Add(0,u,v);
    }
    Tarjan(1);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
