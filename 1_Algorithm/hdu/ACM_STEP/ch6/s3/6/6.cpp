#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=110;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool G[MAXN][MAXN];
bool vis[MAXN*MAXN];
int mp[MAXN*MAXN];
int N,M,K;

void Init(){
    memset(G,true,sizeof(G));
    memset(vis,false,sizeof(vis));
    memset(mp,-1,sizeof(mp));
}


bool InMap(int ri,int ci){
    return (ri>=1)&&(ri<=N)
        &&(ci>=1)&&(ci<=M)&&G[ri][ci];
}

int FindPath(int u){
    int ri=u/100;
    int ci=u%100;
    for(int di=0;di<4;di++){
        int tmpri=ri+dir[di][0];
        int tmpci=ci+dir[di][1];
        if(!InMap(tmpri,tmpci))continue;
        int v=100*tmpri+tmpci;
        if(vis[v])continue;
        vis[v]=true;
        if(mp[v]==-1||FindPath(mp[v])){
             mp[u]=v;
             mp[v]=u;
             return 1;
        }
    }
    return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

        int cai=0;
        while(scanf("%d%d",&N,&M),N||M){
            //if(cai)printf("\n");
             Init();
             scanf("%d",&K);
             for(int ki=0;ki<K;ki++){
                 int u,v;
                 scanf("%d%d",&u,&v);
                 G[u][v]=false;
             }
             int ans=0;
             for(int ri=1;ri<=N;ri++){
                 for(int ci=1;ci<=M;ci++){
                     int u=ri*100+ci;
                     if(((ri+ci)%2==1)&&(G[ri][ci])&&(mp[u]==-1)){
                         memset(vis,false,sizeof(vis));
                         vis[u]=true;
                         ans+=FindPath(u);
                     }
                 }
             }
             printf("%d\n",ans);
             for(int ri=1;ri<=N;ri++){
                 for(int ci=1;ci<=M;ci++){
                     int tmp=ri*100+ci;
                     if(mp[tmp]!=-1){
                          int ntmp=mp[tmp];
                          int nri=ntmp/100;
                          int nci=ntmp%100;
                          printf("(%d,%d)--(%d,%d)\n",ri,ci,nri,nci);
                          mp[tmp]=mp[ntmp]=-1;
                     }
                 }
             }
             cai++;
             printf("\n");
        }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
