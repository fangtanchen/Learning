#include<stdio.h>

int main(void)
{
	int n;
	while(EOF!=scanf("%d",&n))
	{
		int sum=0;
		int a=0;
		while(n--){
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
	}
	return 0;
}
