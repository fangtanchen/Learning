#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+200;

vector<int> G[2][MAXN];
int light[MAXN],heavy[MAXN],in[MAXN];
int T,N,M;

void Init(){
    memset(light,0,sizeof(light));
    memset(heavy,0,sizeof(heavy));
    memset(in,0,sizeof(in));
    for(int i=0;i<2;i++){
        for(int j=0;j<MAXN;j++){
            G[i][j].clear();
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
        Init();
        scanf("%d%d",&N,&M);
        for(int mi=0;mi<M;mi++){
             int u,v;
             scanf("%d%d",&u,&v);
             G[0][u].push_back(v);
             G[0][v].push_back(u);
             in[u]++;in[v]++;
        }
        int bord=sqrt(N+1);
        for(int ni=1;ni<=N;ni++){
            for(int i=G[0][ni].size()-1;i>=0;i--){
                int v=G[0][ni][i];
                if(in[v]>=bord){
                    G[1][ni].push_back(v);
                }
            }
        }
        int Q;
        scanf("%d",&Q);
        while(Q--){
             int op;
             scanf("%d",&op);
             if(0==op){
                 int u,val;
                 scanf("%d%d",&u,&val);
                 if(in[u]>=bord){
                      heavy[u]+=val;
                 }else{
                     for(int i=G[0][u].size()-1;i>=0;i--){
                         int v=G[0][u][i];
                         light[v]+=val;
                     }
                 }
             }else{
                 int u;
                 scanf("%d",&u);
                 int ans=light[u];
                 for(int i=G[1][u].size()-1;i>=0;i--){
                     int v=G[1][u][i];
                     ans+=heavy[v];
                 }
                 printf("%d\n",ans);
             }
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
