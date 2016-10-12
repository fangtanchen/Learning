#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	//double f[60]={0,1,2};
	__int64 f[60]={0,1,2};
	for(int i=3;i<60;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	cin>>n;
	while(n)
	{
		int a,b;
		cin>>a>>b;
		int m=b-a;
		
		printf("%I64d\n",f[m]);
		n--;
	}
	return 0;
}
