#include <stdio.h>
int main()
{
	float I,w,r1=0.1,r2=0.075,r3=0.05,r4=0.03,r5=0.015,r6=0.01;
	int key;
	printf("请输入当月利润\n");
	scanf("%f",&I);
	if(I<=0)
		printf("enter data error\n");
	else
	{
		int(key=(I-1)/100000);
		switch(key)
		{
			case 0:w=I*r1;break;
			case 1:w=10000+(I-100000)*r2;break;
			case 2:
			case 3:w=17500+(I-200000)*r3;break;
			case 4:
			case 5:w=27500+(I-400000)*r4;break;
			case 6:
			case 7:
			case 8:
			case 9:w=33500+(I-600000)*r5;break;
			default:w=39500+(I-1000000)*r6;
			}
		printf("应发奖金为%f",w);		
	}
	return 0;
}
