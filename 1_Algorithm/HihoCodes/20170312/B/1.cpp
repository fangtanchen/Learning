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
const int MAXN=805;
typedef pair<int,int> pii;

const int dir[4][2]={-1,0,1,0,0,1,0,-1};
char G[MAXN][MAXN];
int dist[MAXN][MAXN];
int ans[MAXN][MAXN];
bool vis[MAXN][MAXN];
int N,M;

bool InMap(int ri,int ci){
    return (ri>=0)&&(ri<N)&&(ci>=0)&&(ci<M);
}

int BFS(int ri,int ci){
    queue<pii> Q;
    memset(vis,false,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    Q.push(make_pair(ri,ci));
    dist[ri][ci]=0;
    while(!Q.empty()){
        pii now=Q.front();
        Q.pop();
        int uri=now.first,uci=now.second;
        vis[uri][uci]=true;
        if(ans[uri][uci]<=dist[uri][uci])continue;
        else ans[uri][uci]=dist[uri][uci];

        for(int di=0;di<4;di++){
             int vri=uri+dir[di][0];
             int vci=uci+dir[di][1];
             if(!InMap(vri,vci))continue;
             if(vis[vri][vci])continue;
             dist[vri][vci]=dist[uri][uci]+1;
             if(dist[vri][vci]<ans[vri][ci]){
                 Q.push(make_pair(vri,vci));
             }
        }
    }
    return 0x3f3f3f3f;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%s",G[i]);
    }
    memset(ans,0x3f,sizeof(ans));
    for(int ri=0;ri<N;ri++){
        for(int ci=0;ci<M;ci++){
            if(G[ri][ci]=='1')continue;
            else{
                BFS(ri,ci);
            }
        }
    }
    for(int ri=0;ri<N;ri++){
        printf("%d",ans[ri][0]);
        for(int ci=1;ci<M;ci++){
            printf(" %d",ans[ri][ci]);
        }
        printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
