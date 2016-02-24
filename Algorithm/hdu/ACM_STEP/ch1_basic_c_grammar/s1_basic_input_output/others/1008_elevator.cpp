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
	int N;
	int f[110];
	while(EOF!=scanf("%d",&N),N){
		int sum=N*5;
		f[0]=0;
		int diff;
		for(int i=1;i<=N;i++){
			scanf("%d", &f[i]);
			diff=f[i]-f[i-1];
			if(diff>0){
				sum+=(6*diff);
			}else if(diff<0){
				sum-=(4*diff);
			}
		}
		printf("%d\n", sum);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
