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

double Fun(double x, double y){
	return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
double dFun(double x, double y){
	return 42*pow(x,6)+48*pow(x,5)+21*pow(x,2)+10*x-y;
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
		
		if(dFun(100,Y)<=0){
			printf("%.4lf\n",Fun(100,Y));
			continue;
		}
		double xa=0;
		double xb=100;
		double xmid=50.0;
		while(fabs(dFun(xmid,Y))>=1e-5){
			if(dFun(xmid,Y)<0){
				xa=xmid;
			}else{
				xb=xmid;
			}
			xmid=(xa+xb)/2.0;
		}
		printf("%.4lf\n",Fun(xmid,Y));
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
