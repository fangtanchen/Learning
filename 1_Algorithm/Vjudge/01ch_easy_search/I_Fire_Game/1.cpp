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
int T,N,M;

int BFS(int x,int y){
    memset(vis,false,sizeof(vis));
    queue<pii > Q;
    int id=x*M+y;
    Q.push(make_pair(id,0));
    int ret=0;
    while(!Q.empty()){
        pii now=Q.front();
        ret=max(now.second,ret);
        Q.pop();
        int ri=now.first/M,ci=now.first%M;
        vis[ri][ci]=true;
        for(int di=0;di<4;di++){
             int tmpri=ri+dir[di][0];
             int tmpci=ci+dir[di][1];
             if((tmpri>=0)&&(tmpri<N)&&(tmpci>=0)&&(tmpci<M)
                     &&(!vis[tmpri][tmpci])
                     &&(G[tmpri][tmpci]=='#')){
                 Q.push(make_pair(tmpri*M+tmpci,now.second+1));
             }
        }
    }
    return ret;
}
int TagColor(int ri,int ci,int c){
    queue<pii > Q;
    Q.push(make_pair(ri,ci));

    while(!Q.empty()){
        pii now=Q.front();
        Q.pop();
        color[now.first][now.second]=c;
        for(int di=0;di<4;di++){
             int tmpri=now.first+dir[di][0];
             int tmpci=now.second+dir[di][1];
             if((tmpri>=0)&&(tmpri<N)&&(tmpci>=0)&&(tmpci<M)
                     &&(color[tmpri][tmpci]==-1)&&(G[tmpri][tmpci]=='#')){
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
         if(numcolor>2){
              printf("-1\n");
              continue;
         }
         int ans[3]={INF,INF,INF};
         for(int ri=0;ri<N;ri++){
             for(int ci=0;ci<M;ci++){
                 if(G[ri][ci]!='#')continue;
                 ans[color[ri][ci]]=min(ans[color[ri][ci]],BFS(ri,ci));
             }
         }
         int kk=ans[1];
         if(numcolor==2)kk+=ans[2];
         printf("%d\n",kk);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
