#include<stdio.h>
#include<stdlib.h>

int main(){
	char ch;
	signed char check_sum=-1;
	while((ch=getchar())!=EOF){
		check_sum+=ch;
		if('\n'==ch)break;
	}
	printf("%d\n",check_sum);
	return EXIT_SUCCESS;
}
