#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int dt[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(int argc, char** argv) {
	int y,m,d;
	while(scanf("%d/%d/%d",&y,&m,&d)==3)
	{
		int c=0;
		if(y%400==0||((!(y%4))&&(y%100)))c=1;
		dt[2]+=c;
		if(m<1||m>12)
		{
			dt[2]-=c;
			continue;
		}
		if(d<1||d>dt[m])
		{
			dt[2]-=c;
			continue;
		}
		
		if(m>2)a[m]+=c;
		printf("%d\n",a[m]+d);
		dt[2]-=c;
		if(m>2)a[m]-=c;
	}
	return 0;
}
