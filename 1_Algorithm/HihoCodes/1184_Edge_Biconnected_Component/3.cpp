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
const int MAXN=2e4+10;
const int MAXM=2e5+10;

#define MEM(x,a) memset(x,a,sizeof(x))

int top,first[MAXN],adj[MAXM],to[MAXM];
int low[MAXN],dfn[MAXN],parent[MAXN];
bool vis[MAXN];
int pstack[MAXM];
int pcolor[MAXN];
int N,M;

void Init(){
     top=0;
     MEM(first,-1);
     MEM(adj,-1);
     MEM(to,-1);
     MEM(low,0x5f);
     MEM(dfn,0x5f);
     MEM(parent,-1);
     MEM(vis,false);
     MEM(pcolor,-1);
     pstack[0]=0;
     pcolor[0]=0;
}

void Add(int u,int v){
     adj[top]=first[u];
     to[top]=v;
     first[u]=top++;
}

void Tarjan(int u){
    static int counter=0;
    vis[u]=true;
    low[u]=dfn[u]=++counter;
    int nchild=0;
    pstack[++pstack[0]]=u;
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
         int v=to[pos];
         if(!vis[v]){
             nchild++;
             parent[v]=u;
             Tarjan(v);
             low[u]=min(low[u],low[v]);
         }else if(v!=parent[u]){
             low[u]=min(low[u],dfn[v]);
         }
    }
    if(low[u]>=dfn[u]){
        ++pcolor[0];
        int tmp;
        do{
            tmp=pstack[pstack[0]--];
            pcolor[tmp]=pcolor[0];
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
    for(int mi=0;mi<M;mi++){
         int u,v;
         scanf("%d%d",&u,&v);
         Add(u,v);Add(v,u);
    }
    Tarjan(1);
    MEM(pstack,-1);
    printf("%d\n",pcolor[0]);
    for(int ni=1;ni<=N;ni++){
        if(pstack[pcolor[ni]]==-1){
            pstack[pcolor[ni]]=ni;
        }
        printf("%d",pstack[pcolor[ni]]);
        if(ni<N)putchar(' ');
        else putchar('\n');
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
