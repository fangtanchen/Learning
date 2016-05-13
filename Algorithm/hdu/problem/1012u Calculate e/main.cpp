#include <iostream>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int mul=2;
	int i=3;
	double result = 1.0;
	cout<<"n e"<<endl<<"- -----------"<<endl;
	cout<<"0 1"<<endl;
	cout<<"1 2"<<endl;
	cout<<"2 2.5"<<endl;
	mul=2;
	i=3;
	result=2.5;
	while(i<=9)
	{
		mul*=i;
		result+=(1.0/mul);
		printf("%d %.9f\n",i,result);
	//	if(i!=9)printf("\n");
		i++;
	}
	return 0;
}
