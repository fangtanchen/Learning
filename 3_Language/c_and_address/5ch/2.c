#include<stdio.h>

#define L_JUDGE

int main(){
#ifdef L_JUDGE
	freopen("in2.txt", "r", stdin);
#endif

	int ch;
	while((ch=getchar())!=EOF){
		if((ch<='M'&&ch>='A')
			||(ch<='m'&&ch>='a')){
			ch=ch+13;
		}
		else if((ch>'M'&&ch<='Z')
			||(ch>'m'&&ch<='z'))
			ch-=13;
		putchar(ch);
	}
#ifdef L_JUDGE
	fclose(stdin);
#endif
	return 0;
}
