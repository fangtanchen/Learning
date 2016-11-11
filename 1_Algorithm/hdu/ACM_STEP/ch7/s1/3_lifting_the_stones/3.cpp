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

struct Node {
    double x;
    double y;
    Node(const Node &p){
        x=p.x;
        y=p.y;
    }
    Node(int a=0,int b=0){
        x=a;y=b;
    }
};

double Direction(const Node &p1,const Node &p2,const Node &p3){
    double ret=(p3.x-p1.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p3.y-p1.y);
    return ret/2.0;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        double sigmax,sigmay,totalarea;
        sigmax=sigmay=totalarea=0;
        Node p1,p2,p3;
        scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
        for(int i=2;i<N;i++){
            scanf("%lf%lf",&p3.x,&p3.y);
            double  area=Direction(p1,p3,p2);
            totalarea+=area;
            sigmax+=(p1.x+p2.x+p3.x)*area/3;
            sigmay+=(p1.y+p2.y+p3.y)*area/3;
            p2=p3;
        }



         //sigmax=int((sigmax+0.005)*100)/100.0;
         //sigmay=int((sigmay+0.005)*100)/100.0;
         printf("%.2lf %.2lf\n",sigmax/totalarea,sigmay/totalarea);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
