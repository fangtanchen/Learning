#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m,n;
	cin>>m;
	while(m)
	{
		cin>>n;
		double sum=0;
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			sum+=(flag*1.0/i);
			flag*=-1;
		}
		printf("%.2f\n",sum);
		m--;
	}
	return 0;
}
