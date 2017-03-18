#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef pair<int,int> pii;
const int MAXN=14;
const int INF=0x1f1f1f1f;
const int dir[4][2]={-1,0,1,0,0,-1,0,1};

char G[14][14];
bool vis[14][14];
int color[14][14],numcolor;
int dist[13][13][13][13];
int T,N,M;

int BFS(int x,int y){
    memset(vis,false,sizeof(vis));
    queue<pii > Q;
    Q.push(make_pair(x,y));
    dist[x][y][x][y]=0;
    int ret=0;
    while(!Q.empty()){
        pii now=Q.front();
        Q.pop();
        int ri=now.first,ci=now.second;
        vis[ri][ci]=true;
        ret=max(ret,dist[x][y][ri][ci]);
        for(int di=0;di<4;di++){
             int tmpri=ri+dir[di][0];
             int tmpci=ci+dir[di][1];
             if((tmpri>=0)&&(tmpri<N)&&(tmpci>=0)&&(tmpci<M)
                     &&(!vis[tmpri][tmpci])
                     &&(G[tmpri][tmpci]=='#')){
                 dist[x][y][tmpri][tmpci]=dist[x][y][ri][ci]+1;
                 Q.push(make_pair(tmpri,tmpci));
             }
        }
    }
    return ret;
}
int TagColor(int ri,int ci,int c){
    queue<pii > Q;
    Q.push(make_pair(ri,ci));
    color[ri][ci]=c;

    while(!Q.empty()){
        pii now=Q.front();
        Q.pop();
        for(int di=0;di<4;di++){
             int tmpri=now.first+dir[di][0];
             int tmpci=now.second+dir[di][1];
             if((tmpri>=0)&&(tmpri<N)&&(tmpci>=0)&&(tmpci<M)
                     &&(color[tmpri][tmpci]==-1)&&(G[tmpri][tmpci]=='#')){
                 color[tmpri][tmpci]=c;
                 Q.push(make_pair(tmpri,tmpci));
             }
        }
    }
    return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        printf("Case %d: ",ti);
         scanf("%d%d",&N,&M);
         for(int ri=0;ri<N;ri++){
             scanf("%s",G[ri]);
         }
         numcolor=0;
         memset(color,-1,sizeof(color));
         for(int ri=0;ri<N;ri++){
             for(int ci=0;ci<M;ci++){
                 if(G[ri][ci]!='#')continue;
                 if(color[ri][ci]==-1){
                     TagColor(ri,ci,++numcolor);
                 }
             }
         }
         if(numcolor>2||numcolor==0){
              printf("-1\n");
              continue;
         }
         memset(dist,0x1f,sizeof(dist));
         int a[3]={INF,INF,INF};
         for(int ri=0;ri<N;ri++){
             for(int ci=0;ci<M;ci++){
                 if(G[ri][ci]!='#')continue;
                 a[color[ri][ci]]=min(BFS(ri,ci),a[color[ri][ci]]);
             }
         }
         if(numcolor==2){
             int kk=a[1]+a[2];
             printf("%d\n",kk);
         }else{
              int ans=INF;
              for(int ai=0;ai<N;ai++){
                  for(int aj=0;aj<M;aj++){
                      if(G[ai][aj]!='#')continue;
                      for(int bi=ai;bi<N;bi++){
                          for(int bj=0;bj<M;bj++){
                              if(G[bi][bj]!='#')continue;
                              int tmp=0;
                              for(int ri=0;ri<N;ri++){
                                  for(int ci=0;ci<M;ci++){
                                      if(G[ri][ci]!='#')continue;
                                      tmp=max(tmp,
                                              min(dist[ai][aj][ri][ci],dist[bi][bj][ri][ci]));
                                  }
                              }
                              ans=min(tmp,ans);
                          }
                      }
                  }
              }
              if(ans==INF)ans=-1;
              printf("%d\n",ans);
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
