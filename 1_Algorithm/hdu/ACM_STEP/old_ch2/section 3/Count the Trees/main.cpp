#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int f[3000];
	int n;
	while(cin>>n,n)
	{
		int max=2*n;
		f[0]=1;
		int flen=1;
		for(int i=n+2;i<=max;i++)
		{
			int carry=0;
			for(int j=0;j<flen;j++)
			{
				int temp=carry+f[j]*i;
				f[j]=temp%10000;
				carry=temp/10000;
			}
			if(carry)
			{
				f[flen]=carry;
				flen++;
			}
		}
		printf("%d",f[flen-1]);
		for(int i=flen-2;i>=0;i--)
			printf("%04d",f[i]);
		printf("\n");
	}
	return 0;
}
