#include<stdio.h>
int main()
{
	int n;
    scanf("%d",&n);
	while (n--)
	{
		int i,r;
		double s=1,v=1;
		scanf("%d",&r);
		for (i=1;i<=r;i++)
		{
			v=v*i;
			if (i&1) s-=1/v; else s+=1/v;
		}
		printf("%.2lf%%\n",100*s);
	}
	return 0;
}