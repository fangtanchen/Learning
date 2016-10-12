#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double f[1111];
	int k1=0,k2=0;
	while(cin>>k1)
	{
		memset(f,0,sizeof(f));
		int t;
		float p;
		for(int i=0;i<k1;i++)
		{
			cin>>t>>p;
			f[t]+=p;
		}
		cin>>k2;
		for(int i=0;i<k2;i++)
		{
			cin>>t>>p;
			f[t]+=p;
		}
		int cnt=0;
		for(int i=0;i<1111;i++)
		{
			if(fabs(f[i])>1e-6)cnt++;
		}
		printf("%d",cnt);
		for(int i=1110;i>=0;i--)
		{
			if(fabs(f[i])>1e-6)
				printf(" %d %.1lf",i,f[i]);
		}
		printf("\n");
	}
	return 0;
}
