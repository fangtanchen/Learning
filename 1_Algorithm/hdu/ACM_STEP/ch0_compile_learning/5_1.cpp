#include<cstdio>
#include<cstring>

char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(){
	int i,ch;
	while(EOF!=(ch=getchar())){
		for(i=1;s[i]&&s[i]!=ch;i++)
			;
		if(s[i])putchar(s[i-1]);
		else putchar(ch);
	}
	return 0;
}
