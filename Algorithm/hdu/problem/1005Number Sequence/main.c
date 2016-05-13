#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,n;
	int f[200]={0,1,1,0};
	int loopn=200;
	int ni=3;
	
	scanf("%d %d %d",&a,&b,&n);
	while(a||b||n)
	{
		loopn=200;
		if(n>0)
		{
			if((a%7==0)&&(b%7==0))
			{
				if(n>2)printf("0\n");
				else
					printf("1\n");
			}
			else
			{
				a = a%7;
				b = b%7;
				ni=3;
				while(ni<=100)
				{
					f[ni]=(a*f[ni-1]+b*f[ni-2])%7;
					if((f[ni-1]==1)&&(f[ni]==1))
					{
						loopn = ni-2;
						break;
					}
					ni++;
				}
				//printf("%d\n",f[(n-1)%loopn+1]);
				n = n%loopn;
				if(0==n)
				{
					printf("%d\n",f[loopn]);
				}
				else
				{
					printf("%d\n",f[n]);
				}
			}				
		}
		scanf("%d %d %d",&a,&b,&n);
	}
	return 0;
}
