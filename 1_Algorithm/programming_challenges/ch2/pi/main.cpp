#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double p(int n){
	double x;
	int k=0;
	srand((unsigned)time(NULL));
		for(int i=0;i<n;i++){	
		x=(double)rand()/RAND_MAX;
		double y=(double)rand()/RAND_MAX;
		
		if(y<=sqrt(1-x*x))k++;
	}
	return k*4.0/n;
}

int main(int argc, char** argv) {
	cout<<p(10000)<<endl;
	cout<<p(100000)<<endl;
	cout<<p(10000000)<<endl;
	printf("1000000000  %lf",p(1000000000));
	printf("%d  %lf",10000000000,p(10000000000));
	
	return 0;
}
