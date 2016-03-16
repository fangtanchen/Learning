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

#define MINF(a, b) ((a)<(b)?(a):(b))
#define MAXF(a, b) ((a)>(b)?(a):(b))
#define SIZE 1010

int n;
int dp[SIZE][SIZE];
int m2[SIZE][SIZE];
int m5[SIZE][SIZE];

const int dir[2][2]={{1, 0}, {0, 1}};
const char w[2]="DR";

void init(){
	memset(dp, 0, sizeof(dp));
	memset(m2, 0, sizeof(m2));
	memset(m5, 0, sizeof(m5));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	scanf("%d", &n);
	int a, b;
	for(int i=1;i<SIZE;i++){
		for(int j=1;j<SIZE;j++){
			scanf("%d", &a);
			while((a)&&(a%5==0)){
				m5[i][j]++;
				a/=5;
			}
			while((a)&&(a%2==0)){
				m2[i][j]++;
				a/=2;
			}
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
