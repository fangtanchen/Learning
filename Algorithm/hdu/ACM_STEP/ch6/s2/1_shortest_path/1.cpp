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
const int MAXN=110;
const int MAXM=10010;
const int INF=0x3f3f3f3f;


vector<pair<int,int> > G[MAXN];

int N,M;
int dist[MAXN];
int vis[MAXN];


void Init(){
     memset(dist,0x3f,sizeof(dist));
     memset(vis,false,sizeof(vis));
     for(int i=1;i<MAXN;i++){
         G[i].clear();
     }
}

void Dijkstra(int si,int di){
    memset(dist,0x3f,sizeof(dist));
    vis[si]=true;
    dist[si]=0;
    for(int i=G[si].size()-1;i>=0;i--){
        int b=G[si][i].first;
        if(vis[b])continue;
        int c=G[si][i].second;
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
        if(mini==-1||mini==di)break;
        vis[mini]=true;
        for(int i=G[mini].size()-1;i>=0;i--){
            int b=G[mini][i].first;
            if(vis[b])continue;
            int c=G[mini][i].second;
            if(c+dist[mini]<dist[b]){
                dist[b]=c+dist[mini];
            }
        }
    }while(1);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);

    while(cin>>N>>M,N||M){
        Init();
        for(int mi=0;mi<M;mi++){
             int a,b,c;
             cin>>a>>b>>c;
             G[a].push_back(make_pair(b,c));
             G[b].push_back(make_pair(a,c));
        }
        Dijkstra(1,N);
        cout<<dist[N]<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
