#include <iostream>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N,M;
	cin>>N;
	while(N)
	{
		cin>>M;
		int a,b;
		cin>>a;
		for(int i=2;i<=M;i++)
		{
			cin>>b;
			a+=b;
		}
		cout<<a<<endl;
		N--;
	}
	return 0;
}
