#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n=1;
	int t=0;
	int i;
	int start=0,dest=0;
	int distance;
	while(scanf("%d",&n)&&n!=0)
	{
		i=0;
		t=5*n;
		start=0;
		while(i<n)
		{
			scanf("%d",&dest);
			distance = dest-start;
			if(distance>0)
			{
				t+=(6*distance);
			}
			else
			{
				t-=(4*distance);
			}						
			start = dest;
			i++;
		}
		printf("%d\n",t);
	}
	return 0;
}
