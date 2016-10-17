#include<stdio.h>
#include<math.h>

int main(){
    double d=3e5;
    double p=6000;
    double r=0.01;
    double res=(log10(p)-log10(p-d*r))/(log10(1+r));
    printf("%.2lf\n",res);
    return 0;
}
