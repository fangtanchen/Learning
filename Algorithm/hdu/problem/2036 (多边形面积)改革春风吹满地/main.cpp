#include <iostream>
#include<cstdlib>
#include<cstdio>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(cin>>n,n)
	{
		int x[101],y[101];
		
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];
		float sum=0;
		x[n]=x[0];
		y[n]=y[0];
		for(int i=0;i<n;i++)
		{
			sum+=(x[i]*y[i+1]-x[i+1]*y[i]);
		}
		
		sum*=0.5;
		printf("%.1f\n",sum);
		
	}
	return 0;
}
