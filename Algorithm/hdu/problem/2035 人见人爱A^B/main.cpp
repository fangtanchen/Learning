#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a,b;
	while(cin>>a>>b,a||b)
	{
		a=a%1000;
		int result=1;
		for(int i=1;i<=b;i++)
		{
			result*=a;
			result%=1000;
		}
		cout<<result<<endl;
	}
	return 0;
}
