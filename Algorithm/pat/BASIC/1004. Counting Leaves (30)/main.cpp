#include <iostream>
#include<cstdio>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
std::vector< std::vector<int> > map;
std::vector<int > count;
int counti=1;
int hir_t=0;
void dfs(int rt,int hir)
{
	if(hir>hir_t)
		hir_t=hir;
	int num=map[rt][0];
	if(!num)
	{
		count[hir]++;
		return;	
	}
	for(int i=1;i<=num;i++)
	{
		int t=map[rt][i];
		dfs(t,hir+1);
	}
}

int main(int argc, char** argv) {
	int n,m;
	while(cin>>n>>m)
	{
		hir_t=0;
		map.resize(n+1);
		for(int i=0;i<=n;i++)
			map[i].assign(n+1,0);
		count.resize(n+1);
		count.assign(n+1,0);
		for(int i=0;i<m;i++)
		{
			int a,cnt,b;
			cin>>a>>cnt;
			while(cnt--)
			{
				cin>>b;			
				map[a][0]++;
				map[a][map[a][0]]=b;			
			}			
		}
		
		count[1]=0;
		dfs(1,1);
		cout<<(int)count[1];
		for(int i=2;i<=hir_t;i++)
			cout<<" "<<(int)count[i];
		cout<<endl;
	}
	
	return 0;
}
