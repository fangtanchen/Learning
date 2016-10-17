#include<stdio.h>
#include<math.h>

int main(){
    double res1=(1000.0)*(1+5*0.0585)-1000;
    double res2=1000.0*(1+2*0.0468)*(1+3*0.054)-1000;
    double res3=1000.0*(1+3*0.054)*(1+2*0.0468)-1000;
    double res4=1000.0*pow(1+0.0414,5)-1000;
    double res5=1000.0*pow(1+0.0072/4,20)-1000;

    printf("%lf\n",res1);
    printf("%lf\n",res2);
    printf("%lf\n",res3);
    printf("%lf\n",res4);
    printf("%lf\n",res5);
    return 0;
}
