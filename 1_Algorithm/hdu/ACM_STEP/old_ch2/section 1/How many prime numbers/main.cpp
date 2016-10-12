#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int IsPrime(int a)
{	
	int t=sqrt(a*1.0);
	for(int i=2;i<=t;i++)
	{
		if(a%i==0)return 0;
	}
	return 1;
}

int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		int t;
		int count=0;
		for(int i=0;i<n;i++)
		{
			cin>>t;
			count+=IsPrime(t);
		}
		cout<<count<<endl;
	}
	return 0;
}
