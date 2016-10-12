#include<stdio.h>
#include<string.h>


#define L_JUDGE
int main(){
#ifdef L_JUDGE
freopen("in5.txt", "r", stdin);
#endif
	char old_str[130];
	char new_str[130];
	int flag=1;
	gets(old_str);
	while(gets(new_str)){
		if((0==strcmp(new_str, old_str))){
			if(1==flag){
				flag++;
				printf("%s\n", new_str);
			}
		}
		else{
			flag=1;
		}
		strcpy(old_str, new_str);
	}
#ifdef L_JUDGE
fclose(stdin);
#endif
	return 0;
}
