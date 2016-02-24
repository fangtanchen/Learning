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

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int f[15]={1, 1, 2};
	double sum[15]={1, 2, 2.5};
	for(int i=3;i<=9;i++){
		f[i]=i*f[i-1];
		sum[i]=sum[i-1]+1.0/(1.0*f[i]);
	}

	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for(int i=3;i<=9;i++){
		printf("%d %.9lf\n", i, sum[i]);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
