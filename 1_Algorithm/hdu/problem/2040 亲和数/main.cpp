#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int f(int n)
{
	int sum=1;
	int max=n/2;
	for(int i=2;i<=max;i++)
	{
		if(n%i==0)sum+=i;
	}
	return sum;
}

int main(int argc, char** argv) {
	int m;
	cin>>m;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		if(f(a)==b||f(b)==a)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
