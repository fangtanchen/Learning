#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double x1,y1,x2,y2;
	while(cin>>x1>>y1>>x2>>y2)
	{
		
		printf("%.2lf\n",sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
	}
	return 0;
}
