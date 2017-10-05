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
typedef long long ll;
const int MAXN=1e6;
const int INF=0x5f5f5ff;
int A[MAXN];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    for(int i=0;i<N;i++){
         cin>>A[i];
    }
    if(N<2){
        cout<<0<<endl;
        return 0;
    }
    ll dp[2][4];
    memset(dp,0x5f,sizeof(dp));
    dp[0][0]=1;dp[0][1]=dp[0][2]=dp[0][3]=-INF;
    dp[1][0]=1;dp[1][1]=dp[1][2]=dp[1][3]=INF;
    for(int i=0;i<N;i++){
        int si=0;
        if(A[i]>=0)si=0;
        else si=1;
        for(int j=3;j>=1;j--){
            dp[0][j]=max(dp[0][j],A[i]*dp[si][j-1]);
            dp[1][j]=min(dp[1][j],A[i]*dp[1-si][j-1]);
        }
        dp[0][1]=max(dp[0][1],(1LL)*A[i]);
        dp[1][1]=min(dp[1][1],(1LL)*A[i]);

    }
    cout<<dp[0][3]<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
