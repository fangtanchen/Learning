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
const int MAXN=110;
const int MAXM=MAXN*MAXN;
const int INF=0x1f1f1f1f;
const int dir[4][2]={-1,0,1,0,0,-1,0,1};

char G[MAXN][MAXN];
int path[MAXM];
int N,M;
bool in[MAXM];
int dist[MAXM];
queue<int> Q;

bool InMap(int ri,int ci){
    return (ri>=0)&&(ri<N)&&(ci>=0)&&(ci<M);
}

void BFS(){
    memset(path,-1,sizeof(path));
    memset(in,false,sizeof((in)));
    memset(dist,0x1f,sizeof(dist));
    while(!Q.empty())Q.pop();
    Q.push(0);
    in[0]=true;
    dist[0]=0;
    while(!Q.empty()){
         int now=Q.front();
         Q.pop();
         in[now]=false;
         int ri=now/MAXN,ci=now%MAXN;
         int tmpdist=dist[now]+1;
         if(G[ri][ci]>='0'&&G[ri][ci]<='9')
             tmpdist+=G[ri][ci]-'0';
         for(int di=0;di<4;di++){
              int tmpri=ri+dir[di][0];
              int tmpci=ci+dir[di][1];
              int tmpnow=MAXN*tmpri+tmpci;
              if((!InMap(tmpri,tmpci))||G[tmpri][tmpci]=='X')
                  continue;
              if(tmpdist<dist[tmpnow]){
                  dist[tmpnow]=tmpdist;
                  path[tmpnow]=now;
                  if(!in[tmpnow]){
                      Q.push(tmpnow);
                      in[tmpnow]=true;
                  }
              }
         }
    }
}

int DFS(int now){
    if(path[now]==-1)return 0;
    int k=path[now];
    DFS(k);
    path[k]=now;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d%d",&N,&M)){
            for(int i=0;i<N;i++){
                scanf("%s",G[i]);
            }
            BFS();
            int tmp=((N-1)*MAXN+(M-1));
            if(path[tmp]==-1){
                 printf("God please help our poor hero.\n");
            }else{
                DFS(tmp);
                int kk=0;
                if(G[N-1][M-1]>='0'&&G[N-1][M-1]<='9'){
                    kk=G[N-1][M-1]-'0';
                }
                printf("It takes %d seconds to reach the target position, let me show you the way.\n",dist[tmp]+kk);
                int now=0,ri=0,ci=0;
                int nex=path[now],nri=nex/MAXN,nci=nex%MAXN;
                for(int i=1;i<=dist[tmp];i++){
                    printf("%ds:",i);
                    if(i==dist[nex]){
                        printf("(%d,%d)->(%d,%d)\n",ri,ci,nri,nci);
                        now=nex;ri=nri;ci=nci;
                        nex=path[now],nri=nex/MAXN,nci=nex%MAXN;
                    }else{
                         printf("FIGHT AT (%d,%d)\n",ri,ci);
                    }
                }
                for(int ki=1;ki<=kk;ki++){
                    printf("%ds:FIGHT AT (%d,%d)\n",dist[tmp]+ki,N-1,M-1);
                }
            }
            printf("FINISH\n");
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
