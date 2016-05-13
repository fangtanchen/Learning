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
int dp[SIZE][SIZE][2];
int m2[SIZE][SIZE];
int m5[SIZE][SIZE];

const int dir[2][2]={{1, 0}, {0, 1}};
const char w[5]="DR";

void init(){
	memset(dp, 0, sizeof(dp));
	memset(m2, 0, sizeof(m2));
	memset(m5, 0, sizeof(m5));
}

int path(int ri, int ci){
	if(ri==1&&(ci==1)){
		return 0;
	}else if(ri==1){
		for(int i=ci-1;i>=1;i--){
			putchar('R');
		}
		return 0;
	}else if(ci==1){
		for(int i=ri-1;i>=1;i--){
			putchar('D');
		}
		return 0;
	}
	int i=ri;
	int j=ci;
	int tempa=0, tempb=0;
	int tempa2=dp[i-1][j][0]+m2[i][j];
	int tempa5=dp[i-1][j][1]+m5[i][j];
	int tempb2=dp[i][j-1][0]+m2[i][j];
	int tempb5=dp[i][j-1][1]+m5[i][j];
	if((dp[ri][ci][0]==tempa2)
		&&(dp[ri][ci][1]==tempa5)){
		path(ri-1, ci);
		putchar('D');
	}else{
		path(ri, ci-1);
		putchar('R');
	}
	return 0;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	while(EOF!=scanf("%d", &n)){
	int a, b;
	int x=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d", &a);
			if(a==0){
				x=a;
				continue;
			}
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
	dp[1][1][0]=m2[1][1];
	dp[1][1][1]=m5[1][1];
	for(int i=2;i<=n;i++){
		dp[1][i][0]=dp[1][i-1][0]+m2[1][i];
		dp[1][i][1]=dp[1][i-1][1]+m5[1][i];
		dp[i][1][0]=dp[i-1][1][0]+m2[1][i];
		dp[i][1][1]=dp[i-1][1][1]+m5[1][i];
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			int tempa=0, tempb=0;
			int tempa2=dp[i-1][j][0]+m2[i][j];
			int tempa5=dp[i-1][j][1]+m5[i][j];
			tempa=MINF(tempa2, tempa5);
			int tempb2=dp[i][j-1][0]+m2[i][j];
			int tempb5=dp[i][j-1][1]+m5[i][j];
			tempb=MINF(tempb2, tempb5);
			if(tempa<tempb){
				dp[i][j][0]=tempa2;
				dp[i][j][1]=tempa5;
			}else{
				dp[i][j][1]=tempb2;
				dp[i][j][1]=tempb5;
			}
		}
	}
	int ans=MINF(dp[n][n][0], dp[n][n][1]);
	if(x&&(ans>1)){
		printf("1\n");
		for(int i=1;i<x;i++)
			putchar('D');
		for(int j=1;j<n;j++){
			putchar('R');
		}
		for(int i=x;i<n;i++)
			putchar('D');
	}else{
		printf("%d\n",ans); 
		path(n, n);
	}
	printf("\n");
}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
