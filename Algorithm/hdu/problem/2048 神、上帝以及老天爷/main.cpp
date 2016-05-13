#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	__int64 t[21]={1,1,2};
	for(int i=3;i<21;i++)
	{
		t[i]=i*t[i-1];
	}
	double f[21]={1,0};
	for(int i=2;i<21;i++)
	{
		double sum=0;
		for(int j=1;j<=i;j++)
		{
			sum+=f[i-j]/t[j];
		}
		f[i]=1-sum;
	}
	int c;
	cin>>c;
	while(c)
	{
	
		int n;
		while(cin>>n)
		{
			printf("%.2lf%c\n",f[n]*100,'%');
		}
		c--;
	}
	return 0;
}
