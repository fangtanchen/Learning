#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	__int64 f[21]={0,0,1};
	for(int i=3;i<21;i++)
	{
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	}
	
	
	int c;
	cin>>c;
	while(c--)
	{
		int m,n;
		cin>>n>>m;
		
		__int64 ct=1;
		for(int i=n-m+1;i<=n;i++)
		{
			ct*=i;
		}
		for(int i=2;i<=m;i++)
		{
			ct/=i;
		}
		printf("%I64d\n",ct*f[m]);
		
	}
	return 0;
}
