#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int gcd(int m,int n)
{
	int r;
	while(r=m%n)
	{
		m=n;
		n=r;
	}
	return n;
}

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a/=b;
		int c=0;
		for(int i=2;i<1000000;i++)
		{
			if(1==gcd(i,a))
			{
				c=i*b;
				break;
			}
		}
		cout<<c<<endl;
	}
	
	return 0;
}
