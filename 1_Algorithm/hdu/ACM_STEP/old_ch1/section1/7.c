#include<stdio.h>

int main(void){
	int a,b;
	int flag=0;
	while(EOF!=scanf("%d%d",&a,&b)){
		printf("%d\n\n",a+b);
	}
	return 0;
}
