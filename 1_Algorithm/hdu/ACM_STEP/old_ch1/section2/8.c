#include<stdio.h>
#include<string.h>
int main(void){
	char s[30]="abcdefghijklmnopqrstuvwxyz";
	int count[26];
	char buf[100010];

	while(gets(buf)){
		memset(count,0,26*sizeof(int));
		int cnti=0;
		int len=strlen(buf);
		{
			int stri=0;
			for(stri=0;stri<len;stri++){

				if(buf[stri]>='a'&&buf[stri]<='z')
				  count[buf[stri]-'a']++;
			}
		}
		for(cnti=0;cnti<26;cnti++){
			printf("%c:%d\n",s[cnti],count[cnti]);
		}
		printf("\n");
	}

	return 0;
}
