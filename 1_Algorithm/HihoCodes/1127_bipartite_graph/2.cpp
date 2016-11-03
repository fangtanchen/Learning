#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;
const int MAXM=5010;

int N,M;
int top,first[MAXN],adj[MAXM*2],to[MAXM*2];
int tag[MAXN];
bool vis[MAXN];
int mp[MAXN];
queue<int> qe;


void Init(){
    top=0;
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(to,-1,sizeof(to));
    memset(tag,-1,sizeof(tag));
    memset(vis,false,sizeof(vis));
    memset(mp,-1,sizeof(mp));
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}

void BFS(int rt){
    while(!qe.empty())qe.pop();
    tag[rt]=0;
    qe.push(rt);
    while(!qe.empty()){
        int now=qe.front();
        qe.pop();
        for(int pos=first[now];pos!=-1;pos=adj[pos]){
             int nex=to[pos];
             if(tag[nex]==-1){
                 tag[nex]=1-tag[now];
                 qe.push(nex);
             }
        }
    }
}

bool FindPath(int rt){
    for(int pos=first[rt];pos!=-1;pos=adj[pos]){
        int nex=to[pos];
        if(vis[nex])continue;
        vis[nex]=true;
        if((mp[nex]==-1)||FindPath(mp[nex])){
            mp[nex]=rt;
            mp[rt]=nex;
            return true;
        }
    }
    return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);
    for(int mi=0;mi<M;mi++){
         int u,v;
         scanf("%d%d",&u,&v);
         Add(u,v);
         Add(v,u);
    }
    for(int ni=1;ni<=N;ni++){
        if(tag[ni]==-1){
            BFS(ni);
        }
    }
    int ans=0;
    for(int ni=1;ni<=N;ni++){
        if((tag[ni]==0)&&(mp[ni]==-1)){
            memset(vis,false,sizeof(vis));
            vis[ni]=true;
            if(FindPath(ni))ans++;
        }
    }
    printf("%d\n%d\n",ans,N-ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
