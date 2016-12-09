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
const int MAXM=3e5+10;

#define MEM(x,a) memset(x,a,sizeof(x))

int top;
int first[MAXN],to[MAXM],adj[MAXM],id[MAXM];
int N,M;
bool vis[MAXN];
int ecolor[MAXM],estack[MAXM],ncolor;
int parent[MAXN];
int low[MAXN],dfn[MAXN];

void Init(){
    top=0;
    MEM(first,-1);
    MEM(to,-1);
    MEM(adj,-1);
    MEM(id,-1);
    MEM(vis,false);
    MEM(ecolor,-1);
    MEM(parent,-1);
    MEM(low,0x5f);
    MEM(dfn,0x5f);
    estack[0]=0;
    ncolor=0;
}

void Add(int u,int v,int i){
    adj[top]=first[u];
    to[top]=v;
    id[top]=i;
    first[u]=top++;
}

void Tarjan(int u){
    static int counter=0;
    vis[u]=true;
    low[u]=dfn[u]=counter++;
    int nchild=0;
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos] ;
        int mi=id[pos];
        if(ecolor[mi]!=-1)continue;
        if(!vis[v]){
            estack[++estack[0]]=mi;
            nchild++;
            parent[v]=u;
            Tarjan(v);
            low[u]=min(low[u],low[v]);
            if((-1==parent[u])&&(nchild>1)){
                int tmpi;
                do{
                     tmpi=estack[estack[0]--];
                     ecolor[tmpi]=ncolor;
                }while(tmpi!=mi);
                ncolor++;
            }else if(low[v]>=dfn[u]){
                int tmpi;
                do{
                     tmpi=estack[estack[0]--];
                     ecolor[tmpi]=ncolor;
                }while(tmpi!=mi);
                ncolor++;
            }
        }else if(parent[u]!=v){
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
         Add(u,v,mi);
         Add(v,u,mi);
    }

    Tarjan(1);
    printf("%d\n",ncolor);

    MEM(estack,-1);
    for(int mi=1;mi<M;mi++){
        if(estack[ecolor[mi]]==-1) {
             estack[ecolor[mi]]=mi;
        }
        printf("%d ",estack[ecolor[mi]]);
    }
    if(estack[ecolor[M]]==-1){
        estack[ecolor[M]]=M;
    }
    printf("%d\n",estack[ecolor[M]]);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
