#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		int state=1;
		for(int i=2;i<=n;i++)
		{
			if(n%i==0)state^=1;
		}
		
		cout<<state<<endl;
	}
	return 0;
}
