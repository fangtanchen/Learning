#include<stdio.h>
#include<string.h>

#define U_DEBUG
void deblank(char s[]){
	int si=0;
	int pi=0;
	int max=strlen(s);
#ifdef U_DEBUG
	printf("max: %d\n", max);
#endif
	int flag=0;
	for(pi=0;pi<max;pi++){
		s[si]=s[pi];
		si++;
		if(' '==s[pi]){
			while(s[pi]==' '){
				pi++;
			}
			pi--;
		}
	}
	s[si]=0;
}

int main(){
	char s[100];
	memset(s, 0, sizeof(s));
	while(gets(s)){
		printf("%s\n", s);
		deblank(s);
		printf("%s\n", s);
		memset(s, 0, sizeof(s));
	}
	return 0;
}
