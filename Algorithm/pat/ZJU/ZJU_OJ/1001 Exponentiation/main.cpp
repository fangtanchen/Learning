#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char a[6];
	int b[6];
	int c[60];
	int n;
	while(cin>>a>>n)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		c[0]=1;
		int dotpos=0;
		int len;
		for(len=5;a[len]=='0';len--);
		for(int i=len,j=0;i>=0;i--)
		{
			if(a[i]=='.')
			{
				dotpos=len-i;
			}
			else
			{
				b[j]=a[i]-'0';
				j++;
			}
		}
		dotpos=dotpos*n;
		if(!b[len-1])len--;
		int lenRes=len;
		
		for(int i=0;i<len;i++)
			c[i]=b[i];
		
		for(int i=2;i<=n;i++)
		{
			int ct=0;
			for(int j=0;j<len;j++)
			{
				for(int k=0;k<lenRes;k++)
				{
					c[k]=c[k]*b[j]+ct;
					ct=c[k]/10;
					c[k]%=10;
				}
				if(ct)
				{
					c[lenRes]=ct;
					lenRes++;
				}
			}
		}
		if(len<=dotpos)
		{
			printf(".");
			for(int i=dotpos-1;i>=len;i--)
				printf("0");		
		}
		for(int i=len-1;i>=0;i--)
		{
			printf("%d",b[i]);
		}
		printf("\n");
	}
	return 0;
}
