#include <iostream>
#include<cstring>
#include<cstdio>
#include<stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char sot[]="0123456789ABCDEF";
int main(int argc, char** argv) {
	int n,r;
	while(cin>>n>>r)
	{
		int a[32];
		int flag=(n<0?1:0);	
		int i=0;
		if(flag)
		{
			cout<<"-";
			n=-n;
		}
		while(n)
		{
			a[i++]=n%r;
			n/=r;
		}
		
		for(i--;i>=0;i--)
		{
			cout<<sot[a[i]];
		}
		cout<<endl;
	}
	return 0;
}
