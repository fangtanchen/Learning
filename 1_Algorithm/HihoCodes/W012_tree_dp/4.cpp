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
#define MAXN 105
int N,M;
int val[MAXN];
int dp[MAXN][MAXN];
vector<int> G[MAXN];


void Init(){
     memset(val,0,sizeof(val));
     memset(dp,0,sizeof(dp));
     for(int i=1;i<=N;i++){
         G[i].clear();
     }
}

void PostOrder(int root){
    for(int i=G[root].size()-1;i>=0;i--){
        PostOrder(G[root][i]);
    }
    for(int i=G[root].size()-1;i>=0;i--){
        int k=G[root][i];
        for(int m=M;m>1;m--){
            for(int s=1;s<m;s++){
                int temp=dp[root][m-s]+dp[k][s];
                if(temp>dp[root][m])dp[root][m]=temp;
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
