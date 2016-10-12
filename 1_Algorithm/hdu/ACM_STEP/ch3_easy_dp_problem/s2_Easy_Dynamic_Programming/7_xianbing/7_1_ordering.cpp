#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<ctime>
//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int max(int x, int y){
	return (x>y) ? x : y;
}

#define max_3(x,y,z) max(x,max(y,z))

int dp[2][12];
int T[110000][11];

int main(){
#ifdef L_JUDGE
	freopen("in2.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
/*	srand(time(NULL));
	for (int i = 0; i < 90000; i++){
		
		int t1 = rand() % 11;
		int t2 = rand() % 100000;
		printf("%d %d\n", t1, t2);
	}*/

	int n;
	while (EOF != scanf("%d", &n), n){
		memset(T, 0, sizeof(T));
		memset(dp, 0, sizeof(dp));
		int x, t;
		int maxT = 0;
		for (int i = 0; i<n; i++){
			scanf("%d%d", &x, &t);
			T[t][x]++;
			if (maxT<t)maxT = t;
		}
		int si = 0;
		int di = 1;
		dp[si][4] = T[1][4];
		dp[si][5] = T[1][5];
		dp[si][6] = T[1][6];

		for (int i = 2; i<6; i++){

			for (int posi = 1; posi<10; posi++){
				dp[di][posi] = max_3(dp[si][posi - 1], dp[si][posi], dp[si][posi + 1]) + T[i][posi];
			}
			dp[di][5 - i] = max(dp[si][5 - i], dp[si][6 - i]) + T[i][5 - i];
			dp[di][5 + i] = max(dp[si][4 + i], dp[si][5 + i]) + T[i][5 + i];
			for (int posi = 4 - i; posi >= 0; posi--){
				dp[di][posi] = 0;
				dp[di][10 - posi] = 0;
			}
			si = 1 - si;
			di = 1 - di;
		}

		for (int i = 6; i <= maxT; i++){

			for (int posi = 1; posi<10; posi++){
				dp[di][posi] = max_3(dp[si][posi - 1], dp[si][posi], dp[si][posi + 1]) + T[i][posi];
			}
			dp[di][0] = max(dp[si][0], dp[si][1]) + T[i][0];
			dp[di][10] = max(dp[si][9], dp[si][10]) + T[i][10];

			si = 1 - si;
			di = 1 - di;
		}

		int max = dp[si][0];
		for (int i = 1; i<11; i++){
			if (max<dp[si][i]){
				max = dp[si][i];
			}
		}
		printf("%d\n", max);
	}

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
