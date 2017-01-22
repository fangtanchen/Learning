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
const int MAXN=2005;

int dp[MAXN][MAXN];
int v[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int N;
    while(EOF!=scanf("%d",&N)){
        for(int ni=1;ni<=N;ni++){
            scanf("%d",v+ni);
            dp[1][ni]=v[ni];
        }
        int sum=v[1];
        for(int i=2;i<=N;i++){
            int imax=N-i+1;
            sum+=v[i];
            int tmpsum=sum;
            for(int j=1;j<=imax;j++){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+tmpsum;
                tmpsum=tmpsum-v[j]+v[j+i];
            }
        }
        printf("%d\n",dp[N][1]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
