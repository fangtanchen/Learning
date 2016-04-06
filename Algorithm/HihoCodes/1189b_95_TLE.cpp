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
#define KMAX 1001

struct CEvent{
	int a, b, c;
	double cpb;
	CEvent(int x, int y, int z){
		a = x; b = y; c = z;
		cpb = c*1.0 / b;
	}
	CEvent(){}
};

int dp[NMAX][MMAX];
int q[5001][5001];
int head[CMAX];
int tail[CMAX];
CEvent events[NMAX];
int N, M, K;

bool cmp(CEvent x, CEvent y){
	return x.cpb <= y.cpb;
}

int Calc(CEvent x, int ki, int vi){
	int temp = ki*(x.a - vi*x.b) + (ki*(ki + 1)/2)  * x.c*x.b;
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
		events[i].cpb = events[i].c*1.0 / events[i].b;
	}
	sort(events + 1, events + N + 1, cmp);

	for (int ni = 1; ni <= N; ni++){
		memset(tail, 0, sizeof(tail));
		//        memset(head,0,sizeof(head));
		int imax=max(events[ni].c, M);
		for (int i = 0; i<imax; i++){
			head[i] = 1;
		}
		memcpy(dp[ni], dp[ni - 1], sizeof(dp[ni]));
		for (int vi = events[ni].c; vi<M; vi++){
			int r = vi%events[ni].c;
			tail[r]++;

			q[r][tail[r]] = vi - events[ni].c;

			int tempval1=events[ni].a-(q[r][tail[r]]*events[ni].b);
			int val1=dp[ni-1][q[r][tail[r]]]+tempval1;

			while ((vi - q[r][head[r]]) / events[ni].c>K){
				head[r]++;
			}
			int pi=tail[r]-1;
			while(pi>=head[r]){
				tempval1=tempval1
					+events[ni].a-q[r][pi]*events[ni].b;
				int val2=dp[ni-1][q[r][pi]]+tempval1;
				if(val1>=val2){
					q[r][tail[r]-1]=q[r][tail[r]];
					tail[r]--;
				}
				pi--;
			}
			
			//int ki = (vi - q[r][head[r]]) / events[ni].c;
			//tempval1 = Calc(events[ni], ki, vi);
			gao(dp[ni][vi], dp[ni - 1][q[r][head[r]]] + tempval1);
		}
	}
	int max = 0;
	for (int i = 0; i<M; i++){
		if (max<dp[N][i])max = dp[N][i];
	}
	printf("%d\n", max);


#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}

