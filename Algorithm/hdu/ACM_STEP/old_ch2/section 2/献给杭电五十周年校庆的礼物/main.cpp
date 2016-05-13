#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int f[500]={1};
int fi=0;
int main(int argc, char** argv) {
	int n;
	while(cin>>n)
	{
		cout<<((n*n*n+5*n+6)/6)<<endl;;
	}
	return 0;
}
