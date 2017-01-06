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
const int MAXN=20;
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int INF=1000000;

int N,M;
int G[MAXN][MAXN];
int tmpG[MAXN][MAXN];
int ans[MAXN][MAXN];
int tmpans[MAXN][MAXN];


bool InMap(int r,int c){
    return (r>=1)&&(r<=M)&&(c>=1)&&(c<=N);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d%d",&M,&N)){
            for(int i=1;i<=M;i++){
                for(int j=1;j<=N;j++){
                    scanf("%d",G[i]+j);
                }
            }
            int pimax=1<<N;
            int pi;
            int acnt=INF;
            memset(ans,0,sizeof(ans));
            for(pi=0;pi<pimax;pi++){
                 memcpy(tmpG,G,sizeof(G));
                 memset(tmpans,0,sizeof(tmpans));

                 int tmpacnt=0;
                 int tmppi=pi;
                 for(int ci=N;(ci>=1)&&(tmppi);ci--){
                    tmpans[1][ci]=tmppi%2;
                    tmppi/=2;
                 }

                 for(int ci=1;ci<=N;ci++){
                     if(tmpans[1][ci]){
                         tmpacnt+=1;
                         tmpG[1][ci]=1-tmpG[1][ci];
                         for(int di=0;di<4;di++){
                             int tmpri=1+dir[di][0];
                             int tmpci=ci+dir[di][1];
                             if(InMap(tmpri,tmpci)){
                                 tmpG[tmpri][tmpci]=1-tmpG[tmpri][tmpci];
                             }
                         }
                     }
                 }
                 for(int ri=2;ri<=M;ri++){
                     for(int ci=1;ci<=N;ci++){
                         int ttr=ri-1;
                         if(tmpG[ttr][ci]){
                             tmpans[ri][ci]=1;
                             tmpacnt+=1;
                             tmpG[ri][ci]=1-tmpG[ri][ci];
                             for(int di=0;di<4;di++){
                                 int tmpri=ri+dir[di][0];
                                 int tmpci=ci+dir[di][1];
                                 if(InMap(tmpri,tmpci)){
                                     tmpG[tmpri][tmpci]=1-tmpG[tmpri][tmpci];
                                 }
                             }
                         }
                     }
                 }
                 bool flag=true;
                 for(int ci=1;ci<=N;ci++){
                     if(tmpG[M][ci]){
                         flag=false;
                         break;
                     }
                 }
                 if(flag&&(tmpacnt<acnt)){
                     acnt=tmpacnt;
                     for(int ri=1;ri<=M;ri++){
                         for(int ci=1;ci<=N;ci++){
                             ans[ri][ci]=tmpans[ri][ci];
                         }
                     }
                 }
            }
            if(acnt==INF)printf("IMPOSSIBLE\n");
            else{
                for(int ri=1;ri<=M;ri++){
                    printf("%d",ans[ri][1]);
                    for(int ci=2;ci<=N;ci++){
                        printf(" %d",ans[ri][ci]);
                    }
                    printf("\n");
                }
            };
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
