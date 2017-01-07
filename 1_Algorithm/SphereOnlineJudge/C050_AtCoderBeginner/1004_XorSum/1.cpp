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
const ll MAXN=1e18+2;
const ll MODU=1e9+7;

ll dp[100][3][3][2];
// 0:  a_(i+1)^b_(i+1)<N_(i+1)
// 1:  a_(i+1)^b_(i+1)=N_(i+1)
// 2:  a_(i+1)^b_(i+1)>N_(i+1)
//
ll N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%lld",&N);
    memset(dp,0,sizeof(dp));
    dp[0][1][1][0]=1;
    int i;
    for(i=0;N;N>>=1,i++){
        ll ni=N&0x1;
        for(int ci=0;ci<2;ci++){
            for(int xi=0;xi<3;xi++){
                for(int yi=0;yi<3;yi++){
                    for(int ai=0;ai<2;ai++){
                        for(int bi=ai;bi<2;bi++){
                            int tmpxi=xi;
                            if(ai^bi>ni)tmpxi=2;
                            else if(ai^bi<ni)tmpxi=0;
                            int tmpyi=yi;
                            int tmp=(ai+bi+ci)%2;
                            if(tmp<ni)tmpyi=0;
                            else if(tmp>ni)tmpyi=2;
                            int tmpci=(ai+bi+ci)/2;
                            dp[i+1][tmpxi][tmpyi][tmpci]+=dp[i][xi][yi][ci];
                            dp[i+1][tmpxi][tmpyi][tmpci]%=MODU;
                        }
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int xi=0;xi<2;xi++){
        for(int yi=0;yi<2;yi++){
            ans+=dp[i][xi][yi][0];
            ans%=MODU;
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
