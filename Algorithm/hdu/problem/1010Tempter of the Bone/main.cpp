#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct point
{
	int x;
	int y;
}Point; 

int fa(int x,int y)
{
	if(x>y)return x-y;
	else return y-x;
}
char a[20][20];
Point spt,dpt;
int m,n,t;
int i,j;
int p,q;
int sum;

Point pt[4]={{1,0},{0,1},{-1,0},{0,-1}};
int f(int x,int y,int second)
{
	int dis=0;
	int fi=0;
	if(a[x][y]=='X'
	||x<1
	||y<1
	||x>n
	||y>m	)	
	return 0;//有障碍物或者跑出边界
	
	dis = fa(x,dpt.x)+fa(y,dpt.y);
	if(dis>second)return 0;
	
	if(0==second) return (x==dpt.x)&&(y==dpt.y);
	else 
	{
		if(a[x][y]=='D')return 0;
		a[x][y]='X';//a[x][y]='X';打错了哥哥。活该 
					
		for(fi=0;fi<4;fi++)
		{
			if(f(x+pt[fi].x,y+pt[fi].y,second-1))
				return 1;
		}
			
		a[x][y]='.';
		return 0;
		
	}
}

int main(int argc, char** argv) {
	
	sum=0;
	while(cin>>n>>m>>t,m||n||t)
	{
	
		for(i=1;i<=n;i++)
		{	
		//	cin>>a[0][0];
			for(j=1;j<=m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='S')
				{
					spt.x=i;
					spt.y=j;
				}
				if(a[i][j]=='D')
				{
					dpt.x=i;
					dpt.y=j;
				}
				if(a[i][j]=='.')
				{
					sum++;
				}
			}
		//	cin>>a[0][0];
		}
		if(dpt.x<spt.x)
		{
			p=-1;
		}
		else p=1;
		if(dpt.y<spt.y)
		{
			q=-1;
		}
		else q=1;
		
		if(sum+1<t || (t+spt.x+spt.y+dpt.x+dpt.y)%2==1)printf("NO\n"); 
		if(t<=sum&&f(spt.x,spt.y,t))printf("YES\n");
		else	printf("NO\n");
	}
	
	return 0;
}
