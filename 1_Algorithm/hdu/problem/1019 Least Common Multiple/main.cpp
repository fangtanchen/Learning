#include <iostream>
#include <cstdio>
//注意溢出 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gcd(int x,int y)//x>y
{
	if(x%y==0)return y;
	else return gcd(y,x%y);
}

int main(int argc, char** argv) {
	int ins;
	int m;
	unsigned int n[10000];
	cin>>ins;
	while(ins)
	{
		cin>>m;
		for(int i=1;i<=m;i++)
			cin>>n[i];
		for(int i=1;i<m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(n[i]<n[j])
				{
					int temp=n[i];
					n[i]=n[j];
					n[j]=temp;
				}
			}
		}
		
		for(int i=2;i<=m;i++)
		{
			//n[1]=(n[1]*n[i])/(gcd(n[1],n[i]));//先乘再除和先除再乘的区别：  前者会溢出而出错，后者可以避免这样的错误 
			n[1]=(n[1])/(gcd(n[1],n[i]))*n[i];
		}
		printf("%d\n",n[1]);
		ins--;
	}
	return 0;
}
