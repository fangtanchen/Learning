#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<utility>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;

typedef pair<double,double> pii;

pii seg[MAXN][2];
int N;

double Direction(pii p0,pii p1,pii p2){
    return (p2.first-p0.first)*(p1.second-p0.second)
        -(p2.second-p0.second)*(p1.first-p0.first);
}
bool OnSegment(pii p0,pii p1,pii p2){
    return min(p0.first,p1.first)<=p2.first
        && max(p0.first,p1.first)>=p2.first
        && min(p0.second,p1.second)<=p2.second
        && max(p0.second,p1.second)>=p2.second;
}

bool SegmentIntersection(pii p0,pii p1,pii p2,pii p3){
    double d1=Direction(p0,p1,p2);
    double d2=Direction(p0,p1,p3);
    double d3=Direction(p2,p3,p0);
    double d4=Direction(p2,p3,p1);
    if((d1*d2<=0)&&(d3*d4<=0))return true;
    return false;
    if((d1*d2<0)&&(d3*d4<0))return true;
    if((0==d1)&&(OnSegment(p0,p1,p2))){
         return true;
    }else if((0==d2)&&(OnSegment(p0,p1,p3))){
        return true;
    }else if((0==d3)&&(OnSegment(p2,p3,p0))){
        return true;
    }else if((0==d4)&&(OnSegment(p2,p3,p1))){
        return true;
    }
    return false;
}
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    while(scanf("%d",&N),N>=1){
        for(int ni=0;ni<N;ni++){
            scanf("%lf%lf%lf%lf",
                    &seg[ni][0].first,&seg[ni][0].second,
                    &seg[ni][1].first,&seg[ni][1].second);
        }
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                ans+=SegmentIntersection(seg[i][0],
                        seg[i][1],seg[j][0],seg[j][1]);
            }
        }
        printf("%d\n",ans);
    }
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
