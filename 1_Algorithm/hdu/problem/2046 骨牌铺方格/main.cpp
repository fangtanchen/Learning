#include <iostream>
#include<cstdio>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	__int64 f[51]={0,1,2};
	for(int i=3;i<=50;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	
	int n;
	while(cin>>n)
	{
		cout<<f[n]<<endl;
	}
	return 0;
}
