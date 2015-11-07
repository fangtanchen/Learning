#include<iostream>
#include<cstdio>
using namespace std;

typedef struct point
{
	int x;
	int y;
}Point;

Point spt,dpt;

int n,m,t;
int i,j;
char map[10][10];
int sum;
Point pt[4]={{0,1},{1,0},{0,-1},{-1,0}};

int fa(int x)
{
	if(x>0)return x;
	else return -x;
}

int bfs(int x,int y,int second)
{
	int dis=0;
	int fi=0;
	int x1,y1;
	dis = fa(dpt.x-x)+fa(dpt.y-y);
	if(dis>second)return 0;
	if(second==0) return (map[x][y]=='D');
	else
	{
		if(map[x][y]=='D')return 0;
		map[x][y]='X';
		for(fi=0;fi<4;fi++)
		{
			x1=x+pt[fi].x;
			y1=y+pt[fi].y;
			if(map[x1][y1]=='X'
			||x1<1
			||y1<1
			||x1>n
			||y1>m	)	
			continue;//有障碍物或者跑出边界
			if(bfs(x1,y1,second-1))return 1;
		}
		
		map[x][y]='.';
		return 0;
	}
	
}

int main(int argc, char** argv) {
	
	while(cin>>n>>m>>t,m||n||t)
	{
		sum=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='S')
				{
					spt.x=i;
					spt.y=j;
				}
				if(map[i][j]=='D')
				{
					dpt.x=i;
					dpt.y=j;
				}
				if(map[i][j]=='.')
				{
					sum++;
				}
				
			}
		}
		if(t>sum||((t-fa(spt.x+spt.y-dpt.x-dpt.y)))%2==1)//到达，一定是两点距离加上一个偶数·· 
		{
			printf("NO\n");
		}
		else
		{		
			map[spt.x][spt.y]='X';
			if(bfs(spt.x,spt.y,t))
			{
				printf("YES\n");
			}	
			else
			{
				printf("NO\n");
			}
			map[spt.x][spt.y ]='.';
		}
	}
	
	return 0;	
}
