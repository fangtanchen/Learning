#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		if(n<=2)
		{
			printf("0.00\n");
			continue;
		}
		
		int max,min,sum=0;
		int m;
		cin>>m;
		max=min=m;
		sum+=m;
		for(int i=2;i<=n;i++)
		{
			cin>>m;
			sum+=m;
			if(m>max)max=m;
			if(m<min)min=m;
		}
		sum=sum-max-min;
		printf("%.2f\n",1.0*sum/(n-2));
	}
	return 0;
}
