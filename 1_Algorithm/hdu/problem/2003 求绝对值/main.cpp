#include <iostream>
#include<cstdio>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double n;
	while(cin>>n)
	{
		printf("%.2lf\n",n>0?n:-n);
	}
	return 0;
}
