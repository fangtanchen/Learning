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
const int MAXN=105;
const int MAXM=10010;
const int INF=0x3f3f3f3f;

int first[MAXN],adj[MAXM*2],to[MAXM*2],val[MAXM*2];
bool vis[MAXN];
int dist[MAXN],energy[MAXN];
int top;
int ans;
int addnum;
int totalenergy;
int T,N,M;
int dp[1000010];

void Init(){
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(to,-1,sizeof(to));
    memset(val,-1,sizeof(val));
    memset(vis,false,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    top=0;
    ans=0;
    totalenergy=0;
}

void Add(int u,int v,int w){
    adj[top]=first[u];
    to[top]=v;
    val[top]=w;
    first[u]=top++;
}

void Dijkstra(int st){
    memset(vis,false,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    vis[st]=true;
    dist[st]=0;
    for(int pos=first[st];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        int w=val[pos];
        dist[v]=min(dist[v],w);
    }
    while(1){
         int minval=INF,mini=-1;
         for(int v=1;v<=N;v++){
             if(vis[v])continue;
             if(dist[v]<minval){
                  minval=dist[v];
                  mini=v;
             }
         }
         if(-1==mini){
             break;
         }
         vis[mini]=true;
         for(int pos=first[mini];pos!=-1;pos=adj[pos]){
              int v=to[pos];
              if(vis[v])continue;
              int w=val[pos];
              if(w+dist[mini]<dist[v]){
                  dist[v]=w+dist[mini];
              }
         }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>T;
    while(T--){
        Init();
         cin>>N>>M;
         for(int i=0;i<M;i++){
              int u,v,w;
              cin>>u>>v>>w;
              Add(u,v,w);
              Add(v,u,w);
         }
         for(int i=1;i<=N;i++){
              cin>>energy[i];
              totalenergy+=energy[i];
         }
         Dijkstra(0);
         int totaldist=0;
         for(int i=1;i<=N;i++){
             if(dist[i]==INF)continue;
             totaldist+=dist[i];
         }
         memset(dp,0,sizeof(dp));
         for(int i=1;i<=N;i++){
             if(dist[i]==INF)continue;
             for(int j=totaldist;j>=dist[i];j--){
                 dp[j]=max(dp[j],dp[j-dist[i]]+energy[i]);
             }
         }
         int thre=totalenergy/2;
         if(dp[totaldist]<=thre){
              cout<<"impossible"<<endl;
         }else{
             int l=0,r=totaldist;
             while(l<=r){
                 int mid=(l+r)/2;
                 if(dp[mid]<=thre){
                     l=mid+1;
                 }else{
                    r=mid-1;
                 }
             }
             cout<<r+1<<endl;
         };
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
