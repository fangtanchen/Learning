#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	__int64 f[25]={0,3,7};
	for(int i=3;i<=20;i++)
	{
		f[i]=f[i-1]+4;
		for(int j=i-2;j>0;j--)
			f[i]+=(2*f[j]);		
	}
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
