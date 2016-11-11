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
const int MAXN=1e6+10;


double totalarea;
double ansx,ansy;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int T,N;
    scanf("%d",&T);
    while(T--){
        totalarea=0;
        double sigmax=0,sigmay=0;
         scanf("%d",&N);
         double ox,oy,ax,ay,bx,by;
         scanf("%lf%lf",&ox,&oy);
         ax=ox;ay=oy;
         for(int i=2;i<=N;i++){
             scanf("%lf%lf",&bx,&by);
             double area=-(bx)*ay+by*ax;
             totalarea+=area;
             double tx=(ax+bx);
             double ty=(ay+by);
             sigmax+=(tx)*area;
             sigmay+=(ty)*area;
             ax=bx;ay=by;
         }
         double area=-ox*ay+oy*ax;
         totalarea+=area;
         sigmax+=(ox+ax)*area;
         sigmay+=(oy+ay)*area;
         sigmax=sigmax/3/totalarea;
         sigmay=sigmay/3/totalarea;

         //sigmax=int((sigmax+0.005)*100)/100.0;
         //sigmay=int((sigmay+0.005)*100)/100.0;
         printf("%.2lf %.2lf\n",sigmax,sigmay);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
