#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define GG 9.8

double ft(double x, double y, double v, double p){
	return GG*x*x/(2*v*v)*(p*p+1)-x*p+y;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	while(T--){
		double x,y,v;
		scanf("%lf%lf%lf",&x,&y,&v);
		if(x==0){
			printf("-1\n");
			continue;
		}
		double max=v*v/(GG*x);
		if(ft(x,y,v,max)>0){
			printf("-1\n");
			continue;
		}
		//printf("1\n");
		double min=0;
		double mid=(min+max)/2;
		double  temp=ft(x,y,v,mid);
		while(fabs(temp)>=1e-8){
			if(temp>0){
				min=mid;
			}else{
				max=mid;
			}
			mid=(min+max)/2;
			temp=ft(x,y,v,mid);
		}
		printf("%.6lf\n",atan(mid));
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
