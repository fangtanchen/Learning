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
typedef long long int LL;
const int MAXN=5e3+10;
const int MAXS=8;
const int MAXM=210;

LL R[MAXS][MAXN][MAXM];
LL dp[2][MAXN];
LL N,M;
LL A[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%lld%lld",&N,&M);
    A[1]=0;
    for(int i=2;i<=N;i++){
         scanf("%lld",A+i);
         A[i]+=A[i-1];
    }
    memset(R,0,sizeof(R));
    for(int ni=1;ni<=N;ni++){
        for(int mi=1;mi<=M;mi++){
            scanf("%lld",&R[0][ni][mi]);
        }
    }
    int fac[10];
    fac[0]=1;
    for(int i=1;i<MAXS;i++)fac[i]=2*fac[i-1];
    for(int si=1;si<MAXS;si++){
        int nimax=N-fac[si]+1;
        for(int ni=1;ni<=nimax;ni++){
            for(int mi=1;mi<=M;mi++){
                R[si][ni][mi]=max(R[si-1][ni][mi],R[si-1][ni+fac[si-1]][mi]);
            }
        }
    }
    LL ans=0;
    for(int di=2;di<=N;di++){
        int si=0;
        while(fac[si]<=di){
            si++;
        }
        si--;
        int nimax=N-di+1;
        for(int ni=1;ni<=nimax;ni++){
            LL tmpans=0;
            for(int mi=1;mi<=M;mi++){
                tmpans+=max(R[si][ni][mi],R[si][ni+di-fac[si]][mi]);
            }
            ans=max(ans,tmpans-(A[ni+di-1]-A[ni]));
        }
    }
    printf("%lld\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
