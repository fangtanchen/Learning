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
const int MAXN=1005;
const int MODU=998244353;
const int MAXS=4;

//long long int dp[MAXN][MAXS];
long long int dp[MAXN];
char A[MAXN],B[MAXN];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    scanf("%s%s",A+1,B+1);
    A[0]='1',B[0]='0';
    A[N]=B[N]='0';
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    for(int ni=2;ni<=N;ni++){
        if((A[ni]=='1')&&(B[ni]=='0')){
            dp[ni][2]=(dp[ni][2]+dp[ni-1][2])%MODU;
        }
        int kmax=n-2;
        for(int k=2;k<kmax;k++){
            if((A[ni]=='1')&&(B[ni]==1)
                    &&(A[N-k]=='0'&&B[N-k]=='0')
                    &&(A[N-k+1]=='1')&&(B[N-k+1]))
                dp[ni]=(dp[ni]+dp[k]*dp[n-k-1])%MODU;
        }
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
