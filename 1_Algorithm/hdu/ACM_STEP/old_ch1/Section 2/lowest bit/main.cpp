#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(cin>>n,n)
	{
		int k=1;
		while(n%2==0)
		{
			k*=2;
			n/=2;
		}
		cout<<k<<endl;
		
	}
	return 0;
}
