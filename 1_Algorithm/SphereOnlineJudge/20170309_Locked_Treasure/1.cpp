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
const int MAXN=45;

long long dp[MAXN][MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    dp[0][0]=1;
    for(int i=1;i<32;i++){
        dp[i][0]=1;
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
    int n,m,T;
    cin>>T;
    while(T--){
         cin>>n>>m;
         cout<<dp[n][m-1]<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
