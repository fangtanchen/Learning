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
const int MAXS=1025;
const int MOD=1e9+7;

#define MEM(x,a) memset(x,a,sizeof(x))

int top,first[MAXN],adj[MAXM],to[MAXM],eid[MAXM];
int estack[MAXM];
bool vis[MAXN];
int dfn[MAXN],low[MAXN];
int parent[MAXN];
int ecolor[MAXM],ncolor;
int N,M;

void Init(){
     top=0;
     MEM(first,-1);
     MEM(adj,-1);
     MEM(to,-1);
     MEM(eid,-1);
     estack[0]=0;
     MEM(vis,false);
     MEM(parent,-1);
     MEM(ecolor,-1);
     ncolor=1;
}

void Add(int id,int u,int v){
    adj[top]=first[u];
    to[top]=v;
    eid[top]=id;
    first[u]=top++;
}

void Tarjan(int u){
    static int counter=0;
    vis[u]=true;
    low[u]=dfn[u]=++counter;
    int nchild=0;
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        int mi=eid[pos];
        if(ecolor[mi]!=-1)continue;
        if(!vis[v]){
            nchild++;
            parent[v]=u;
            estack[++estack[0]]=mi;
            Tarjan(v);
            low[u]=min(low[u],low[v]);
            if(parent[u]==-1&&nchild>1){
                ncolor++;
                int tmpmi;
                do{
                    tmpmi=estack[estack[0]--];
                    ecolor[tmpmi]=ncolor;
                }while(tmpmi!=mi);
            }
            if(parent[u]!=-1 && (low[v]>=dfn[u])){
                ncolor++;
                int tmpmi;
                do{
                    tmpmi=estack[estack[0]--];
                    ecolor[tmpmi]=ncolor;
                }while(tmpmi!=mi);
            }
        }else if(v!=parent[u]){
            estack[++estack[0]]=mi;
             low[u]=min(low[u],dfn[v]);
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);
    for(int mi=1;mi<=M;mi++){
         int u,v;
         scanf("%d%d",&u,&v);
         Add(mi,u,v);
         Add(mi,v,u);
    }
    Tarjan(1);
    MEM(estack,-1);
    printf("%d\n",ncolor);
    for(int mi=1;mi<=M;mi++){
        if(ecolor[mi]==-1)ecolor[mi]=1;
        if(estack[ecolor[mi]]==-1){
            estack[ecolor[mi]]=mi;
        }
        printf("%d",estack[ecolor[mi]]);
        if(mi<M)printf(" ");
        else printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
