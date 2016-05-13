#include <iostream>

using namespace std;
#include<iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	float quotient,number1=132.364f,number2=26.91f;
	quotient=number1/number2;
	cout<<quotient<<endl;
	cout<<setprecision(5)<<quotient<<endl;
	cout<<setprecision(4)<<quotient<<endl;
	cout<<setprecision(3)<<quotient<<endl;
	cout<<setprecision(2)<<quotient<<endl;
	cout<<setprecision(1)<<quotient<<endl;
	return 0;
}
