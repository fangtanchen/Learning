#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//#include<stdbool.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAXNUM 110
typedef struct Room
{
	int bugs,pos;
}Room;


int M,N;

int adj[MAXNUM][MAXNUM];
int dp[MAXNUM][MAXNUM];
int visited[MAXNUM];
//int i,j,k;

int max(int x,int y)
{
	if(x>y)return x;
	else return y;
}

Room rooms[MAXNUM];

void dfs(int root)
{
	int u;
	int i,j,k;
	
	int num=(rooms[root].bugs+19)/20;
	int count=0;
	visited[root]=1;
	for(i=num;i<=M;i++)
		dp[root][i]=rooms[root].pos;
	count = adj[root][0];
	for(i=1;i<=count;i++)
	{
		u=adj[root][i];
		if(visited[u])continue; 
		dfs(u);//i是全局变量时，这里在调用函数是会修改i的值引起错误
		for(j=M;j>=num;j--)
		{
			for(k=1;k+j<=M;k++)
			{
				if(dp[u][k])
					dp[root][j+k]=max(dp[root][j+k],dp[root][j]+dp[u][k]);
			}
		}
	}
}


int main(int argc, char *argv[]) {
	int s,d;
	int i,j,k;
	while(scanf("%d%d",&N,&M), M!=-1||N!=-1)
	{
		
		memset(adj,0,sizeof(adj));
		memset(visited,0,sizeof(visited));
		memset(dp,0,sizeof(dp));
		
		for(i=1;i<=N;i++)
		{
			scanf("%d%d",&rooms[i].bugs,&rooms[i].pos);
		}
		for(i=1;i<N;i++)
		{
			scanf("%d%d",&s,&d);
			adj[s][0]++;
			adj[d][0]++;
			adj[s][adj[s][0]]=d;
			adj[d][adj[d][0]]=s;
		}
		if(M==0)
		{
			printf("0\n");
			continue;
		}
		dfs(1);
		printf("%d\n",dp[1][M]);
	}
	return 0;
}
