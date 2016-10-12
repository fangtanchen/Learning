#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int f[100]={7,2};
	int i;
	for(i=2;i<100;i++)
	{
		f[i]=f[i-1]+f[i-2];
		f[i]=f[i]/10+f[i]%10;
		if(f[i-1]==7&&f[i]==2)break;
	}
	int mod = i-1;
	
	int n;
	while(cin>>n)
	{
		n=n%mod;
		if(0==f[n]%3)printf("yes\n");
		else printf("no\n");
	}
	
	return 0;
}
