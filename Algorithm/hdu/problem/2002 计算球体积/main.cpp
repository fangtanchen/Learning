#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#define PI 3.1415927


int main(int argc, char** argv) {
	double r;
	double v;
	while(cin>>r)
	{
		v=4.0/3.0*PI*r*r*r;
		printf("%.3f\n",v);
	}
	return 0;
}
