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
const int MAXN=1005;
const LL MODU=1e9+7;

LL n,a,b,c,d;
LL dp[2][MAXN];
LL C[MAXN][MAXN];
LL fac[MAXN];
LL prod[MAXN];

LL ModExp(LL a,LL b,LL p){
    LL ret=1;
    while(b){
        if(1&b)ret=ret*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ret;
}

LL Call(LL k,LL left){
    memset(prod,0,sizeof(prod));
    prod[0]=1;
    LL tmpn=left;
    LL pp=1;
    if(left<k*c)return 0;

    int ci=0;
    while(tmpn>=k){
        pp=pp*C[tmpn][k]%MODU;
        tmpn-=k;
        ci++;
        if(ci<c)continue;
        prod[ci]=pp*ModExp(fac[ci],MODU-2,MODU)%MODU;
        if(ci>d)break;
    }

    return 0;

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    memset(C,0,sizeof(C));
    C[0][0]=1;
    fac[0]=fac[1]=1;
    for(int i=1;i<MAXN;i++){
        fac[i]=fac[i-1]*i%MODU;
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MODU;
        }
    }
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    if(a*c>n)return 0*printf("0\n");

    memset(dp,0,sizeof(dp));
    int now=0,la=1;

    Call(a,n);
    dp[now][0]=1;
    for(int i=c,v=c*a;i<=d&&v<=n;i++,v+=a){
        dp[now][v]=prod[i];
    }
    int jmax=min(n,a*d);
    for(int ni=a+1;ni<=b;ni++){
        swap(now,la);
        memset(dp[now],0,sizeof(dp[now]));
        for(int j=0;j<=jmax;j++){
            LL tmpn=n-j;
            Call(ni,tmpn);
            dp[now][j]=(dp[la][j]+dp[now][j])%MODU;
            for(int k=c,v=ni*c;k<=d&&v<=tmpn;k++,v+=ni){
                dp[now][j+v]=(dp[now][j+v]+dp[la][j]*prod[k])%MODU;
            }
        }
        jmax=min(n,jmax+ni*d);
    }
    printf("%lld\n",dp[now][n]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
