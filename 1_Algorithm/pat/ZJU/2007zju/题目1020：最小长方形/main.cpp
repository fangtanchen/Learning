#include <iostream>
#include<cstdio> 
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x,y;
	int count=0;
	int maxx=0,maxy=0;
	int minx=0,miny=0;
	while(cin>>x>>y)
	{
		if(0==count&&(0==x&&0==y))break;
		if(0==count)
		{
			maxx=minx=x;
			maxy=miny=y;
		}
		if(x==0&&y==0)
		{
			cout<<minx<<" "<<miny<<" "<<maxx<<" "<<maxy<<endl;
			count=0;
		}
		else
		{
			maxx=x>maxx?x:maxx;
			maxy=y>maxy?y:maxy;
			minx=x<minx?x:minx;
			miny=y<miny?y:miny;
			count++;
		}
	}
	return 0;
}
