#include<iostream>
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

int LPF[1000010] = { 0, 0, 1, 2, 1, 3 };
int prime[100000];
int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif

	

	int pi = 1;
	int primei = 1;
	for (int i = 2; i<1000000; i++){
		if (IsPrime(i)){
			LPF[i] = pi;
			pi++;
			prime[primei] = i;
			primei++;
			for (int j = 2; j<=i; j++){
				int tt = j*i;
				if (tt>= 1000000)break;
				LPF[tt] = LPF[i];
			}

		}
		else{
			for (int j = 2; j <= prime[LPF[i]]; j++){
				int tt = j*i;
				if (tt >= 1000000)break;
				LPF[tt] = LPF[i];
			}
		}
	}


	int n;
	while (cin >> n){
 		cout << LPF[n] << endl;
	}
#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
