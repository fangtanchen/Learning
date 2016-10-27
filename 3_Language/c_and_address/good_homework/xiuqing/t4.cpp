#include <stdio.h>
int main()
{
	int i,m=0,n=0,q=0,p=0;
	char a;
	printf("请输入一行字符\n");
	while((a=getchar())!='\n')
	{
		
		if(a>='0'&&a<='9')
			m++;
		else if((a>='A'&&a<='Z')||(a>='a'&&a<='z'))
			n++;
		else if(a==' ')
			q++;
		else
			p++;
	}
	printf("有%d个数字%d个英文字母%d个空格%d个其他",m,n,q,p);
	return 0;
}
