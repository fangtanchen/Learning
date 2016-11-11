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

int first[MAXN],to[MAXM*2],val[MAXM*2],adj[MAXM*2];
int top;
int dist[MAXN];
bool vis[MAXN];
int N,M,T;
int ans,addnum;

void Init(){
     memset(first,-1,sizeof(first));
     memset(to,-1,sizeof(to));
     memset(adj,-1,sizeof(adj));
     top=0;
     memset(dist,0x3f,sizeof(dist));
     memset(vis,false,sizeof(vis));
}

void Add(int u,int v,int w){
    adj[top]=first[u];
    to[top]=v;
    val[top]=w;
    first[u]=top++;
}

int Dijkstra(int u){
    ans=0;
    addnum=0;
    memset(dist,0x3f,sizeof(dist));
    memset(vis,false,sizeof(vis));

    vis[u]=true;
    dist[u]=0;
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        dist[to[pos]]=val[pos];
    }
    while(1){
        int minval=INF,mini=-1;
        for(int i=1;i<=N;i++){
            if(vis[i])continue;
            if(dist[i]<minval){
                 mini=i;
                 minval=dist[i];
            }
        }
        if(mini==-1){
            ans=-1;
            addnum=-1;
            break;
        }
        ans+=dist[mini];
        addnum++;
        if(addnum==(N)/2+1){
             break;
        }
        vis[mini]=true;
        for(int pos=first[mini];pos!=-1;pos=adj[pos]){
            int v=to[pos];
            int w=val[pos];
            if(vis[v])continue;
            if(w<dist[v]){
                dist[v]=w;
            }
        }
    }
    return ans;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
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
        int ans=Dijkstra(0);
        if(-1==ans)printf("impossible\n");
        else printf("%d\n",ans);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
