#include<stdio.h>

int main(){
	int ch;
	while((ch=getchar())!=EOF){
		putchar(tolower(ch));
	}
	return 0;
}
