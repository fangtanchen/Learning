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
const int MAXN=1050;

int dp[MAXN][MAXN];
char S[MAXN],T[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%s",S+1);
    scanf("%s",T+1);
    memset(dp,0,sizeof(dp));
    int i,j;
    for(i=1;S[i];i++){
        for(j=1;T[j];j++){
            int tmp=max(dp[i-1][j],dp[i][j-1]);
            if(S[i]==T[j])tmp=max(dp[i-1][j-1]+1,tmp);
            dp[i][j]=max(dp[i][j],tmp);
        }
    }
    printf("%d\n",i-1-dp[i-1][i-1]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
