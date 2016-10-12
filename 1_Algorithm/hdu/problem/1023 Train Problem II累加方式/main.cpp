#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a[101][11];
	
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		a[1][0]=a[2][0]=1;
		int len=0;
		for(int i=3;i<=n;i++)
		{
			for(int j=2;j<i;j++)
			{
				int c=0;
				for(int k=0;k<=len;k++)
				{
					a[j][k]+=a[j-1][k]+c;
					c=a[j][k]/100000000;
					a[j][k]%=100000000;
				}
				
				if(c)
				{
					len++;
					a[j][len]+=c;
				}
				
			}
			
			for(int j=len;j>=0;j--)
			{
				a[i][j]=a[i-1][j];
			}
			
		}
		
		for(int i=2;i<=n;i++)
		{
			int c=0;
			for(int k=0;k<=len;k++)
			{
				a[1][k]+=a[i][k]+c;
				c=a[1][k]/100000000;
				a[1][k]%=100000000;
			}			
			if(c)
			{
				len++;
				a[1][len]+=c;
			}
		}
		printf("%d",a[1][len]);
		for(int i=len-1;i>=0;i--)
		{
			printf("%08d",a[1][i]);
		}
		printf("\n");
		
	}
	return 0;
}
