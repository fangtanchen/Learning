#include<stdio.h>

int main(){
    int f[100];
    f[1]=0;
    for(int i=2;i<100;i++){
        f[i]=(f[i-1]+3)%i;
    }
    for(int i=1;i<100;i++){
        if(i%6==1)printf("\n");
        printf("f[%3d]=%3d  ",i,f[i]+1);
    }
    printf("\n");
}
