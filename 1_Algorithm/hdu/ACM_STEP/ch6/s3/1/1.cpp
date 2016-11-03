#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE

#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1010;

vector<int> G[MAXN];
queue<int> qe;
int tag[MAXN];
bool vis[MAXN];
int mp[MAXN];
int N;

void Init(){
    for(int i=0;i<MAXN;i++){
        G[i].clear();
    }
    memset(tag,-1,sizeof(tag));
    memset(mp,-1,sizeof(mp));
    memset(vis,false,sizeof(vis));
}

void BFS(int u){
    while(!qe.empty())qe.pop();
    qe.push(u);
    tag[u]=0;
    while(!qe.empty()){
        int now=qe.front();
        qe.pop();
        for(int i=G[now].size()-1;i>=0;i--){
            int nex=G[now][i];
            if(tag[nex]==-1){
                tag[nex]=1-tag[now];
                qe.push(nex);
            }
        }
    }
}

bool FindPath(int u){
    for(int i=G[u].size()-1;i>=0;i--){
        int v=G[u][i];
        if(vis[v])continue;
        vis[v]=true;
        if((mp[v]==-1)||FindPath(mp[v])){
            mp[u]=v;
            mp[v]=u;
            return true;
        }
    }
    return false;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d",&N)){
             Init();
             int u,v,M;
             for(int ni=0;ni<N;ni++){
                 scanf("%d: (%d)",&u,&M);
                 for(int mi=0;mi<M;mi++){
                     scanf("%d",&v);
                     G[u].push_back(v);
                 }
             }
             for(int ni=0;ni<N;ni++){
                 if(tag[ni]==-1){
                     BFS(ni);
                 }
             }
             int ans=0;
             for(int ni=0;ni<N;ni++){
                 if((mp[ni]==-1)&&(tag[ni])){
                     memset(vis,false,sizeof(vis));
                     vis[ni]=true;
                     if(FindPath(ni))ans++;
                 }
             }
             printf("%d\n",N-ans);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
