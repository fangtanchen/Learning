#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef pair<double,double> pdd;

const int MAXN=10005;

pdd pt[MAXN][2];
int N;

bool Zero(double x){
    return fabs(x)<1e-6;
}

double  Direction(pdd p0,pdd p1,pdd p2){
    return (p2.first-p0.first)*(p1.second-p0.second)
        -(p2.second-p0.second)*(p1.first-p0.first);
}

bool OnSegment(pdd p0,pdd p1,pdd p2){
    return min(p0.first,p1.first)<=p2.first
        &&max(p0.first,p1.first)>=p2.first
        &&min(p0.second,p1.second)<=p2.second
        &&max(p0.second,p1.second)>=p2.second;
}

bool SegmentIntersect(pdd p0,pdd p1,pdd p2,pdd p3){
    double d1=Direction(p0,p1,p2);
    double d2=Direction(p0,p1,p3);
    double d3=Direction(p2,p3,p0);
    double d4=Direction(p2,p3,p1);
    if((d1*d2<0)&&(d3*d4)<0){
        return true;
    }
    if((Zero(d1))&&(OnSegment(p0,p1,p2))){
         return true;
    }
    if((Zero(d2))&&(OnSegment(p0,p1,p3))){
         return true;
    }
    if((Zero(d3))&&(OnSegment(p2,p3,p0))){
         return true;
    }
    if((Zero(d4))&&(OnSegment(p2,p3,p1))){
         return true;
    }
    return false;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&N),N){
            for(int ni=0;ni<N;ni++){
                scanf("%lf%lf%lf%lf",
                        &pt[ni][0].first,&pt[ni][0].second,
                        &pt[ni][1].first,&pt[ni][1].second);
            }
            printf("Top sticks:");
            for(int i=0;i<N;i++){
                bool flag=true;
                for(int j=i+1;j<N;j++){
                    if(SegmentIntersect(pt[i][0],pt[i][1],pt[j][0],pt[j][1])){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                     printf(" %d%c",i+1,(i==N-1?'.':','));
                }
            }
            printf("\n");
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
