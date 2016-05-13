#include<stdio.h>
#include<stdlib.h>

int main(){
	int *b, c, d;
	b=&c;
	c=1;
	d=1;
	printf("%d %d %d %d %d\n", b, *b, &c, c, d);

	char *message;
	message="Hello world!";
	printf("%s", message);
	return EXIT_SUCCESS;
}
