#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct road
{
	int x;	
	int y;
	int val;
}Road;

int cmp(const void* r1,const void* r2)
{
	Road* t1=(Road*)r1;
	Road* t2=(Road*)r2;
	if(t1->val!=t2->val) return t1->val-t2->val;
	else if(t1->x!=t2->x) return t1->x-t2->x;
	else return t1->y-t2->y;
}



int pre[200];
Road r[10000];

int pref(int x)
{	
	if(pre[x]==x)return x;
	else return pre[x]=pref(pre[x]);
}

int main(int argc, char** argv) {
	int n;
	while(cin>>n,n)
	{
		int ans=0;
		int max=n*(n-1)/2;
		for(int i=0;i<max;i++)
			cin>>r[i].x>>r[i].y>>r[i].val;		
		qsort(r,max,sizeof(r[0]),&cmp);		
		for(int i=1;i<100;i++)	
			pre[i]=i;
		
		int rctn=1;
		for(int i=0;i<max&&rctn<n;i++)					
		{
			int pre_x=pref(r[i].x);
			int pre_y=pref(r[i].y );
			if(pre_x==pre_y)continue;
			//如果是路径 
			ans+=r[i].val ;
			rctn++;
			//加入集合
			pre[pre_x] =pre_y;
		}
		cout<<ans<<endl;
	}
	return 0;
}
