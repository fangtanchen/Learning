#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gcd(int x,int y)
{
	int r=x%y;
	while(r)
	{
		x=y;
		y=r;
		r=x%y;		
	}
	return y;
	
}

int main(int argc, char** argv) {
	int p;
	cin>>p;
	while(p--)
	{
		int n,m;
		cin>>m>>n;
		int res=gcd(m,n);
		if(res!=1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
