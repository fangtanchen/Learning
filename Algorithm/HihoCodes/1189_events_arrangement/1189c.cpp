#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>


#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MMAX 5001
#define NMAX 1005
#define CMAX 10001
#define KMAX 1011

struct CEvent{
	int a, b, c;
	CEvent(int x, int y, int z){
		a = x; b = y; c = z;
	}
	CEvent(){}
};

int dp[2][MMAX];
int q[5001][1024];
int head[CMAX];
int tail[CMAX];
CEvent events[NMAX];
int N, M, K;

bool cmp(CEvent x, CEvent y){
	return x.b*y.c>=y.b*x.c;
}

int Calc(CEvent x, int ki, int vi){

	int temp = (ki)*(x.a - vi*x.b) + (ki*(ki + 1)/2)  * x.c*x.b;
	return temp;
}

void gao(int&x, int y){
	x = max(x, y);
}

int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++){
		scanf("%d%d%d", &events[i].a, &events[i].b, &events[i].c);
	}
	sort(events + 1, events + N + 1, cmp);
	memset(dp, 0, sizeof(dp));
	memset(q, 0, sizeof(q));

	int di=1;
	int si=0;
	for (int ni = 1; ni <= N; ni++){
		int ac=events[ni].c;
      for (int i = 0; i<M; i++){
			head[i] = 1;
		}
		memset(tail, 0, sizeof(tail));

		for (int vi = 0; vi<M; vi++){
			int r = vi%ac;
			tail[r]++;
			q[r][tail[r]] = vi;

			int k1=(vi-q[r][tail[r]])/(ac);
			int tempval1=Calc(events[ni], k1, vi);
			int val1=dp[si][q[r][tail[r]]]+tempval1;

			while(tail[r]>head[r]){
				int k2=(vi-q[r][tail[r]-1])/ac;
				int tempval2=Calc(events[ni], k2, vi);
				int val2=dp[si][q[r][tail[r]-1]]+tempval2;
				if(val1>=val2){
					q[r][tail[r]-1]=q[r][tail[r]];
					tail[r]--;
				}else{
					break;
				}
			}
			while((vi-q[r][head[r]])/ac>K){
				head[r]++;
			}
			dp[di][vi]=dp[si][q[r][head[r]]]
				+Calc(events[ni], (vi-q[r][head[r]])/ac, vi);
		}
		si=1-si;
		di=1-di;
	}
	int max = 0;
	for (int i = 0; i<M; i++){
		if (max<dp[si][i])max = dp[si][i];
	}
	printf("%d\n", max);


#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}

