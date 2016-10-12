#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	cin>>N;
	int a,b;
	while(N)
	{
		cin>>a>>b;
		cout<<a+b<<endl;
		N--;
	}
	return 0;
}
