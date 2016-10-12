#include <iostream>
#include<cstdio>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define PI 3.1415927

int main(int argc, char** argv) {
	float dia,time;
	int rev;
	int idnum=1;
	while(cin>>dia>>rev>>time)
	{
		if(!rev)break;
		float dis=0;
		dis=PI*dia*rev/12.0/5280.0;
		float mph=dis/time*3600.0;
		printf("Trip #%d: %.2f %.2f\n",idnum++,dis,mph);
	}
	return 0;
}
