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

typedef pair<int,int> pii;

int top,first[MAXN],adj[MAXM],to[MAXM];
int parent[MAXN],low[MAXN],dfn[MAXN];
bool vis[MAXN];
int N,M;
bool bart[MAXN];
pii bridge[MAXM];
int brilen;

void Init(){
     top=0;
     MEM(first,-1);
     MEM(adj,-1);
     MEM(to,-1);
     MEM(parent,-1);
     MEM(low,0x5f);
     MEM(dfn,0x5f);
     MEM(vis,false);
     MEM(bart,false);
     brilen=0;
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}

void Tarjan(int u){
    static int counter=0;
    vis[u]=true;
    low[u]=dfn[u]=counter++;
    int nchild=0;
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(!vis[v]){
            nchild++;
            parent[v]=u;
            Tarjan(v);
            low[u]=min(low[u],low[v]);
            if((parent[u]==-1)&&(nchild>1)){
                 bart[u]=true;
            }else if(parent[u]!=-1&&low[v]>=dfn[u]){
                bart[u]=true;
            }
            if(low[v]>dfn[u]){
                bridge[brilen++]=pii(min(u,v),max(u,v));
            }
        }else if(v!=parent[u]){
             low[u]=min(low[u],dfn[v]);
        }
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif

    Init();
    scanf("%d%d",&N,&M);
    for(int mi=0;mi<M;mi++){
         int u,v;
         scanf("%d%d",&u,&v);
         Add(u,v);Add(v,u);
    }

    Tarjan(1);
    sort(bridge,bridge+brilen);
    int cnt=0;
    for(int i=1;i<=N;i++){
        if(bart[i]){
            if(cnt)printf(" ");
            cnt++;
            printf("%d",i);
        };
    }
    if(cnt==0)printf("Null");
    printf("\n");
    for(int i=0;i<brilen;i++){
         printf("%d %d\n",bridge[i].first,bridge[i].second);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
