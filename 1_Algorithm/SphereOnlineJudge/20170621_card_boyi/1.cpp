#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;

int cardGame(vector<int> A, int n) {
    // write code here
    int dp[310][310];
    memset(dp,0,sizeof(dp));
    for(int l=0;l<n;l++){
        dp[1][l]=A[l];
    }
    for(int di=2;di<=n;di++){
        int lmax=n-di+1;
        for(int l=0;l<lmax;l++){
            int tmp1=min(dp[di-2][l+1],dp[di-2][l+2])+A[l];
            int tmp2=min(dp[di-2][l],dp[di-2][l+1])+A[l+di-1];
            dp[di][l]=max(tmp1,tmp2);
        }
    }
    return dp[n][0];
}

int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    vector<int> G;
    G.push_back(1);
    G.push_back(2);
    G.push_back(100);
    G.push_back(14);
    int n=4;
    cout<<cardGame(G,n)<<endl;




#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
