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
const int MAXN=210;
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int INF=0x3f3f3f3f;

class Point{
public:
    int ri,ci;
    Point(int r=0,int c=0){
        ri=r;ci=c;
    }
};

int N,M;
char G[MAXN][MAXN];
Point pl1,pl2;
int dis1[MAXN][MAXN],dis2[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<Point> qe;

bool InMap(int ri,int ci){
    return (ri>=0)&&(ri<N)&&(ci>=0)&&(ci<M)
        &&(!vis[ri][ci])&&(G[ri][ci]!='#');
}

void BFS(Point st,int dist[210][210]){
    memset(vis,false,sizeof(vis));
    memset(dist,0,sizeof(dist));
    while(!qe.empty()){
         qe.pop();
    }
    qe.push(st);
    vis[st.ri][st.ci]=true;
    dist[st.ri][st.ci]=0;
    while(!qe.empty()){
        Point now=qe.front();
        qe.pop();
        for(int di=0;di<4;di++){
            Point nex(now.ri+dir[di][0],now.ci+dir[di][1]);
            if(InMap(nex.ri,nex.ci)){
                vis[nex.ri][nex.ci]=true;
                qe.push(nex);
                dist[nex.ri][nex.ci]=dist[now.ri][now.ci]+1;
            }
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d%d",&N,&M)){
            for(int ri=0;ri<N;ri++){
                scanf("%s",G[ri]);
                for(int ci=0;ci<M;ci++){
                    if(G[ri][ci]=='Y'){
                        pl1=Point(ri,ci);
                    }else  if('M'==G[ri][ci]){
                        pl2=Point(ri,ci);
                    }
                }
            }
            BFS(pl1,dis1);
            BFS(pl2,dis2);
            int ans=INF;
            for(int ri=0;ri<N;ri++){
                for(int ci=0;ci<M;ci++){
                    if('@'==G[ri][ci]){
                        ans=min(ans,11*(dis1[ri][ci]+dis2[ri][ci]));
                    }
                }
            }
            printf("%d\n",ans);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
