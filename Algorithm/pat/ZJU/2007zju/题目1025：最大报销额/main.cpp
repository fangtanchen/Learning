#include <iostream>
#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double temp[33]={0};
int tempi=1;
int  N;
double Q;
int cmp(const double* x,const double* y)
{
	return *x-*y;
}

double f(int fee )
{
	if(tempi==N)
	{
		if(fee>=temp[N])return temp[N];
		else return 0;
	}
	double h=temp[tempi];
	temp[tempi++]=0;
	double a=f(fee-h)+h;
	double b=f(fee);
	return a>b?a:b;
}

int main(int argc, char** argv) {
	
	while(cin>>Q>>N,N)
	{
		double total=0;
		memset(temp,0,sizeof(temp));
		tempi=1;
		for(int Ni=1;Ni<=N;Ni++)
		{		
			int m=0;
			double price=0;
			char type;		
			cin>>m;
			while(m--)
			{
				scanf(" %c:%lf",&type,&price);				
				if(type<'A'||type>'C'||price>600)
				{
					temp[Ni]=0;
					break;
				}
				else 
				{
					temp[Ni]+=price;
				}
			}
			if(temp[Ni]>1000)temp[Ni]=0;					
		}
		double ans = f(Q);
		printf("%.2f\n",ans);
	}
	return 0;
}
