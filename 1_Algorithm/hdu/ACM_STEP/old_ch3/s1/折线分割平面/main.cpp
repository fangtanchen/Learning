#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int C;
	cin>>C;
	while(C--)
	{
		int n;
		cin>>n;
		cout<<2*n*n-n+1<<endl;
	}
	return 0;
}
