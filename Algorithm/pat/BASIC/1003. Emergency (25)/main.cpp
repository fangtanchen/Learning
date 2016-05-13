#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define INF 0x6FFFFFFF

typedef struct Node
{
	int nPath;
	int call;
	int dis;
}Node;

std::vector<Node> city; 
std::vector<std::vector<int> > map;
std::vector<bool> visit;
std::vector<int> team;

int extract_min()
{
	int num=city.size();
	int min=INF;
	int minIdx=-1;
	for(int i=0;i<num;i++)
	{
		if(!visit[i]&&city[i].dis<min)
		{
			minIdx=i;
			min=city[i].dis;
		}
	}
	return minIdx;
}

void Dijkstra(int s,int t)
{
	int num=map.size();
	city.resize(num);
	for(int i=0;i<num;i++)
	{
		city[i].dis=INF;
		city[i].call=0;
		city[i].nPath=0;
	}
	city[s].dis=0;
	city[s].call=team[s];
	city[s].nPath=1;
	visit.assign(num,false);
	
	while(true)
	{
		int u=extract_min();
		if(u==-1) return ;
		
		visit[u]=true;
		if(u==t)return;		
		for(int v=0;v<num;v++)
		{
			if(map[u][v]==INF||visit[v])
				continue;
			if(city[v].dis>city[u].dis+map[u][v])
			{
				city[v].dis=city[u].dis+map[u][v];
				city[v].call=team[v]+city[u].call;
				city[v].nPath=city[u].nPath;
			}
			else if(city[v].dis==city[u].dis+map[u][v])
			{
				city[v].nPath+=city[u].nPath;
				if(city[v].call<city[u].call+team[v])
					city[v].call=city[u].call+team[v];
			}
		}
				
	}
}

int main(int argc, char** argv) {
	int n,m,s,t;
	while(cin>>n>>m>>s>>t)
	{
		map.resize(n);
		for(int i=0;i<n;i++)
			map[i].assign(n,INF);
		team.resize(n);
		for(int i=0;i<n;i++)
			cin>>team[i];
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(map[a][b]>c)
				map[a][b]=map[b][a]=c;
		}
		Dijkstra(s,t);
		cout<<city[t].nPath<<" "<<city[t].call<<endl;
	}
	return 0;
}
