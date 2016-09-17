#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1010;
const int MAXD=1000010;
const int INF=0x7fffffff;

int N,M;
int dist[MAXN];
bool vis[MAXN];
int ans;
int p[MAXN];
vector<pair<int,int> > G[MAXN];

void Init(){
    for(int i=0;i<MAXN;i++){
        G[i].clear();
    }
    ans=0;
    memset(p,0,sizeof(p));
}


void Dijkstra(int si){
    memset(vis,false,sizeof(vis));
    for(int i=0;i<MAXN;i++){
        dist[i]=INF;
    }
    vis[si]=true;
    dist[si]=0;
    for(int i=G[si].size()-1;i>=0;i--){
        int b=G[si][i].first;
        int c=G[si][i].second;
        if(vis[b])continue;
        if(c<dist[b])dist[b]=c;
    }

    do{
        int mini=-1,minv=INF;
        for(int i=1;i<=N;i++){
            if(vis[i])continue;
            if(dist[i]<minv){
                minv=dist[i];
                mini=i;
            }
        }
        if(mini==-1)break;
        vis[mini]=true;
        for(int i=G[mini].size()-1;i>=0;i--){
             int b=G[mini][i].first;
             if(vis[b])continue;
             int c=G[mini][i].second;
             int tmp=c+dist[mini];
             if(tmp<dist[b])dist[b]=tmp;
        }
    }while(1);
}

int DFS(int x){
    if(p[x])return p[x];
    if(2==x) return 1;
    for(int i=1;i<=N;i++){
        if(dist[i]<dist[x]){
            bool flag=false;
            for(int k=G[i].size()-1;k>=0;k--){
                if(G[i][k].first==x){
                    flag=true;
                    break;
                }
            }
            if(flag){
                p[x]+=DFS(i);
            }
        }
    }
    return p[x];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    while(cin>>N,N){
         cin>>M;
         Init();
         for(int i=0;i<M;i++){
             int a,b,c;
             cin>>a>>b>>c;
             G[a].push_back(make_pair(b,c));
             G[b].push_back(make_pair(a,c));
         }
         Dijkstra(2);
         DFS(1);
         cout<<p[1]<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
