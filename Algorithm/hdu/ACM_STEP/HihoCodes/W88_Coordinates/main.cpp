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

int P, Q;
int Pd[10010], Qd[10010];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%d%d", &P, &Q)){
		int imax=sqrt(P);
		int pdi=0;
		if(imax*imax==P){
			Pd[pdi++]=imax;
			imax--;
		}
		for(int i=1;i<=imax;i++){
			if(0==P%i){
				Pd[pdi++]=i;
				Pd[pdi++]=P/i;
			}
		}
		sort(Pd, Pd+pdi);

		imax=sqrt(Q);
		int qdi=0;
		if(imax*imax==Q){
			Qd[qdi++]=imax;
			imax--;
		}
		for(int i=1;i<=imax;i++){
			if(0==Q%i){
				Qd[qdi++]=i;
				Qd[qdi++]=Q/i;
			}
		}
		sort(Qd, Qd+qdi);

		for(int i=0;i<pdi;i++){
			for(int j=0;j<qdi;j++){
				printf("%d %d\n", Pd[i], Qd[j]);
			}
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
