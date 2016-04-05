#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define DIST(x1, y1, x2, y2) sqrt(((x1)-(x2))*((x1)-(x2))+((y1)-(y2))*((y1)-(y2)))

double gcd(double x, double y){
	return fabs(y)<1e-4?x:gcd(y, fmod(x, y));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	double x[3], y[3];
	for(int i=0;i<3;i++){
		scanf("%lf%lf", x+i, y+i);
	}
	double a, b, c;
	a=DIST(x[0], y[0], x[1], y[1]);
	b=DIST(x[0], y[0], x[2], y[2]);
	c=DIST(x[1], y[1], x[2], y[2]);
	double l=(a+b+c)/2;
	double S=sqrt(l*(l-a)*(l-b)*(l-c));
	double R=(a*b*c)/(4*S);

	double k[3];
	k[0]=acos((b*b+c*c-a*a)/(2*b*c));
	k[1]=acos((a*a+c*c-b*b)/(2*a*c));
	k[2]=acos((a*a+b*b-c*c)/(2*a*b));
	double n=M_PI/gcd(k[0], gcd(k[1], k[2]));
	double ans=(n*R*R*sin(2*M_PI/n))/2;

	printf("%.8lf\n", ans);
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
