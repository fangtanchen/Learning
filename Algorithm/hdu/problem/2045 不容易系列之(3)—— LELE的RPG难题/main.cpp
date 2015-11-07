#include <iostream>
#include<cstdio>

using namespace std;
/* run this program usin2,g the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	__int64 f[51]={0,3,6,6};
	for(int i=4;i<=50;i++)
	{
		f[i]=2*f[i-2]+f[i-1];
	}
	while(cin>>n)
	{
		printf("%I64d\n",f[n]);
	}
	return 0;
}
