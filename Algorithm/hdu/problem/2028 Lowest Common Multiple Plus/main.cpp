#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int gcd(int x,int y)
{
	if(0==x%y)return y;
	else return (gcd(y,x%y));
}

int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		int x,y;
		cin>>x;
		n--;
		while(n--)
		{
			cin>>y;
			if(x>y)
			{
				x=x/gcd(x,y)*y;
			}
			else
			{
				x=x/gcd(y,x)*y;
			}
		}
		cout<<x<<endl;
	}
	return 0;
}
