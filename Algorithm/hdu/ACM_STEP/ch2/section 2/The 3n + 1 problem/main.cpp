#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int func(int n)
{
	int i=1;
	while(true)
	{	
		if(n==1)return i;
		else if(n%2) n=3*n+1;
		else n/=2;
		i++;
	}
}

int main(int argc, char** argv) {
	int a,b;
	while(cin>>a>>b)
	{
		cout<<a<<" "<<b<<" ";
		if(a>b)
		{
			int temp=a;
			a=b;
			b=temp;
		}
		int max=func(a);
		for(int i=a;i<=b;i++)
		{
			int temp=func(i);
			if(max<temp)max=temp;
		}
		cout<<max<<endl;
	}
	return 0;
}
