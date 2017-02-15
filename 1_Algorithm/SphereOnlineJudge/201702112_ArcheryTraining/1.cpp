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
const int MAXN=1005;

double X,Y,R;
int T;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         scanf("%lf%lf%lf",&X,&Y,&R);
         double l=0,r=X;
         while(r-l>1e-10){
             double x=(l+r)/2;
             double y=sqrt(X*X+Y*Y-R*R-x*x);
             if((x-X)*(x-X)+(y-Y)*(y-Y)<=R*R){
                  r=x;
             }else{
                 l=x;
             }
         }
         printf("%.6lf %.6lf\n",l,sqrt(X*X+Y*Y-R*R-l*l));
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
