#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

typedef struct point 
{
	int x;
	int y;
} Point;

int minS(int x,int y)
{
	return (x>y?x:y);
}

int dfs(int x,int y)
{	
	if(x==0&&y==0)return 0;
	if(x<0||x>=N) return -1;
	if(y<0||y>=M) return -1;
		
	
	if(map[x][y]=='X') return -1;
	else
	{
		int t=min
	}
}

char map[100][100];

int main(int argc,char** argv)
{
	int N,M;
	while(EOF!=scanf("%d%d",&N,&M))
	{
		getchar();
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				scanf("%c",&map[i][j]);
			}
			getchar();
		}
		getchar();
		
		
	}
	return 0;
}
