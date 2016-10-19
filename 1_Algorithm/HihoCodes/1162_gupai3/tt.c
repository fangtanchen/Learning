#include<stdio.h>

void main(){
    char ch,f[100];
    int i,a;
    printf("Input\n");
    for(i=0;(f[i]=getchar())!='\n';i++){
        f[i]=f[i]-'a'+'A';
    }
    a=i;
    for(i=0;i<=a;i++){
        putchar(f[i]);
    }
}
