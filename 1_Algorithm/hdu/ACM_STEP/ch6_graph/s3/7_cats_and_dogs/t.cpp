#include<stdio.h>
#include<string.h>

int main(void){
    char str[100];
    gets(str);
    printf("%s\n",str);
    gets(str);
    printf("%s\n",str);
    printf("%s\n",str+3);
    printf("%s\n",str+2);
    printf("%s\n",str+1);
    return 0;
}
