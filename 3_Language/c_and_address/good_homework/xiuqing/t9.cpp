#include <stdio.h>
int main()
{
 int a[5],b,i,j,num,t;
 printf("请输入一个不多于五位的正整数\n");
 scanf("%d",&b);
 if(b>0&&b<100000)
 {
 	for(i=0,j=b,num=0;j!=0;i++,num++)
	 {
 		a[i]=j%10;
 		j=j/10;
 	 }
 	printf("你输入的是%d位数\n",num);
	 printf("这个数从低到高位上的数分别是:");
	 for(i=0;i<num;i++)	
 		printf("%d\t",a[i]);
 	printf("\n");
	printf("各个位上按逆序输出为:");
	for(i=0;i<num;i++)
		printf("%d",a[i]);
 }
 else
 	printf("您输入的数不符合要求");
 return 0;
}
