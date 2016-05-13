#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gcd(int x,int y)
{
	if(x%y==0)return y;
	else return gcd(y,x%y);
}

int main(int argc, char** argv) {
	int p,q;
	while(cin>>p>>q)
	{
		if(p>q)
		{
			int temp=p;
			p=q;
			q=temp;
		}
		int result=p+q-gcd(q,p);
		cout<<result<<endl;
	}
	return 0;
}
