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
const int MAXN=15;
const int MAXM=10000;
const int INF=0x3f3f3f3f;

int a[MAXN][MAXN],deg[MAXN],dp[1<<MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int N,M;
    scanf("%d%d",&N,&M);
    memset(a,INF,sizeof(a));
    memset(deg,0,sizeof(deg));
    for(int i=0;i<N;i++){
         a[i][i]=0;
    }
    int sum=0;
    for(int i=0;i<M;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        deg[--u]++;
        deg[--v]++;
        sum+=w;
        a[u][v]=min(a[u][v],w);
        a[v][u]=min(a[v][u],w);
    }
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    for(int i=0;i<N;i++){
        if(deg[i]&&(a[0][i]==INF)){
            return 0*printf("-1\n");
        }
    }
    memset(dp,0x3f,sizeof(dp));
    int now=0;
    for(int i=0;i<N;i++){
        if(1&deg[i]){
            now|=(1<<i);
        }
    }
    dp[now]=0;
    for(int i=(1<<N)-1;i>=0;i--){
        for(int j=0;j<N;j++){
            if(((1<<j)&i)==0)continue;
            for(int k=j+1;k<N;k++){
                if(((1<<k)&i)==0)continue;
                dp[i^(1<<j)^(1<<k)]=
                    min(dp[i^(1<<j)^(1<<k)],
                            dp[i]+a[j][k]);
            }
        }
    }
    printf("%d\n",sum+dp[0]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
