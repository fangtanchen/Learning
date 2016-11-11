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
const int MAXN=110;

struct Node{
    double x,y;
    Node(double a=0,double b=0){
        x=a;y=b;
    }
};

Node pt[MAXN][2];
int N;

double Direction(const Node &p1,const Node &p2,const Node &p3){
    return (p3.x-p1.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p3.y-p1.y);
}

bool OnSegment(const Node &p1,const Node &p2,const Node &p3){
    double maxx=max(p1.x,p2.x);
    double minx=min(p1.x,p2.x);
    double maxy=max(p1.y,p2.y);
    double miny=min(p1.y,p2.y);
    return (p3.x>=minx)&&(p3.x<=maxx)
        &&(p3.y<=maxy)&&(p3.y>=miny);
}


int SegIntersect(const Node &p1,const Node &p2,
        const Node &p3,const Node &p4){
    double d1=Direction(p1,p2,p3);
    double d2=Direction(p1,p2,p4);
    double d3=Direction(p3,p4,p1);
    double d4=Direction(p3,p4,p2);
    if((((d1>0)&&(d2<0))||((d1<0)||(d2>0)))
            &&(((d3>0)&&(d4<0))||((d3<0)&&(d4>0)))){
        return 1;
    }
    if((fabs(d1)<1e-5)&&(OnSegment(p1,p2,p3))){
        return 1;
    }
    if((fabs(d2)<1e-5)&&(OnSegment(p1,p2,p4))){
         return 1;
    }
    if((fabs(d3)<1e-5)&&(OnSegment(p3,p4,p1))){
        return 1;
    }
    if((fabs(d4)<1e-5)&&(OnSegment(p3,p4,p2))){
         return 1;
    }
    return 0;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&N),N){
            int ans=0;
            for(int i=0;i<N;i++){
                scanf("%lf%lf%lf%lf",&pt[i][0].x,&pt[i][0].y,&pt[i][1].x,&pt[i][1].y);
                for(int j=0;j<i;j++){
                    ans+=SegIntersect(pt[i][0],pt[i][1],pt[j][0],pt[j][1]);
                }
            }
            printf("%d\n",ans);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
