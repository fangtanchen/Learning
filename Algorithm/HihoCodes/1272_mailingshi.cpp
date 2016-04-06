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

double a[100];
int b[100];
int N;
int Q;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	for(scanf("%d", &Q);Q--;){
		scanf("%d", &N);
		for(int ni=0;ni<N;ni++){
			scanf("%lf%d", a+ni, b+ni);
		}
		a[N]=a[N+1]=b[N]=b[N+1]=0;
		int ans=0;
		for(int i=0;i<N;i++){
			for(int j=i+1;j<=N;j++){
				for(int k=j+1;k<=N+1;k++){
					double tempa=a[i]+a[j]+a[k];
					if((fmod(tempa, 5.0)<1e-2)){
						int temp=b[i]+b[j]+b[k];
						if(temp>ans)ans=temp;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	
	

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
