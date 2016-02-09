#include<stdio.h>

int main(){
	int a,b;
	while(EOF!=scanf("%x%x",&a,&b)){
		printf("%d\n",a+b);
	}
	return 0;
}
