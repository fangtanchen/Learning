#include <iostream>
#include<cstdio>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define SIZE 1001

int fa[SIZE];
int visit[SIZE];
int find(int a)
{
	if(fa[a]==a)return a;
	else return find(fa[a]);
}

int merge(int a,int b)
{
	int x=find(a);
	int y=find(b);
	fa[x]=fa[y];
}
int main(int argc, char** argv) {
	int n,m;		
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=1;i<=n;i++)	
		{
			fa[i]=i;
			visit[i]=0;
		}
		cin>>m;
		int a,b;
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b;
			merge(a,b);
		}
		for(int i=1;i<=n;i++)
		{
			visit[find(i)]=1;
		}
		int count=0;
		for(int i=1;i<=n;i++)
		{
			if(visit[i])count++;
		}
		cout<<count-1<<endl;
		
	}
	return 0;
}
