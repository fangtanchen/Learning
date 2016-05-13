#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char num[10000];
	int n;
	int i;
	int root;
	while(~scanf("%s",num))
	{
		n=strlen(num);
		if(1==n&&num[0]=='0')break;
		
		do
		{
			root = 0;
			for(i=0;i<n;i++)
			{
				root += (num[i]-'0'); 
			}
			itoa(root,num,10);
			n=strlen(num);
		}while(n>1);
		printf("%d\n",root);
	}
	return 0;
}
