#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a[100]={1};
	int len=0;
	while(EOF!=scanf("%d",&n))
	{
		len=0;//最大下标 
		int max=2*n;
		memset(a,0,sizeof(a));
		a[0]=1;
		for(int i=n+2;i<=max;i++)
		{
			int c=0;
			for(int j=0;j<=len;j++)
			{
				a[j]=a[j]*i+c;
				c=a[j]/10000;
				a[j]%=10000;
			}
			if(c)
			{
				len++;
				a[len]+=c;
			}
		}
		for(int i=n;i>=2;i--)
		{
			int temp1=0,temp2=0;
					
			for(int j=len;j>=0;j--)
			{
				a[j]+=(temp2*10000);
				temp2=a[j]%i;
				a[j]/=i;
			}
			
			if(!a[len])
			{
				len--;
			}
		}
		printf("%d",a[len]);
		for(int i=len-1;i>=0;i--)
		{
			printf("%04d",a[i]);
		}
		printf("\n");
	}
	return 0;
}
