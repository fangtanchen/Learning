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

double len[10010];

#define eps (1e-6)

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int N,K;
	while(scanf("%d%d",&N,&K)!=EOF,N||K){
		double sum=0;
		for(int ni=0;ni<N;ni++){
			scanf("%lf",&len[ni]);
			sum=sum+len[ni];
		}
		double lf=0;
		double ri=sum/K;
		double mid=(lf+ri)/2;
		while(fabs(lf-ri)>eps){
			int cnt=0;
			for(int ni=0;ni<N;ni++){
				cnt=cnt+(int)(len[ni]/mid);
			}
			if(cnt>=K){
				lf=mid;
			}else{
				ri=mid;
			}
			mid=(lf+ri)/2;
		}
		printf("%.2lf\n",mid);
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
