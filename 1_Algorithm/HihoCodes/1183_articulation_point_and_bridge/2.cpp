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


struct Path{
    int x,y;
    Path(int a=0,int b=0){
        x=a;y=b;
    }
};

int first[MAXN],adj[MAXM],to[MAXM],top;
int low[MAXN],dfn[MAXN];
bool vis[MAXN];
bool isacticulation[MAXN];
Path path[MAXM];
int path_len;
int parent[MAXN];
int N,M;

void Init(){
     memset(first,-1,sizeof(first));
     memset(adj,-1,sizeof(adj));
     memset(to,-1,sizeof(to));
     top=0;
     memset(vis,false,sizeof(vis));
     memset(isacticulation,false,sizeof(isacticulation));
     memset(parent,-1,sizeof(parent));
     path_len=0;
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}

void DFS(int u){
    static int counter=0;
    vis[u]=true;
    int numchild=0;
    low[u]=dfn[u]=counter++;

    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(!vis[v]){
            parent[v]=u;
            numchild++;
            DFS(v);
            low[u]=min(low[u],low[v]);
            if((-1==parent[u])&&(numchild>1)){
                 isacticulation[u]=true;
            }
            if((parent[u]>=0)&&(low[v]>=dfn[u])){
                 isacticulation[u]=true;
            }
            if(low[v]>dfn[u]){
                path[path_len].x=min(u,v);
                path[path_len].y=max(u,v);
                path_len++;
            }
        }else if(parent[u]!=v){
             low[u]=min(low[u],dfn[v]);
        }
    }
}

bool Cmp(const Path& p1,const Path& p2){
    if(p1.x<p2.x)return true;
    else if((p1.x==p2.x)&&(p1.y<p2.y))return true;
    return false;
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
    bool flag=false;
    for(int i=1;i<=N;i++){
         if(isacticulation[i]){
             if(flag)printf(" ");
             printf("%d",i);
             flag=true;
         }
    }
    if(!flag)printf("Null");
    printf("\n");
    sort(path,path+path_len,Cmp);
    for(int i=0;i<path_len;i++){
         printf("%d %d\n",path[i].x,path[i].y);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
