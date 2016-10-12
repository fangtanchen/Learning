#include <iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Node
{
	int ni;
	double ani;
}Node;
std::vector< Node > mapa;
double mapb[2111];
int main(int argc, char** argv) {
	int k1,k2;
	while(cin>>k1)
	{
		mapa.resize(k1);
		for(int i=0;i<k1;i++)
			cin>>mapa[i].ni>>mapa[i].ani;
		memset(mapb,0,sizeof(mapb));
		cin>>k2;
		int ni=0;
		double ani=0;
		int max=0;
		for(int i=0;i<k2;i++)
		{
			cin>>ni>>ani;
			for(int j=0;j<k1;j++)
			{
				int t1=mapa[j].ni+ni;
				if(t1>max)max=t1;
				double ati=ani*mapa[j].ani;
				mapb[t1]+=ati;
			}
		}
		int count=0;
		for(int i=max;i>=0;i--)
		{
			if(mapb[i])count++;
		}
		cout<<count;
		for(int i=max;i>=0;i--)
		{
			if(mapb[i])
				printf(" %d %.1f",i,mapb[i]);
		}
		cout<<endl;
	}
	return 0;
}
