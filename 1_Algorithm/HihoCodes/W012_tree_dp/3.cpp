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
#define MAXV 1010



int N,M;
int val[MAXN];
vector<int> G[MAXN];
int dp[MAXN][MAXN];
int in[MAXN];
void Init(){
    for(int i=1;i<=N;i++)G[i].clear();
    memset(in,0,sizeof(in));
    memset(dp,0,sizeof(dp));
}

void PostOrder(int root){
     for(int i=G[root].size()-1;i>=0;i--){
         PostOrder(G[root][i]);
     }
     for(int i=G[root].size()-1;i>=0;i--){
         int pi=G[root][i];
         for(int m=M;m>1;m--){
             for(int s=1;s<m;s++){
                 int temp=dp[pi][s]+dp[root][m-s];
                 if(dp[root][m]<temp)dp[root][m]=temp;
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
    Init();
    for(int i=1;i<=N;i++){
        scanf("%d",val+i);
        dp[i][1]=val[i];
    }
    int a,b;
    for(int i=1;i<N;i++){
         scanf("%d%d",&a,&b);
         if(a>b){
             swap(a,b);
         }
         G[a].push_back(b);
         in[b]++;
    }
    /*for(int i=1;i<=N;i++){
        if(in[i]==0){
            PostOrder(i);
            break;
        }
    }*/
    PostOrder(1);
    printf("%d\n",dp[1][M]);



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
