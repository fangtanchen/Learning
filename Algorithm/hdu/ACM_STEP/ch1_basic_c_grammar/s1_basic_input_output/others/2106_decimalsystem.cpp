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
int transform(int a, int b){
	int res=0;
	int k=1;
	while(a){
		int temp=a%10*k;
		a/=10;
		res+=temp;
		k*=b;
	}
	return res;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int N;
	int sum=0;
	while(EOF!=scanf("%d", &N)){
		int a, b;
		sum=0;
		for(int ni=1;ni<=N;ni++){
			scanf("%d(%d)", &a, &b);
			sum+=transform(a, b);
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
