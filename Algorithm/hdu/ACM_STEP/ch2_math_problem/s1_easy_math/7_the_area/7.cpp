#include<iostream>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

class CPoint{
	public:
		double x;
		double y;
};

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	while(T--){
		CPoint pt[4];
		for(int i=1;i<=3;i++){
			cin>>pt[i].x>>pt[i].y;
		}
		double a,c,b;
		a=(pt[2].y-pt[1].y)/((pt[2].x-pt[1].x)*(pt[2].x-pt[1].x));
		c=(pt[3].y-pt[2].y)/((pt[3].x-pt[2].x));
		b=pt[2].y-c*pt[2].x;
		
		double t1=(pt[3].x-pt[1].x)*(pt[3].x-pt[1].x)*(pt[3].x-pt[1].x);
		double t2=((pt[2].x-pt[1].x)*(pt[2].x-pt[1].x)*(pt[2].x-pt[1].x));
		
		double res=a*(t1-t2)/3+(pt[1].y-b)*(pt[3].x-pt[2].x)-0.5*c*(pt[3].x*pt[3].x-pt[2].x*pt[2].x);
		printf("%.2lf\n",res);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
