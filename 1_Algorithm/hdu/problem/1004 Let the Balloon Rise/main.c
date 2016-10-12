#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	int n;
	
	char color[20];
	int i=0;
	int j=0;
	int ni=0;
	int max=0;
	char s[1000][20];
	int count[1000]={0};
	scanf("%d",&n);
	while(n!=0)
	{
		if(n>0)
		{
			ni=0;
			max=0;
			while(ni<n)
			{
				scanf("%s",s[ni]);
				ni++;
			}
			ni=0;
			for(i=0;i<n-1;i++)
			{
				count[i]=0;
				for(j=i+1;j<n;j++)
				{
					if(!strcmp(s[i],s[j]))
						count[i]++;
				}
				if(count[i]>count[max])max = i;
			}
			puts(s[max]);
		}
		scanf("%d",&n);
	}
	return 0;
}
