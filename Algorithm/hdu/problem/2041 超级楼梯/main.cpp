#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int f[41]={0,1,1};
	for(int i=3;i<41;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	cin>>n;
	while(n)
	{
		int m;
		cin>>m;
		if(m==1)printf("0\n");
		else
		{
			printf("%d\n",f[m]);
		}
		n--;
	}
	return 0;
}
