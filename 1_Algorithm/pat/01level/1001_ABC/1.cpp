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
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;

int dp[MAXN][MAXM][MAXS];
long long int A,B,C;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T;
    cin>>T;
    for(int ti=1;ti<=T;ti++){
         cin>>A>>B>>C;
         if(A+B>C){
             printf("Case #%d: true\n",ti);
         }else{
             printf("Case #%d: false\n",ti);
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
