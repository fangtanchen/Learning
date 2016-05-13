#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	double x[4], y[4];
	int N;
	scanf("%d", &N);
	while(N--){
		for(int i=1;i<=3;i++){
			scanf("%lf%lf", &x[i], &y[i]);
		}
		double a=(y[2]-y[1])/((x[2]-x[1])*(x[2]-x[1]));
		double b=-2*a*x[1];
		double c=y[1]+a*x[1]*x[1];
		double k=((y[2]-y[3])/(x[2]-x[3]));
		double d=y[2]-k*x[2];
		double ans=a*x[3]*x[3]*x[3]/3+b*x[3]*x[3]/2+c*x[3]-k*x[3]*x[3]/2-d*x[3]
							-	(a*x[2]*x[2]*x[2]/3+b*x[2]*x[2]/2+c*x[2]-k*x[2]*x[2]/2-d*x[2]);
		printf("%.2lf\n", ans);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
