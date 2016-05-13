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

int GCD(int x, int y){
	if(x%y==0)return y;
	else return GCD(y, x%y);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int N;
	scanf("%d", &N);
	while(N--){
		int m;
		scanf("%d", &m);
		int nn, ans=1;
		scanf("%d", &ans);
		for(int i=2;i<=m;i++){
			scanf("%d", &nn);
			ans=nn/GCD(ans, nn)*ans;
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
