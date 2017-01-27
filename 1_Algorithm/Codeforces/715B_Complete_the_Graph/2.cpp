#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define LL long long int
#define other(x,y) (y==edg[x].u?edg[x].v:edg[x].u)
#define pii pair<LL,int>

const int MAXN=1005;
const int MAXM=1e4+5;
const LL INF=1e11+7;


struct edge{
     int u,v;
     LL cost;
     bool f;
}edg[MAXM];
priority_queue<pii,vector<pii>,greater<pii> > heap;
vector<int> G[MAXN];
bool vis[MAXN];
int side[MAXN];
LL dis[MAXN];
LL dist,tot;
int N,M;
bool si[MAXM];

void dij(int now,int ed){
    if(now==ed)return;
    vis[now]=true;
    for(int i=0;i<G[now].size();i++){
        int p=G[now][i];
        int q=other(p,now);
        if(vis[q])continue;
        if(dis[q]>dis[now]+edg[p].cost){
            dis[q]=dis[now]+edg[p].cost;
            heap.push(make_pair(dis[q],q));
            side[q]=p;
        }
    }
    while(!heap.empty()&&(vis[heap.top().second]))heap.pop();
    if(heap.empty())return;
    dij(heap.top().second,ed);
}

LL Dijkstra(int st,int ed){
    while(!heap.empty())heap.pop();
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=N;i++)dis[i]=INF;
    dis[st]=0;
    dij(st,ed);
    return dis[ed];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int st,ed;
    scanf("%d%d%lld%d%d",&N,&M,&dist,&st,&ed);
    for(int i=1;i<=M;i++){
         scanf("%d%d%lld",&edg[i].u,&edg[i].v,&edg[i].cost);
         if(0==edg[i].cost){
             edg[i].f=true;
             edg[i].cost=INF;
         }else{
              edg[i].f=false;
         }
         G[edg[i].u].push_back(i);
         G[edg[i].v].push_back(i);
    }
    tot=Dijkstra(st,ed);
    if(tot<dist){
         return 0*printf("NO\n");
    }
    if(tot==dist){
        printf("YES\n");
        for(int i=1;i<=M;i++)printf("%d %d %lld\n",edg[i].u,edg[i].v,edg[i].cost);
        return 0;
    }
    for(int i=1;i<=M;i++)if(edg[i].f)edg[i].cost=1;
    tot=Dijkstra(st,ed);
    if(tot>dist)return 0*printf("NO\n");
    printf("YES\n");
    memset(si,false,sizeof(si));
    int tmpu=ed;
    while(tmpu!=st){
         int ei=side[tmpu];
         if(edg[ei].f)si[ei]=true;
         tmpu=other(ei,tmpu);
    }
    for(int i=1;i<=M;i++)
        if(edg[i].f&&(!si[i]))
            edg[i].cost=INF;
    while((tot=Dijkstra(st,ed))<dist){
        int tmpu=ed;
        while(tmpu!=st){
             int ei=side[tmpu];
             if(edg[ei].f){
                 edg[ei].cost+=dist-tot;
                 break;
             }
             tmpu=other(ei,tmpu);
        }
        if(tmpu==st)break;
    }
    for(int i=1;i<=M;i++)printf("%d %d %lld\n",edg[i].u,edg[i].v,edg[i].cost);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
