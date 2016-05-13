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

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
		int N;
		scanf("%d", &N);
		while(N--){
			int n;
			scanf("%d", &n);
			double sum=0;
			for(int i=2;i<=n;i++){
				sum=sum+log10(i);
			}
			printf("%d\n", (int)sum+1);
		}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
