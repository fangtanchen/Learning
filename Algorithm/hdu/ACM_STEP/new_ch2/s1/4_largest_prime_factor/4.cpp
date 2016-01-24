#include<iostream>
#include<stdio.h>
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

bool IsPrime(int n){
	double imax = sqrt(n*1.0);
	for (int i = 2; i <= imax; i++){
		if (n%i == 0)return false;
	}
	return true;
}

int prime[100000];
int LPF[1000000] = { 0 };
int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int pi = 1;
	//LPF[2] = 1;
	for (int i = 2; i<1000000; i++){
		if (!LPF[i]){
			LPF[i] = pi;
			
			for (int j = i + i; j < 1000000; j += i){
				LPF[j] = LPF[i];
			}
			pi++;
		}
	}


	int n;
	while (scanf("%d",&n)!=EOF){
		printf("%d\n", LPF[n]);
	}
#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
