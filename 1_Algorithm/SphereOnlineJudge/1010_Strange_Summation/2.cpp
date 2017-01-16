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
const int MAXN=10005;
typedef long long int ll;

ll dp[70][2],num[70][2];
ll P,Q;

int Top(ll x){
    if(0==x)return 0;
    int ret=63;
    for(;((x>>ret)&0x01)==0;ret--)
        ;
    return ret;
}

ll Call(ll up){
    int digit[70],cntd=0;
    ll tmp=up;
    while(tmp){
        digit[cntd]=tmp&0x01;
        tmp>>=1;
        cntd++;
    }
    std::reverse(digit,digit+cntd);
    memset(dp,0,sizeof(dp));
    memset(num,0,sizeof(num));
    num[0][1]=dp[0][1]=1;
    int cmax=cntd-1;
    for(int ci=0;ci<cmax;ci++){
        for(int j=0;j<2;j++){
            if(num[ci][j]){
                int maxk=(j==1?digit[ci+1]:1);
                for(int k=0;k<=maxk;k++){
                    int g=(j==1)&&(k==maxk);
                    int off=(k==1)&&(num[ci][j]&0x01);
                    num[ci+1][g]+=num[ci][j];
                    dp[ci+1][g]^=((dp[ci][j]<<1)^off);
                }
            }
        }
    }
    return dp[cmax][0]^dp[cmax][1];
}

ll Solve(ll x){
    __int128 q=1;
    ll ret=0;
    while(q<x){
        ret=((ret<<1)^Call(q));
        q=(q<<1)^1;
    }
    ret=((ret<<1)^Call(x));
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);

    for(int ti=1;ti<=T;ti++){
         scanf("%lld%lld",&P,&Q);
         int offset=Top(Q)-Top(P-1);
         printf("Case %d: %lld\n",ti,Solve(Q)^(Solve(P-1)<<offset));
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
