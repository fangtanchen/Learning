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

double sq[10010];

#define PI (acos(-1.0))
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int cases;
	scanf("%d",&cases);
	
	while(cases--){
		int F,N;
		scanf("%d%d",&N,&F);
		int r;
		double sum_vol=0;
		for(int ni=0;ni<N;ni++)	{
			scanf("%d",&r);
			sq[ni]=r*r;
			sum_vol=sum_vol+sq[ni];
		}
		double max_vol=sum_vol/(F+1);
		double min_vol=0;
		double mid_vol=max_vol/2.0;
		int max_cnt=F+1;
		do{
			int cnt=0;
			for(int ni=0;ni<N;ni++){
				cnt=cnt+(int)(sq[ni]/mid_vol);
			}
			if(cnt>=max_cnt){
				min_vol=mid_vol;
			}else{
				max_vol=mid_vol;
			}
			mid_vol=(max_vol+min_vol)/2.0;

		}while(fabs(max_vol-min_vol)>1e-7);


		printf("%.4lf\n",mid_vol*PI);
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
