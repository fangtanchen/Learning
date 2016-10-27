#include <stdio.h>
int main()
{
	float I,i,w,r1=0.1,r2=0.075,r3=0.05,r4=0.03,r5=0.015,r6=0.01;
	printf("请输入当月利润\n");
	scanf("%f",&I);
	i=I/100000;
	if(i>0&&i<=1)
		w=I*r1;
	else if(i>1&&i<=2)
		w=10000+(I-100000)*r2;
	else if(i>2&&i<=4)
		w=17500+(I-200000)*r3;
	else if(i>4&&i<=6)
		w=27500+(I-400000)*r4;
	else if(i>6&&i<=10)
		w=33500+(I-600000)*r5;
	else if(i>10)
		w=39500+(I-1000000)*r6;
	else
		printf("enter data error");
	printf("应发奖金为%f\n",w);
	return 0;
}
