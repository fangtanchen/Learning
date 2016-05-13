#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	int a,b;
	while(cin>>N)
	{
		cin>>a;
		for(int i=2;i<=N;i++)
		{
			cin>>b;
			a+=b;
		}
		cout<<a<<endl;	
	}
	return 0;
}
