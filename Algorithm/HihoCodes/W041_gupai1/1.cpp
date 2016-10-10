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
const int MOD=19999997;

int N;
int dp[4];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    dp[1]=1;dp[2]=2;
    int a,b,c;
    c=0;a=1;b=2;
    for(int i=3;i<=N;i++){
         dp[c]=(dp[a]+dp[b])%MOD;
         a=b;b=c;c=3-a-b;
    }
    if(1==N)dp[b]=1;
    if(2==N)dp[b]=2;
    cout<<dp[b]<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
