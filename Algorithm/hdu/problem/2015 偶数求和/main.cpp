#include <iostream>
#include<cstdio>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m;
	while(cin>>n>>m)
	{
		if(!m)continue;
		int arraynum=n/m;
		int avg=1+m;
		printf("%d",avg);
		int inc=2*m;
		for(int i=2;i<=arraynum;i++)
		{	
			printf(" ");
			avg+=inc;
			printf("%d",avg);
		}
		if(n%m)
		{
			printf(" ");
			avg=m*arraynum+1+n;
			printf("%d",avg);
		}
		printf("\n");
	}
	return 0;
}
