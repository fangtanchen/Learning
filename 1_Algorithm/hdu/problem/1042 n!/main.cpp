#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,c,s,mul,i,len,nextlen;
	int f[10001];
	int maxn=10001;
	while(EOF!=scanf("%d",&n))
	{
		
		memset(f,0,sizeof(f));
		f[1]=1;
		len=1;
		nextlen = len+2;//����Ժ�Ľ������������ԭ����4 
		for(mul=2;mul<=n;mul++)
		{
			c=0;
			for(i=1;i<nextlen;i++)
			{
			/*	if((i>len+4))//����Ժ�Ľ������������ԭ����4 
				{
					break;
				}*/
				s = c+f[i]*mul;
				f[i]=s%10000;
				c=s/10000;				
			}
			while(!f[i])i--;
			len=i;
			nextlen = len+2;
		}
		printf("%d",f[len]);
		for(i=len-1;i>0;i--)
		{
			printf("%04d",f[i]);
		}
		printf("\n");
	}
	return 0;
}
