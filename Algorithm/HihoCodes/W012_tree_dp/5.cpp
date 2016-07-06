#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=105;
int N,M;
int val[MAXN];
int in[MAXN];
vector<int> G[MAXN];
int dp[MAXN][MAXN];

void Init(){
    memset(in,0,sizeof(in));
    memset(val,0,sizeof(val));
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=N;i++){
        G[i].clear();
    }
}

void PostOrder(int node){
    for(int i=G[node].size()-1;i>=0;i--){
        int child=G[node][i];
        PostOrder(child);
    }
    for(int i=G[node].size()-1;i>=0;i--){
        int child=G[node][i];
        for(int m=M;m>=2;m--){
            for(int k=1;k<m;k++){
                int tmp=dp[node][k]+dp[child][m-k];
                if(tmp>dp[node][m])dp[node][m]=tmp;
            }
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
         scanf("%d",val+i);
         dp[i][1]=val[i];
    }
    for(int i=1;i<N;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        G[a].push_back(b);
    }
    PostOrder(1);
    printf("%d\n",dp[1][M]);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
