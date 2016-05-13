#include<stdio.h>
#include<stdlib.h>

int main(){
	int n_line=0;
	int ch;
	int line_begin=1;
	while((ch=getchar())!=EOF){
		if(line_begin){
			line_begin=0;
			n_line++;
			printf("%d: ",n_line);
		}
		putchar(ch);

		if('\n'==ch){
			line_begin=1;
		}

	}
	return EXIT_SUCCESS;
}
