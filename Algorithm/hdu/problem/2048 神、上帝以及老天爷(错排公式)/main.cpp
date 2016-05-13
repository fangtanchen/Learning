#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int c;
	cin>>c;
	while(c--)
	{
		int n;
		cin>>n;
		double v=1;
		int flag=1;
		double p=0;
		for(int i=2;i<=n;i++)
		{
			v/=i;
			p+=flag*v;
			flag*=-1;
		}
		printf("%.2f%%\n",p*100);
	}
	
	return 0;
}
