#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int f[500];
	while(cin>>n)
	{
		f[0]=1;
		int flen=1;
		int max=2*n;
		for(int i=n+2;i<=max;i++)
		{
			int carry=0;
			for(int j=0;j<flen;j++ )
			{
				int temp=f[j]*i+carry;
				f[j]=temp%10000;
				carry=temp/10000;
			}
			if(carry)
			{
				f[flen]=carry;
				flen++;
			}
		}
		
		for(int i=2;i<=n;i++)
		{
			int carry=0;
			for(int j=flen-1;j>=0;j--)
			{
				int temp=carry*10000+f[j];
				f[j]=temp/i;
				carry=temp%i;
			}
			if(!f[flen-1])flen--;
		}
		cout<<f[flen-1];
		for(int i=flen-2;i>=0;i--)
			printf("%04d",f[i]);
		cout<<endl;
		
	}
	return 0;
}
