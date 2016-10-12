#include<stdio.h>

// this program isnot well, for some character sets such as
// EBCDIC, the orders of upper cases are not continuous.
// so the first pragram 1.c is better.
int main(){

	int ch;
	while((ch=getchar())!=EOF){
		if(ch>='A'&&ch<='Z')
			ch+='a'-'A';
		putchar(ch);
	}
}
