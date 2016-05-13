#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int K;
	scanf("%d",&K);
	while(K--){
		long long N;
		scanf("%d",&N);
		long long min=1;
		long long max=0x10000;
		long long mid=(min+max)/2;
		
		long long ri=(mid+1)*mid/2;
		long long lf=ri-mid+1;
		while(N<lf||N>ri){
			if(N<lf){
				max=mid;
			}else{
				min=mid;
			}
			mid=(min+max)/2;
			ri=(mid+1)*mid/2;
			lf=ri-mid+1;
		}
#ifdef U_DEBUG
	printf("N:%d  [%d,%d]\n",N,lf,ri);
#endif
		N=(N-lf)%9+1;
		printf("%lld\n",N);
	}


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
