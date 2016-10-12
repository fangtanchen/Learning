#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct road
{
	int x;
	int y;
	int val;
}Road;

Road road[110];
int f[101];

int cmp(const void* a,const void* b)
{
	Road* pa=(Road*)a;
	Road* pb=(Road*)b;
	if(pa->val!=pb->val)return pa->val-pb->val;
	else if(pa->x!=pb->x)return pa->x-pb->x;
	else return pa->y-pb->y;
}

int pref(int x)
{
	if(x==f[x])	return x;
	else return f[x]=pref(f[x]);
}

int main(int argc, char** argv) {
	int n,m;
	
	//因为输入的村庄是1，2，。。。n，所以不能从0开始计数，否则有错 
	while(cin>>n>>m,n)
	{
		int ans=0;
		for(int i=1;i<=m;i++)
			f[i]=i;
		for(int i=1;i<=n;i++)
			cin>>road[i].x>>road[i].y>>road[i].val;
		qsort(road+1,n,sizeof(road[0]),&cmp);
		int count=m-1;
		for(int i=1;i<=n;i++)
		{
			int r1=pref(road[i].x);
			int r2=pref(road[i].y );
			if(r1==r2)continue;
			else
			{
				count--;
				ans+=road[i].val;
				f[r1]=r2;
			}
		}
		if(!count)cout<<ans<<endl;
		else cout<<"?"<<endl;
		
	}
	return 0;
}
