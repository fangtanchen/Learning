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
typedef long long int ll;
typedef pair<ll,int> pii;

const int MAXN=1005;
const int MAXM=1e4+10;
const int INF=0x3f3f3f3f;


struct Edge{
     int u,v;
     ll w;
     bool f;
}edges[MAXM];


vector<int> G[MAXN];
int N,M,S,T;
ll L;
bool inQ[MAXN];
int Q[MAXM*2];
int head,tail;
int path[MAXN],pathlen;
int pa[MAXN];
const int Qlen=MAXM*2;
priority_queue<pii,vector<pii>,greater<pii> > heap;

void Push(int x){
    tail=(tail+1)%Qlen;
    Q[tail]=x;
}
void Pop(){
     head=(head+1)%Qlen;
}
int Top(){
    return Q[head];
}
bool IsEmpty(){
    return (tail+1)%Qlen==head;
}

void dij(int now,int en,ll *dis){
    if(en==now)return;
    inQ[now]=true;
    for(int i=0;i<G[now].size();i++){
        int ei=G[now][i];
        int v=(edges[ei].u==now?edges[ei].v:edges[ei].u);
        if(inQ[v])continue;
        if(dis[v]>dis[now]+edges[ei].w){
             dis[v]=dis[now]+edges[ei].w;
             heap.push(make_pair(dis[v],v));
             path[v]=ei;
        }
    }
    while(!heap.empty()&&(inQ[heap.top().second]))heap.pop();
    if(heap.empty())return;
    dij(heap.top().second,en,dis);
}

ll dijk(int st,int ed){
    ll dist[MAXN];
    while(!heap.empty())heap.pop();
    memset(inQ,false,sizeof(inQ));
    memset(dist,0x3f,sizeof(dist));
    dist[st]=0;
    dij(st,ed,dist);
    return dist[ed];
}

ll Dijkstra(int st,int ed){
    ll dist[MAXN];
    memset(dist,0x3f,sizeof(dist));
    memset(inQ,false,sizeof(inQ));
    memset(path,-1,sizeof(path));
    inQ[st]=true;
    for(int i=0;i<G[st].size();i++){
        int ei=G[st][i];
        int tmpv=(edges[ei].u==st?edges[ei].v:edges[ei].u);
        dist[tmpv]=edges[ei].w;
        path[tmpv]=ei;
    }
    do{
       ll minv=INF;
       int mini=-1;
       for(int i=0;i<N;i++){
           if(inQ[i])continue;
           if(dist[i]<minv){
               mini=i;
               minv=dist[i];
           }
       }
       if(mini==-1||mini==ed)break;
       inQ[mini]=true;
       for(int i=0;i<G[mini].size();i++){
            int ei=G[mini][i];
            int v=(edges[ei].u==mini?edges[ei].v:edges[ei].u);
            if(inQ[v])continue;
            ll tmp=dist[mini]+edges[ei].w;
            if(tmp<dist[v]){
                 dist[v]=tmp;
                 path[v]=ei;
            }
       }
    }while(1);
    return dist[ed];
}

ll SPFA(int st,int ed){
    ll dist[MAXN];
    memset(dist,0x3f,sizeof(dist));
    head=0,tail=-1;
    memset(inQ,false,sizeof(inQ));
    memset(path,-1,sizeof(path));
    Push(st);
    inQ[st]=true;
    dist[st]=0;
    while(!IsEmpty()){
         int u=Top();
         Pop();
         inQ[u]=false;
         for(int i=0;i<G[u].size();i++){
             Edge e=edges[G[u][i]];
             int v;
             if(u==e.u)v=e.v;
             else v=e.u;
             ll tmp=e.w+dist[u];
             if(tmp<dist[v]){
                  dist[v]=tmp;
                  path[v]=G[u][i];
                  if(!inQ[v]){
                      inQ[v]=true;
                      Push(v);
                  }
             }
         }
    }
    return dist[ed];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d%lld%d%d",&N,&M,&L,&S,&T);
    for(int mi=0;mi<M;mi++){
         scanf("%d%d%lld",&edges[mi].u
                 ,&edges[mi].v,&edges[mi].w);
         if(edges[mi].w==0){
             edges[mi].f=true;
             edges[mi].w=INF;
         }else{
             edges[mi].f=false;
         }
         G[edges[mi].u].push_back(mi);
         G[edges[mi].v].push_back(mi);
    }
    ll dist=dijk(S,T);
    if(dist<L){
         return 0*printf("NO\n");
    }
    if(dist==L){
        printf("YES\n");
        for(int mi=0;mi<M;mi++){
            printf("%d %d %lld\n",edges[mi].u,
                    edges[mi].v,edges[mi].w);
        }
        return 0;
    }
    for(int mi=0;mi<M;mi++){
         if(edges[mi].f)edges[mi].w=1;
    }
    dist=dijk(S,T);
    if(dist>L)return 0*printf("NO\n");

    memset(pa,0,sizeof(pa));
    int  tmpu=T;
    while(tmpu!=S){
        int ei=path[tmpu];
        if(edges[ei].f)pa[ei]=1;
        if(edges[ei].u==tmpu)tmpu=edges[ei].v;
        else tmpu=edges[ei].u;
    }
    for(int mi=0;mi<M;mi++){
        if(edges[mi].f&&(0==pa[mi])){
            edges[mi].w=INF;
        }
    }
    while((dist=dijk(S,T))<L){
         int tmpu=T;
         while(tmpu!=S){
             int ei=path[tmpu];
             if(edges[ei].f){
                 edges[ei].w+=L-dist;
                 break;
             }
             tmpu=(edges[ei].u==tmpu?edges[ei].v:edges[ei].u);
         }
         if(tmpu==S)break;
    }
    printf("YES\n");
    for(int mi=0;mi<M;mi++){
        printf("%d %d %lld\n",edges[mi].u,
                edges[mi].v,edges[mi].w);
    }



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
