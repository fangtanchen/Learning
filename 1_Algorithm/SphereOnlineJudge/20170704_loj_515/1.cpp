#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<bitset>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e6+10;

bitset<MAXN> dp[110];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    dp[0][0]=1;
    for(int i=0;i<N;i++){
         int a,b;
         cin>>a>>b;
         for(int j=a;j<=b;j++){
             dp[i+1]|=dp[i]<<(j*j);
         }
    }
    cout<<dp[N].count()<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
