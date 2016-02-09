#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
__int64 f[55];
int main(int argc, char** argv) {
	f[1]=1;
	f[2]=2;
	for(int i=3;i<51;i++)
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
