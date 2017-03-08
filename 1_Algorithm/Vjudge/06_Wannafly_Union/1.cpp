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
const int MAXN=510;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

const int dir[4][2]={-1,0,1,0,0,-1,0,1};


int N,M;
int  G[MAXN][MAXN];
bool vis[MAXN*MAXN];
int kk[MAXN*MAXN];


bool InMap(int ri,int ci){
    return (ri>=0)&&(ri<N)&&(ci>=0)&&(ci<M);
}

int BFS(int st,int ed){
    queue<int> Q;
    memset(vis,false,sizeof(vis));
    memset(kk,0x3f,sizeof(kk));
    Q.push(st);
    kk[st]=0;
    vis[st]=true;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        vis[u]=false;
        int uri=u/M,uci=u%M;
        for(int di=0;di<4;di++){
            int vri=uri+dir[di][0]*G[uri][uci];
            int vci=uci+dir[di][1]*G[uri][uci];
            int v=vri*M+vci;
            if(!InMap(vri,vci))continue;
            if(kk[u]+1<kk[v]){
                 kk[v]=kk[u]+1;
                 if(!vis[v]){
                     vis[v]=true;
                     Q.push(v);
                 }
            }
        }

    }
    if(kk[ed]==INF)kk[ed]=-1;

    return kk[ed];
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d%d",&N,&M)){
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    scanf("%1d",G[i]+j);
                }
            }
            int ans=BFS(0,N*M-1);
            printf("%d\n",ans);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
