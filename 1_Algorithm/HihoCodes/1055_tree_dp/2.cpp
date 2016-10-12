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

#define MAXN 110

int N,M;
int dp[MAXN][MAXN];
int val[MAXN];
vector<int> g[MAXN];

void Init(){
     memset(dp,0,sizeof(dp));
     memset(val,0,sizeof(val));
     for(int i=1;i<=N;i++)
         g[i].clear();

}

void PostOrder(int root){
    if(g[root].empty()){
        dp[root][1]=val[root];
        return;
    }
    for(int i=g[root].size()-1;i>=0;i--){
        PostOrder(g[root][i]);
        for(int mi=M-1;mi>=1;mi--){
            int max=0;
            for(int j=0;j<=mi;j++){
                int temp=dp[g[root][i]][j]+dp[root][mi-j];
                if(temp>max)max=temp;
            }
            dp[root][mi]=max;
        }
    }
    for(int mi=M;mi>=1;mi--)
        dp[root][mi]=dp[root][mi-1]+val[root];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    Init();
    for(int i=1;i<=N;i++){
         scanf("%d",val+i);
    }
    int a,b;
    for(int ni=1;ni<N;ni++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
    }
    PostOrder(1);
    printf("%d\n",dp[1][M]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
