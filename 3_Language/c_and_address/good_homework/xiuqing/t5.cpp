#include <stdio.h>
#include <math.h> 
int main()
{
	int a,n,i,Sn=0,j=0;
	printf("请输入一个数和您需要的位数\n");
	scanf("%d,%d",&a,&n);
	for(i=1;i<n+1;i++)
	{
		j=j+pow(10,i-1);
		Sn=Sn+a*j;
	}
	printf("Sn=%d",Sn);
	return 0;
}
