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
const int MAXV=1020;
const int MAXN=1020;
const int INF=0x3f3f3f3f;

int T,S,D;
int from[MAXN],to[MAXN];
int dist[MAXN];
bool vis[MAXN];
int maxn;
vector<pair<int,int> > G[MAXN];

void Init(){
    memset(dist,0x3f,sizeof(dist));
    for(int i=0;i<MAXN;i++){
         G[i].clear();
    }
    maxn=0;
}

int Dijkstra(int si,int to[],int tolen){
    memset(vis,false,sizeof(vis));
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
        for(int i=1;i<=maxn;i++){
            if(vis[i])continue;
            if(dist[i]<minv){
                mini=i;
                minv=dist[i];
            }
        }
        if(mini==-1)break;
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
    int ret=INF;
    for(int i=0;i<tolen;i++){
        if(dist[to[i]]<ret) ret=dist[to[i]];
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    while(cin>>T>>S>>D){
        Init();
        for(int i=0;i<T;i++){
            int a,b,t;
            cin>>a>>b>>t;
            G[a].push_back(make_pair(b,t));
            G[b].push_back(make_pair(a,t));
            if(a>maxn)maxn=a;
            if(b>maxn)maxn=b;
        }
        for(int i=0;i<S;i++){
            cin>>from[i];
        }
        for(int i=0;i<D;i++){
            cin>>to[i];
        }
        int ret=INF;
        for(int i=0;i<S;i++){
            int tmp=Dijkstra(from[i],to,D);
            if(tmp<ret)ret=tmp;
        }
        cout<<ret<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
