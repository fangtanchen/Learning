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

#define MAXN 102
#define MAXM 3005
#define INF 0x1FFFFFFF
typedef int ll;

bool P[MAXN][MAXN][MAXN];
ll D[MAXN][MAXN];
ll G[MAXN][MAXN];
ll a[MAXM],b[MAXM];
ll n,m;
ll sum[MAXN];
ll sumx[MAXN];
ll sumy[MAXN];

void init(){
    for(ll i=0;i<n;i++){
         for(ll j=0;j<n;j++){
            G[i][j]=INF;
         }
        G[i][i]=0;
    }
}
void Floyd(){
    ll tte=INF;
     memset(P,false,sizeof(P));
     for(ll i=0;i<n;i++){
         for(ll j=0;j<n;j++){
             D[i][j]=G[i][j];
             if(G[i][j]<INF){
                 D[i][j]=G[i][j];
                 P[i][j][i]=P[i][j][j]=true;
             };
         }
     }
     for(ll k=0;k<n;k++){
         for(ll j=0;j<n;j++){
             for(ll i=0;i<n;i++){
                 ll temp=D[i][k]+D[k][j];
                 if(temp<D[i][j]){
                      D[i][j]=temp;
                      for(ll p=0;p<n;p++){
                           P[i][j][p]=P[i][k][p]||P[k][j][p];
                      }
                 }
             }
         }
     }
}

bool Pd[MAXN][MAXN];
void Dijkstra(int st, int* pt){
     int visited[MAXN];
     memset(visited,false,sizeof(visited));
     memset(Pd,false,sizeof(Pd));
     for(int i=0;i<n;i++){
         pt[i]=G[st][i];
         if(pt[i]<INF){
             Pd[i][i]=Pd[i][st]=true;
         }
     }
     pt[st]=0;
     visited[st]=true;
     ll v=0;
     for(ll i=0;i<n;i++){
          if(i==st)continue;
          ll min=INF;
          for(ll w=0;w<n;w++){
              if(!visited[w])
                  if(pt[w]<min){
                      v=w;min=pt[w];
                  }
          }
          visited[i]=true;
          for(int w=0;w<n;w++){
              if(!visited[w]&&(min+G[v][w]<pt[w])){
                pt[w] =min+G[v][w];
                for(int i=0;i<n;i++)
                    Pd[w][i]=Pd[v][i];
                Pd[w][w]=true;
              }
          }
     }
}


int  main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

        while(EOF!=scanf("%d%d",&n,&m)){
             init();
             for(ll mi=0;mi<m;mi++){
                 scanf("%d%d",a+mi,b+mi);
                 G[a[mi]][b[mi]]=G[b[mi]][a[mi]]=1;
             }
             memset(sum,0,sizeof(sum));
             Floyd();
             ll res=0;
             for(ll i=0;i<n;i++){
                 for(ll j=0;j<n;j++){
                      sum[i]+=D[i][j];
                 }
                 res+=sum[i];
             }
             for(ll mi=0;mi<m;mi++){
                 int x=a[mi],y=b[mi];
                 G[x][y]=G[y][x]=INF;
                 Dijkstra(x,sumx);
                 Dijkstra(y,sumy);
                 G[x][y]=G[y][x]=1;
                 ll ans=res-sum[x]-sum[y];
                 ll tx=0,ty=0;
                 for(int i=0;i<n;i++){
                     tx+=sumx[i];
                     ty+=sumy[i];
                 }
                 if(tx>=INF||ty>=INF)printf("INF\n");
                 else printf("%d\n",ans-tx-ty);
             }

        }



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
