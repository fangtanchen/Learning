
#include<iostream>
#include<cmath>
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
const int MAXN=1005;
const double eps=1e-8;

double s[4],sum,x,y,z,v;
struct Point{
     double x,y,z;
     Point operator - (const Point &b) const{
         return Point{x-b.x,y-b.y,z-b.z};
     }
     Point operator ^ (const Point &b) const{
          return Point{(y*b.z-z*b.y),(z*b.x-x*b.z),(x*b.y-y*b.x)};
     }
}p[4];

int dcmp(double x){
    if(fabs(x)<eps)return 0;
    return x<0?-1:1;
}

double MixMul(Point a,Point b, Point c){
    return a.x*b.y*c.z+a.y*b.z*c.x+a.z*b.x*c.y
        -a.x*b.z*c.y-a.y*b.x*c.z-a.z*b.y*c.x;
}

double dis(Point a,Point b){
     return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
}

double Heron(double a,double  b,double c){
    double  p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

double getsqr(Point a,Point b,Point c){
    return Heron(dis(a,b),dis(b,c),dis(a,c));
}



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    while(~scanf("%lf%lf%lf",&p[0].x,&p[0].y,&p[0].z)){
        for(int i=1;i<4;i++){
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        }
        v=fabs(MixMul(p[1]-p[0],p[2]-p[0],p[3]-p[0]));
        if(!dcmp(v)){
            puts("O O O O");
            continue;
        }
        s[3]=fabs(getsqr(p[0],p[1],p[2]));
        s[2]=fabs(getsqr(p[0],p[1],p[3]));
        s[1]=fabs(getsqr(p[0],p[2],p[3]));
        s[0]=fabs(getsqr(p[1],p[2],p[3]));

        sum=0;
        for(int i=0;i<4;i++){
            sum+=s[i];
        }
        x=y=z=0;
        for(int i=0;i<4;i++){
             x+=p[i].x*s[i];
             y+=p[i].y*s[i];
             z+=p[i].z*s[i];
        }
        x/=sum,y/=sum,z/=sum;
        printf("%.4lf %.4lf %.4lf %.4lf\n",x,y,z,v/2/sum);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
