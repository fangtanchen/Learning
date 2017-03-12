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

const int MAXN=810;
typedef long long int LL;
typedef pair<int,int> pii;

const int dir[4][2]={-1,0,1,0,0,1,0,-1};
int N,M;
char G[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
queue<pii> Q;

bool InMap(int ri,int ci){
    return ri>=1&&ri<=N&&ci>=1&&ci<=M;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    memset(dist,0x3f,sizeof(dist));
    memset(vis,false,sizeof(vis));
    for(int ri=1;ri<=N;ri++){
        scanf("%s",G[ri]+1);
        for(int ci=1;ci<=M;ci++){
            if(G[ri][ci]=='0'){
                dist[ri][ci]=0;
                Q.push(make_pair(ri,ci));
                vis[ri][ci]=true;
            }
        }
    }
    while(!Q.empty()){
        pii u=Q.front();
        Q.pop();
        int uri=u.first,uci=u.second;
        vis[uri][uci]=false;
        for(int di=0;di<4;di++){
             int vri=uri+dir[di][0];
             int vci=uci+dir[di][1];
             if((!InMap(vri,vci)))continue;
             if(dist[vri][vci]>dist[uri][uci]+1){
                 dist[vri][vci]=dist[uri][uci]+1;
                 if(!vis[vri][vci]){
                     Q.push(make_pair(vri,vci));
                     vis[vri][vci]=true;
                 };
             }
        }
    }
    for(int ri=1;ri<=N;ri++){
        printf("%d",dist[ri][1]);
        for(int ci=2;ci<=M;ci++){
            printf(" %d",dist[ri][ci]);
        }
        printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
