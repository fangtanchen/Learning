#include<stdio.h>

int main(){
	char s[100]="abcdfaf1321dfafd1231";
	char a[100], b[100], c[100], d[100];
	sscanf(s, "%[a-z]s%[0-9]s%[a-z]s%[0-9]s", a, b, c, d);
	printf("%s%s%s%s\n", a, b, c, d);
	return 0;
}
