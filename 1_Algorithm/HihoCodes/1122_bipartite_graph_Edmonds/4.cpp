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
const int MAXM=5010;

int N,M;
vector<int> G[MAXN];
bool vis[MAXN];
int tag[MAXN];
queue<int> qe;
int mp[MAXN];

void Init(){
    for(int i=0;i<MAXN;i++)
        G[i].clear();
    memset(vis,false,sizeof(vis));
    memset(tag,-1,sizeof(tag));
    memset(mp,-1,sizeof(mp));
}


void BFS(int rt){
    while(!qe.empty()){
        qe.pop();
    }
    tag[rt]=0;
    qe.push(rt);
    while(!qe.empty()){
        int now=qe.front();
        qe.pop();
        for(int i=G[now].size()-1;i>=0;i--){
            int nex=G[now][i];
            if(tag[nex]==tag[now])return;
            if(tag[nex]==-1){
                tag[nex]=1-tag[now];
                qe.push(nex);
            }
        }
    }
    return;
}



bool FindPath(int pi){
    for(int i=G[pi].size()-1;i>=0;i--){
        int nex=G[pi][i];
        if(vis[nex])continue;
        vis[nex]=true;
        if(mp[nex]==-1 || FindPath(mp[nex])){
            mp[pi]=nex;
            mp[nex]=pi;
            return true;
        }
    }
    return false;
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
         G[u].push_back(v);
         G[v].push_back(u);
    }
    for(int ni=1;ni<=N;ni++){
        if(-1==tag[ni]){
            BFS(ni);
        }
    }
    int ans=0;
    for(int ni=1;ni<=N;ni++){
        if(mp[ni]==-1&& tag[ni]==0) {
            memset(vis,false,sizeof(vis));
            vis[ni]=true;
             if(FindPath(ni))ans++;
        }
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
