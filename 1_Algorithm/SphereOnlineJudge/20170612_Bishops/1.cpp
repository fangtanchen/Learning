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
const int MAXN=50;

typedef long long LL;

LL dp1[MAXN][MAXN],dp2[MAXN][MAXN];
LL ans;
LL cnt1[MAXN],cnt2[MAXN];
int N,K;


void Init(int N,int K){
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    for(int i=1;i<=N;i++){
        cnt1[i]=(i%2?i:i-1);
    }
    for(int i=1;i<N;i++){
        cnt2[i]=(i%2?i+1:i);
    }
    dp1[0][0]=dp2[0][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=i;j++){
             dp1[i][j]=dp1[i-1][j];
             if(j>0)dp1[i][j]+=dp1[i-1][j-1]*(cnt1[i]-j+1);
        }
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<=i;j++){// j<=i not j<=K
            dp2[i][j]=dp2[i-1][j];
            if(j>0)dp2[i][j]+=dp2[i-1][j-1]*(cnt2[i]-j+1);
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    while(cin>>N>>K,N+K){
        Init(N,K);
        LL ans=0;
        for(int i=0;i<=K;i++){
             ans=ans+dp1[N][i]*dp2[N-1][K-i];
        }
        cout<<ans<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
