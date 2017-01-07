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
typedef long long int ll;
const int MAXN=2010;

ll dp[MAXN];
int N,S;
int w[MAXN],c[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&S);
    for(int i=0;i<N;i++){
         scanf("%d%d",w+i,c+i);
    }
    memset(dp,0,sizeof(dp));
    for(int ni=0;ni<N;ni++){
        for(int mi=w[ni];mi<=S;mi++){
             dp[mi]=max(dp[mi],dp[mi-w[ni]]+c[ni]);
        }
    }
    printf("%lld\n",dp[S]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
