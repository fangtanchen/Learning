#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAXN 310


vector<int> g[MAXN];
int num_cnt;
int N,M;
int dp[MAXN][MAXN];
int val[MAXN];

void Init(){
    for(int i=1;i<=N;i++){
        g[i].clear();
    }
    num_cnt=N;
    memset(val,0,sizeof(val));
    memset(dp,0,sizeof(dp));
}

void BinaryTree(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int num=q.front();
        q.pop();
        if(g[num].empty())continue;
        if(g[num].size()>2||g[num].size()==1){
            num_cnt++;
            for(int i=g[num].size()-1;i>0;i--){
                g[num_cnt].push_back(g[num][i]);
                g[num].pop_back();
            }
            g[num].push_back(num_cnt);
        }
        q.push(g[num][0]);
        q.push(g[num][1]);
    }
}

void PostOrder(int root){
    dp[root][1]=val[root];
    if(g[root].empty())return ;
    for(int i=g[root].size()-1;i>=0;i--){
        PostOrder(g[root][i]);
    }
    if(root>N){
        for(int i=1;i<=M;i++){
            for(int j=0;j<=i;j++){
                int temp=dp[g[root][0]][j]+dp[g[root][1]][i-j];
                if(temp>dp[root][i])dp[root][i]=temp;
            }
        }
    }else{
        for(int i=1;i<M;i++){
            int max=0;
            for(int j=0;j<=i;j++){
                int temp=dp[g[root][0]][j]+dp[g[root][1]][i-j];
                 if(temp>max)max=temp;
            }
            dp[root][i+1]=val[root]+max;
        }
    }

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
    for(int i=1;i<N;i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
    }
    BinaryTree(1);
    PostOrder(1);
    printf("%d\n",g[1][M]);
    //printf("1");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
