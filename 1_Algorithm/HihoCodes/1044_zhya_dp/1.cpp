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
#define MAXP 1024
#define MAXN 1005
#define MAXM 15

int N,M,Q;
int dp[2][MAXP];
int bitcnt[MAXP];
int nxt[MAXP];
int aft[MAXP];
int W[MAXP];

void Init(){
    memset(dp,0,sizeof(dp));
    memset(bitcnt,0,sizeof(bitcnt));
    memset(nxt,0,sizeof(nxt));
    const int maxi=1<<M;
    for(int i=0;i<maxi;i++){
        int mulp=i;
        for(int k=0;k<M;k++){
            if(1&mulp)bitcnt[i]++;
            mulp>>=1;
        }
        nxt[i]=(2*i)%maxi;
        aft[i]=nxt[i]+1;
    }
}

void Solve(){
    const int hbit=1<<(M-1);
    const int lbit=1;
    const int maxs=1<<M;

    int si=0,di=1;
    for(int i=1;i<=N;i++){
        memset(dp[di],0,sizeof(dp[di]));
        for(int s=0;s<maxs;s++){
            if(bitcnt[s]>Q)continue;
            if(dp[di][nxt[s]]<dp[si][s]){
                dp[di][nxt[s]]=dp[si][s];
            }
            int temp=dp[si][s]+W[i];
            if(dp[di][aft[s]]<temp){
                dp[di][aft[s]]=temp;
            }
        }
        si=1-si;
        di=1-di;
    }
    int ans=0;
    for(int s=0;s<maxs;s++){
         if(bitcnt[s]>Q)continue;
         if(ans<dp[si][s])ans=dp[si][s];
    }
    printf("%d\n",ans);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d%d",&N,&M,&Q);
    for(int i=1;i<=N;i++){
         scanf("%d",W+i);
    }
    Init();
    Solve();


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
