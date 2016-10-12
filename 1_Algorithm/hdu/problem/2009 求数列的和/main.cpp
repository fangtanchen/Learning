#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double n,m;
	while(cin>>n>>m)
	{
		double sum=n;
		for(int i=2;i<=m;i++)
		{
			n=sqrt(n);
			sum+=n;
		}
		printf("%.2lf\n",sum);
		
	}
	return 0;
}
