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

#define MAXN 200
#define MAXM 1000
#define INF 0x1fffffff

bool visited[MAXN];
bool P[MAXN][MAXN];
int G[MAXN][MAXN];
int D[MAXN];
int N,M;

void Dijkstra(int st){
    memset(visited,false,sizeof(visited));
     memset(P,false,sizeof(P));
     for(int v=0;v<N;v++){
         D[v]=G[st][v];
         if(D[v]<INF){
             P[v][st]=true;
             P[v][v]=true;
         }
     }
     visited[st]=true;
     D[st]=0;
     for(int i=1;i<N;i++){
          int min=INF;
          int v=-1;
          for(int w=0;w<N;w++){
              if(!visited[w]){
                  if(D[w]<min){
                      min=D[w];
                      v=w;
                  }
              }
          }
          if(v<0)return;
          visited[v]=true;
          for(int w=0;w<N;w++){
              if(!visited[w]) {
                   int temp=D[v]+G[v][w];
                   if(temp<D[w]){
                       D[w]=temp;
                       for(int i=0;i<N;i++){
                            P[w][i]=P[v][i];
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
        while(EOF!=scanf("%d%d",&N,&M)){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    G[i][j]=INF;
                }
                G[i][i]=0;
            }
             int a,b,x;
             for(int mi=0;mi<M;mi++){
                  scanf("%d%d%d",&a,&b,&x);
                  if(x<G[a][b]){ G[a][b]=G[b][a]=x;};
             }
             int S,T;
             scanf("%d%d",&S,&T);
             Dijkstra(S);
             printf("%d\n",D[T]<INF?D[T]:-1);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
