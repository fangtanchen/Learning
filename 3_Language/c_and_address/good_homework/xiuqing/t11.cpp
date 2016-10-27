#include <stdio.h>
 int main()
 {
 int a[4],i,j,m;
 printf("please input four number:\n");
 for(i=0;i<4;i++)
 	scanf("%d",&a[i]);
 for(i=0;i<4;i++)
 	for(j=i+1;j<4;j++)
	 	if(a[i]>a[j])
		 {m=a[i];
		  a[i]=a[j];
		  a[j]=m;
		  } 
 printf("由小到大的顺序是：\n");
 for(i=0;i<4;i++)
 	printf("%d\t",a[i]);
 return 0;
 }
