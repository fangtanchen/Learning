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

#define MAXN 105
#define MAXM 10005
#define INF 0x1fffffff
int N,M;

int D[MAXN];
int G[MAXN][MAXN];
bool P[MAXN][MAXN];
bool visited[MAXN];

void Disjkstra(){
     memset(P,false,sizeof(P));
     memset(visited,false,sizeof(visited));
     for(int v=1;v<=N;v++){
         D[v]=G[1][v];
         if(D[v]<INF){
             P[1][v]=P[1][1]=true;
         }
     }
     visited[1]=true;
     D[1]=0;
     for(int i=1;i<N;i++){
          int min=INF;
          int v;
          for(int w=1;w<=N;w++){
              if(!visited[w]){
                  if(D[w]<min){
                      min=D[w];v=w;
                  }
              }
          }
          visited[v]=true;
          for(int w=1;w<=N;w++){
              if(!visited[w]){
                  int temp=D[v]+G[v][w];
                  if(temp<D[w]){
                      D[w]=temp;
                      for(int k=1;k<=N;k++){
                           P[w][k]=P[v][k];
                      }
                    P[w][w]=true;
                  }
              }
          }
     }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d%d",&N,&M),N+M){
             int a,b,c;
             for(int i=1;i<=N;i++){
                 for(int j=1;j<=N;j++){
                     G[i][j]=INF;
                 }
                 G[i][i]=0;
             }
             for(int mi=0;mi<M;mi++){
                 scanf("%d%d%d",&a,&b,&c);
                 G[a][b]=G[b][a]=c;
             }
             Disjkstra();
             printf("%d\n",D[N]);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
