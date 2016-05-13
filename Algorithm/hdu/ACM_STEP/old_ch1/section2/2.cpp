#include<iostream>
#include<cstdio>
using namespace std;


#define PI 3.1415927
#define MILE 63360
#define TIME 3600


int main(){
	double d,t;
	int r;
	int casei=1;
	while(cin>>d>>r>>t,r){
		double distance=PI*d*r/MILE;
		double mph=distance/(t/TIME);
		printf("Trip #%d: %.2f %.2f\n",casei,distance,mph);
		casei++;
	}
	return 0;
}
