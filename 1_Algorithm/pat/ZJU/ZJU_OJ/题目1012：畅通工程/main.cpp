#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct point
{
	int x;
	int y;
}Point;


int main(int argc, char** argv) {
	int n,m;
	Point pt[1001];
	while(scanf("%d",&n)!=EOF&&n)
	{
		scanf("%d",&m);
		int rcount=0;
		memset(pt,0,sizeof(pt));
		for(int i=1;i<=m;i++)
		{
			cin>>pt[i].x>>pt[i].y;
			int flag=1;
			if(pt[i].x==pt[i].y )
				continue;
			for(int j=i-1;j>0;j--)
			{
				if((pt[i].x==pt[j].x&&pt[i].y==pt[j].y)
				||(pt[i].x==pt[j].y&&pt[i].y==pt[j].x))
				{
					flag=0;
					break;
				}
			}
			rcount+=flag;			
		}
		int res=0;
		res = n-1-rcount;
		if(res<0)
			cout<<0<<endl;
		else cout<<res<<endl;
		
	}
	return 0;
}
