#include<stdio.h>

int main(){
	
	double n;
	printf("input n:");
	scanf("%lf", &n);
	double last_num=1;
	double new_num=1;
	do{
		last_num=new_num;
		new_num=(last_num+n/last_num)/2.0;
	}while(last_num!=new_num);
	printf("output sqrt(n)=%lf\n", new_num);

	return 0;
}
