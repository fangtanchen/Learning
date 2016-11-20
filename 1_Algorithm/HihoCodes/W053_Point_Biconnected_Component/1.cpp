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

int top,first[MAXN],adj[MAXM],to[MAXM];
int sta[MAXN],parent[MAXN];
bool vis[MAXN];
int dfn[MAXN],low[MAXN];
int tag[MAXN],group[MAXN];
int N,M;
int graph_cnt;

void Init(){
    top=0;
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(to,-1,sizeof(to));
    memset(vis,false,sizeof(vis));
    sta[0]=0;
    memset(parent,-1,sizeof(parent));
    memset(group,-1,sizeof(group));
    memset(tag,-1,sizeof(tag));
    graph_cnt=1;
}

void Add(int u,int v){
     adj[top]=first[u];
     to[top]=v;
     first[u]=top++;
}

void Push_Stack(int x){
    sta[0]++;
     sta[sta[0]]=x;
}
int Top_Stack(){
    return sta[sta[0]];
}
void Pop_Stack(){
     sta[0]--;
}

void DFS(int u){
    static int counter=0;
    vis[u]=true;
    dfn[u]=low[u]=counter++;
    Push_Stack(u);
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(!vis[v]){
            parent[v]=u;
            DFS(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                graph_cnt++;
            }
        }else if(parent[u]!=v){
             low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        int x;
        do{
            x=Top_Stack();
            Pop_Stack();
            tag[x]=graph_cnt;
        }while(x!=u);
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
         Add(u,v);
         Add(v,u);
    }
    DFS(1);
    printf("%d\n",graph_cnt);
    memset(vis,false,sizeof(vis));
    for(int ni=1;ni<=N;ni++){
        if(group[tag[ni]]==-1){
            group[tag[ni]]=ni;
        }
        printf("%d%c",group[tag[ni]],ni==N?'\n':' ');
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
