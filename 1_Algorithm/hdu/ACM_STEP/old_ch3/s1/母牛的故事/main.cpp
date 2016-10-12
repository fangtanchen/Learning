#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	__int64 f[60];
	f[0]=0;
	f[1]=1;
	f[2]=2;
	f[3]=3	;
	f[4]=4;
	for(int i=5;i<55;i++)
		f[i]=f[i-1]+f[i-3];
	int n;
	while(cin>>n,n)
		cout<<f[n]<<endl;
	return 0;
}
