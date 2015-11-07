#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m,n;
	int casei=1;
	while(cin>>m>>n,m||n)
	{
		printf("Test #%d:\n",casei);
		
		if(n>m)
		{
			cout<<0<<endl;
			continue;
		}
		
		int max=m+n;
		int f[500]={1};
		int flen=1;
		for(int i=2;i<=max;i++)
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
		int carry=0;		
		int mul=m+1-n;
		for(int j=0;j<flen;j++)
		{
			int temp=carry+f[j]*mul;
			f[j]=temp%10000;
			carry=temp/10000;
		}
		if(carry)
		{
			f[flen]=carry;
			flen++;
		}
		
		carry=0;
		int div=m+1;
		for(int j=flen-1;j>=0;j--)
		{
			int temp=carry*10000+f[j];
			f[j]=temp/div;
			carry=temp%div;
		}
		if(!f[flen-1])flen--;
		
		
		cout<<f[flen-1];
		for(int i=flen-2;i>=0;i--)
		{
			printf("%04d",f[i]);			
		}
		cout<<endl;
	}
	return 0;
}
