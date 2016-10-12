#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>

typedef struct Road
{
	int x;
	int y;
}Road;

std::vector<Road > r;
std::vector<int > f;
std::vector<int > ccity;

int findf(int a)
{
	if(a==f[a])return a;
	else return f[a]=findf(f[a]);
}

int main(int argc,char** argv)
{
	int n,m,k;
	while(cin>>n>>m>>k)
	{		
		r.resize(m+1);
		for(int i=1;i<=m;i++)
		{
			cin>>r[i].x>>r[i].y;
		}
		ccity.resize(k+1);
		for(int i=1;i<=k;i++)
			cin>>ccity[i];
		for(int ci=1;ci<=k;ci++)
		{
			f.resize(n+1);
			for(int i=0;i<=n;i++)
				f[i]=i;		
			int ans=n-2;
			for(int ri=1;ri<=m;ri++)
			{
				if((r[ri].x==ccity[ci])||(r[ri].y==ccity[ci]))
					continue;
				int fx=findf(r[ri].x);
				int fy=findf(r[ri].y);
				if(fx!=fy)
				{
					ans--;
					f[fx]=fy;
				}
			}
			if(ans>0)cout<<ans<<endl;
			else cout<<0<<endl;
		}
	}
	
	return 0;
}
