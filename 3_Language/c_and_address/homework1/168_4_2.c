#include<stdio.h>
#include<string.h>
/*
int scan(){
    char ch;
    int ret=0;
    while((ch=getchar()),ch<'0'||ch>'9')
    {
        if(ch=='\n')return -1;
    }
    ret=ch-'0';
    while((ch=getchar()),(ch>='0')&&(ch<='9')){
        ret=ret*10+ch-'0';
    }
    return ret;
}
*/

int scan(){
    char ch;
    int ret=0;
    ret=ch-'0';

    while((ch=getchar()),ch<'0'||ch>'9')
    {
        if(ch=='\n')return -1;
    }

    while((ch=getchar()),(ch>='0')&&(ch<='9')){
        ret=ret*10+ch-'0';
    }
    return ret;
}

int main(){
    int a[100];
    int len=0;
    int x,i;
    while(1==scanf("%d",&x)){
        a[len++]=x;
    }
    for(i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}

