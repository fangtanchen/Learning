#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	double f[31]={3};
	for(int i=1;i<31;i++)
	{
		f[i]=2*(f[i-1]-1);
	}
	
	int n;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		printf("%.lf\n",f[a]);
	}
	return 0;
}
