#include <iostream>
#include<cstdio>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	__int64 f[35]={0,1,3,5};
	for(int i=4;i<31;i++)
		f[i]=f[i-1]+2*f[i-2];
	int C;
	cin>>C;
	while(C--)
	{
		int n;
		cin>>n;
		cout<<f[n]<<endl;
	}
	return 0;
}
