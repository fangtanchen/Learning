#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

class CPt{
	public:
		double x;
		double y;
		CPt(){
			this->x=0;
			this->y=0;
		}
		CPt(int x1, int y1){
			this->x=x1;
			this->y=y1;
		}
		CPt(const CPt &pt){
			this->x=pt.x;
			this->y=pt.y;
		}
};

double P,Q,R;
#define DIST(A,B) (sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)))
#define eps (1e-6)
double  CalFee(CPt A,CPt mid1, CPt mid2, CPt D){
	return DIST(A,mid1)/P+DIST(mid1,mid2)/R+DIST(mid2,D)/Q;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	while(T--){
		CPt A,B,C,D;
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&A.x,&A.y,
			&B.x,&B.y,&C.x,&C.y,&D.x,&D.y);
		scanf("%lf%lf%lf",&P,&Q,&R);
		CPt p1(B);
		CPt p2;
		double fee1;
		double fee2;
		do{
			//update p2
			CPt p2_lf(C),p2_ri(D);
			CPt p2_mid((p2_lf.x+p2_ri.x)/2,
						(p2_lf.y+p2_ri.y)/2);
			CPt p2_midmid((p2_ri.x+p2_mid.x)/2,
						(p2_ri.y+p2_mid.y)/2);
			double fee2_lf=CalFee(A,p1,p2_lf,D);
			double fee2_ri=CalFee(A,p1,p2_ri,D);
			double fee2_mid=CalFee(A,p1,p2_mid,D);
			double fee2_midmid=CalFee(A,p1,p2_midmid,D);
			while(fabs(fee2_lf-fee2_ri)>eps){
				if(fee2_mid<fee2_midmid){
					p2_ri.x=p2_midmid.x;
					p2_ri.y=p2_midmid.y;
				}else{
					p2_lf.x=p2_mid.x;
					p2_lf.y=p2_mid.y;
				}
				p2_mid.x=(p2_lf.x+p2_ri.x)/2;
				p2_mid.y=(p2_lf.y+p2_ri.y)/2;
				p2_midmid.x=(p2_mid.x+p2_ri.x)/2;
				p2_midmid.y=(p2_mid.y+p2_ri.y)/2;
				fee2_lf=CalFee(A,p1,p2_lf,D);
				fee2_ri=CalFee(A,p1,p2_ri,D);
				fee2_mid=CalFee(A,p1,p2_mid,D);
				fee2_midmid=CalFee(A,p1,p2_midmid,D);
			}
			fee2=fee2_lf;
			p2.x=p2_lf.x;
			p2.y=p2_lf.y;

			//update p1
			CPt p1_lf(A),p1_ri(B);
			CPt p1_mid((p1_lf.x+p1_ri.x)/2,
						(p1_lf.y+p1_ri.y)/2);
			CPt p1_midmid((p1_ri.x+p1_mid.x)/2,
						(p1_ri.y+p1_mid.y)/2);
			double fee1_lf=CalFee(A,p1_lf,p2,D);
			double fee1_ri=CalFee(A,p1_ri,p2,D);
			double fee1_mid=CalFee(A,p1_mid,p2,D);
			double fee1_midmid=CalFee(A,p1_midmid,p2,D);
			while(fabs(fee1_lf-fee1_ri)>eps){
				if(fee1_mid<fee1_midmid){
					p1_ri.x=p1_midmid.x;
					p1_ri.y=p1_midmid.y;
				}else{
					p1_lf.x=p1_mid.x;
					p1_lf.y=p1_mid.y;
				}
				p1_mid.x=(p1_lf.x+p1_ri.x)/2;
				p1_mid.y=(p1_lf.y+p1_ri.y)/2;
				p1_midmid.x=(p1_mid.x+p1_ri.x)/2;
				p1_midmid.y=(p1_mid.y+p1_ri.y)/2;
				fee1_lf=CalFee(A,p1_lf,p2,D);
				fee1_ri=CalFee(A,p1_ri,p2,D);
				fee1_mid=CalFee(A,p1_mid,p2,D);
				fee1_midmid=CalFee(A,p1_midmid,p2,D);
			}
			fee1=fee1_lf;
			p1.x=p1_lf.x;
			p1.y=p1_lf.y;

		}while(fabs(fee1-fee2)>eps);
		printf("%.2lf\n",fee2);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
