#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gcd(int x,int y)
{
	if(0==x%y)return y;
	else return gcd(y,x%y);
}

int main(int argc, char** argv) {
	int m,n;
	while(cin>>m>>n)
	{		
		int div=0;
		if(m>n)div=gcd(m,n);
		else div= gcd(n,m);
		cout<<m/div*n<<endl;
	}
	return 0;
}
