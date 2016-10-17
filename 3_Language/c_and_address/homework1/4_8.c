#include<stdio.h>

int main(){
    double x;
    int g;
    while(scanf("%lf",&x)!=EOF){
        g=x/10;
        switch(g){
            case 6:
                putchar('D');
                break;
            case 7:
                putchar('C');
                break;
            case 8:
                putchar('B');
                break;
            case 9:
            case 10:
                putchar('A');
                break;
            default:
                putchar('E');
                break;
        }
        putchar('\n');
    }
    return 0;
}

