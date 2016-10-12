#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int i=1;
	int j=1;
	double x[1001];
	double y[1001];
	double radius=11110;
	double temp;
	double a,b;
	cin>>n;
	while(n)
	{
		i=1;
		while(i<=n)
		{
			cin>>x[i]>>y[i];
			i++;
		}
		radius = (y[2]-y[1])*(y[2]-y[1])+(x[2]-x[1])*(x[2]-x[1]);
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				a = (y[i]-y[j]);
				b = (x[i]-x[j]);
				temp = a*a+b*b;
				if(radius>temp)radius = temp;
			}
		}
		cout.precision(2); 
		cout<<sqrt(radius)/2.0<<endl;
		cin>>n;
	}
	return 0;
}
