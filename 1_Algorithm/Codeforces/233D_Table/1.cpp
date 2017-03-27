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
typedef long long LL;
const int MAXN=103;
const int MODU=1e9+7;

LL N,M,K;
LL C[MAXN][MAXN];
LL T[MAXN][MAXN];
LL dp[MAXN][MAXN*MAXN];

LL ModExp(LL a,LL b,LL p){
    LL ret=1;
    while(b){
        if(1&b)ret=ret*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ret;
}

void dfs(int di,int k){
    if(dp[di][k]>=0)return;
    dp[di][k]=0;
    for(int i=0;i<=k;i++){
        dfs(di-1,k-i);
        dp[di][k]+=dp[di-1][k-i]*T[di][i];
        dp[di][k]%=MODU;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>M>>K;
    M--;

    C[0][0]=1;
    for(int ri=1;ri<=N;ri++){
        C[ri][0]=1;
        for(int ci=1;ci<=ri;ci++){
            C[ri][ci]=(C[ri-1][ci]+C[ri-1][ci-1])%MODU;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<=N;j++){
            T[i][j]=ModExp(C[N][j],(M+N-i)/N,MODU);
        }
    }

    memset(dp,0,sizeof(dp));
    for(int ki=0;ki<=N;ki++){
         dp[0][ki]=T[0][ki];
    }
    for(int i=1;i<N;i++){
        for(int ki=0;ki<=K;ki++){
            for(int j=0;(j<=N)&&(ki+j<=K);j++){
                dp[i][j+ki]+=dp[i-1][ki]*T[i][j]%MODU;
                dp[i][j+ki]%=MODU;
            }
        }
    }
    cout<<dp[N-1][K]<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
