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
const int MAXN=3000;
const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

typedef pair<int,int> pii;

bool vis[MAXN][MAXN];
int sx,sy,tx,ty;
pii from[MAXN][MAXN];
pii path[MAXN];
int pathlen;

bool InMap(int x,int y){
    return (x>=0)&&(x<=2000)&&(y>=0)&&(y<=2000);
}

void BFS(pii st,pii ed){
    queue<pii> Q;
    Q.push(st);
    while(!Q.empty()){
        pii u=Q.front();
        Q.pop();
        if(ed==u)return;
        vis[u.first][u.second]=true;
        for(int di=0;di<4;di++){
            int tmpx=u.first+dir[di][0];
            int tmpy=u.second+dir[di][1];
            if(InMap(tmpx,tmpy)&&(!vis[tmpx][tmpy])){
                Q.push(make_pair(tmpx,tmpy));
                from[tmpx][tmpy]=u;
            }
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    sx+=1000;
    sy+=1000;
    tx+=1000;
    ty+=1000;

    pathlen=1;
    path[0]=make_pair(sx,sy);
    for(int it=0;it<4;it++){
        memset(vis,false,sizeof(vis));
        for(int i=0;i<pathlen;i++){
            vis[path[i].first][path[i].second]=true;
        }
        vis[sx][sy]=vis[tx][ty]=false;
        pii ed=make_pair(tx,ty);
        pii st=make_pair(sx,sy);
        BFS(st,ed);
        pii now=ed;
        pii tmp[MAXN];
        int tmplen=0;
        while(now!=st){
            tmp[tmplen++]=now;
             now=from[now.first][now.second];
        }
        for(int i=tmplen-1;i>=0;i--){
            path[pathlen++]=tmp[i];
        }
        swap(sx,tx);swap(sy,ty);
    }
    for(int i=1;i<pathlen;i++){
         int dx=path[i].first-path[i-1].first;
         int dy=path[i].second-path[i-1].second;
         if(dx==0){
             if(dy==-1)printf("D");
             else printf("U");
         }else if(dx==1){
             printf("R");
         }else if(dx==-1){
              printf("L");
         }
    }
    printf("\n");


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
