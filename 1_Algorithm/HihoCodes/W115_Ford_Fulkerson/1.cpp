#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=510;
const int MAXM=20010;
const int INF=0x5f5f5f5f;

typedef unsigned char ubyte;

//ubyte c[MAXN][MAXN];
int cf[MAXN][MAXN];
//ubyte f[MAXN][MAXN];
vector<int> G[MAXN];
int path[MAXN];
int capacity[MAXN];
int N,M;

void Init(){
    for(int i=0;i<MAXN;i++){
        G[i].clear();
    }
    //memset(c,1,sizeof(c));
    memset(cf,0,sizeof(cf));
    //memset(f,1,sizeof(f));
}

int FindAugmentPath(int S,int T,int path[]){
    bool vis[MAXN];
    queue<int> qe;
    memset(vis,false,sizeof(vis));
    memset(capacity,0,sizeof(capacity));
    memset(path,0,sizeof(path));
    while(!qe.empty()){
         qe.pop();
    }

    vis[S]=true;
    capacity[S]=INF;
    qe.push(S);
    while(!qe.empty()){
        int np=qe.front();
        qe.pop();
        if(np==T){
            return capacity[np];
        }else{
            for(int i=G[np].size()-1;i>=0;i--) {
                int pp=G[np][i];
                if(cf[np][pp]<=0||vis[pp])continue;
                path[pp]=np;
                capacity[pp]=min(cf[np][pp],capacity[np]);
                vis[pp]=true;
                qe.push(pp);
            }
        }
    }

    return false;
}

void ModifyGraph(int S,int T,int path[]){
    int flow=capacity[T];
    int now=T;
    while(now!=S){
        int fa=path[now];
        cf[now][fa]=cf[now][fa]+flow;
        cf[fa][now]=cf[fa][now]-flow;
        now=fa;
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    Init();
    for(int i=0;i<M;i++){
         int u,v,c;
         cin>>u>>v>>c;
         G[u].push_back(v);
         cf[u][v]+=c;
    }
    int maxFlow=0;
    int delta=FindAugmentPath(1,N,path);
    while(delta>0){
        maxFlow+=delta;
        ModifyGraph(1,N,path);
        delta=FindAugmentPath(1,N,path);
    }
    cout<<maxFlow<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
