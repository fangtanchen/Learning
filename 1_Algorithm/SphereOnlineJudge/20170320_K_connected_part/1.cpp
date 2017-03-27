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
const int MAXN=15;
const int MAXM=300;
const LL MODU=1e9+9;
int mp[MAXN][MAXN];
int T,N,M,K;
LL dp1[1<<MAXN],dp2[1<<MAXN],dp3[MAXN][1<<MAXN];

LL ModExp(LL a,LL b,LL p){
    LL ret=1;
    while(b){
        if(b&1){
            ret=ret*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return ret;
}

void dfs1(int mask){
    if(dp2[mask]>=0)return;
    dp2[mask]=ModExp(2,dp1[mask],MODU);

    int sub=(mask);
    do{
        if((sub<mask)&&(sub&(mask&-mask))){
            dfs1(sub);
            dp2[mask]=(dp2[mask]-dp2[sub]*(ModExp(2LL,dp1[mask^sub],MODU)))%MODU;
            dp2[mask]=(dp2[mask]+MODU)%MODU;
        }
        sub=(sub-1)&mask;
    }while(sub!=mask);
}


void dfs2(int k,int mask){
    if(dp3[k][mask]>=0)return;
    dp3[k][mask]=0;
    int sub=mask;
    do{
        if(sub<mask && (sub&(mask&-mask))){
            dfs2(k-1,sub^mask);
            dp3[k][mask]+=(dp3[k-1][mask^sub]*dp3[1][sub])%MODU;
            dp3[k][mask]%=MODU;
        }
        sub=(sub-1)&mask;
    }while(sub!=mask);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        memset(mp,0,sizeof(mp));
        scanf("%d%d%d",&N,&M,&K);
        for(int i=1;i<=M;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            mp[a][b]=mp[b][a]=1;
        }
        memset(dp1,0,sizeof(dp1));
        for(int mask=0;mask<(1<<N);mask++){
            for(int i=0;i<N;i++){
                for(int j=i;j<N;j++){
                    if((mask&(1<<i))&&(mask&(1<<j))&&(mp[i][j])){
                        dp1[mask]++;
                    }
                }
            }
        }
        memset(dp2,-1,sizeof(dp2));
        dp2[0]=0;
        for(int mask=1;mask<(1<<N);mask++){
             dfs1(mask);
        }
        memset(dp3,-1,sizeof(dp3));
        for(int mask=1;mask<(1<<N);mask++){
             dp3[1][mask]=dp2[mask];
        }
        dfs2(K,(1<<N)-1);
        printf("Case #%d:\n%lld\n",ti,dp3[K][(1<<N)-1]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
