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
const int MAXN=1e5+10;


class Point{
    public:
        double x,y;
        Point(int a=0,int b=0){
            x=a;y=b;
        }
        Point(const Point &p){
            x=p.x;y=p.y;
        }

};
int recordnum;
int N;
Point pt[MAXN][2];

double Direction(const Point &p1,const Point &p2,const Point &p3){
    return (p3.x-p1.x)*(p2.y-p1.y)-(p3.y-p1.y)*(p2.x-p1.x);
}

double OnSegment(const Point &p1,const Point &p2,const Point &p3){
    double maxx=max(p1.x,p2.x);
    double minx=min(p1.x,p2.x);
    double maxy=max(p1.y,p2.y);
    double  miny=min(p1.y,p2.y);
    return (p3.x>=minx)&&(p3.x<=maxx)&&(p3.y>=miny)&&(p3.y<=maxy);
}

bool Intersect(const Point &p1,const Point &p2,
        const Point &p3,const Point &p4){
    double d1=Direction(p1,p2,p3);
    double d2=Direction(p1,p2,p4);
    double d3=Direction(p3,p4,p1);
    double d4=Direction(p3,p4,p2);
    if((d1*d2<0)&&(d3*d4<0)){
        return true;
    }
    if((fabs(d1)<1e-8)&&(OnSegment(p1,p2,p3))){
        return true;
    }
    if((fabs(d2)<1e-8)&&(OnSegment(p1,p2,p4))){
        return true;
    }
    if((fabs(d3)<1e-8)&&(OnSegment(p3,p4,p1))){
        return true;
    }
    if((fabs(d4)<1e-8)&&(OnSegment(p3,p4,p2))){
        return true;
    }
    return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&N),N){
            recordnum=0;
            for(int ni=1;ni<=N;ni++){
                for(int i=0;i<2;i++){
                    scanf("%lf%lf",&pt[ni][i].x,&pt[ni][i].y);
                }
            }
            printf("Top sticks: ");
            for(int i=1;i<=N;i++){
                bool flag=true;
                for(int j=i+1;j<=N;j++){
                    if(Intersect(pt[i][0],pt[i][1],pt[j][0],pt[j][1])){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                     if(recordnum)printf(", ");
                     printf("%d",i);
                     recordnum=1;
                }
            }
            printf(".\n");
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
