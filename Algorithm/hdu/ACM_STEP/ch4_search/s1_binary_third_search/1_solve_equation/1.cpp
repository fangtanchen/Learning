#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

double ft(double x, double y){
	return pow(x,4)*8+7*pow(x,3)+2*x*x+3*x+6-y;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	while(T--){
		double Y;
		scanf("%lf",&Y);
		if((Y<6)||(ft(100,Y)<0)){
			printf("No solution!\n");
			continue;
		}
		
		double xa=0;
		double xb=100.0;
		double half=(xa+xb)/2.0;
		while(fabs(xa-xb)>1e-6){
			double temp=ft(half,Y);
			if(temp<=0){
				xa=half;
			}else{
				xb=half;
			}
			half=(xa+xb)/2.0;
		}
		printf("%.4lf\n",xb);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
