#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注意溢出的危险 
int gcd(int x,int y)//x>y
{
	
	int r;
	r=x%y;
	while(r!=0)
	{
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
int main(int argc, char** argv) {
	int step;
	int mod;
	int temp;
	while(2==scanf("%d%d",&step,&mod))
	{
		printf("%10d%10d    ",step,mod);
		if(step>mod)
		{
			temp = step;
			step = mod;
			mod = temp;
		}
		//temp = step%mod;这里的想法是让step比mod小。但是在gcd函数里头已经是%操作了，这里再来，多此一举，反而导致错误 
		if(1==gcd(mod,step))
		{
			printf("Good Choice\n\n");
		}
		else
		{
			printf("Bad Choice\n\n");
		}
	}
	return 0;
}
