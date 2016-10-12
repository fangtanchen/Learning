#include<stdio.h>
#include<string.h>
int substr(char dst[], char src[], int start, int len){
	if(start<0||len<=0
			||start>strlen(src)){
		dst[0]=0;
		return 0;
	}
	int max=strlen(src);
	int di=0;
	int si=start;
	for(di=0, si=start;
			di<=len&&si<=max;si++, di++){
		dst[di]=src[si];
	}
	dst[di]=0;
}
int main(){
	char s1[50]="qwertyuioplkjhgfdsaxcvbnmz";
	char s2[50];
	printf("%s\n%s\n", s1, s2);
	substr(s2, s1, 10, 32);
	printf("%s\n%s\n", s1, s2);
	substr(s2, s1, 10, 10);
	printf("%s\n%s\n", s1, s2);
	substr(s2, s1, 10, -1);
	printf("%s\n%s\n", s1, s2);
	return 0;
}
