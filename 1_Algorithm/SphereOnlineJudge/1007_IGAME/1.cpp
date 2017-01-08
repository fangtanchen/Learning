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
const int MAXN=1005;

ll A,B;
int T;
ll dp[30][16][3];

ll Solve(ll N){
    memset(dp,0,sizeof(dp));
    dp[0][0][1]=1;
    int i;
    for(i=0;N;i++,N/=10){
        int dight=N%10;
        for(int xi=0;xi<16;xi++){
            for(int yi=0;yi<3;yi++){
                for(int di=0;di<10;di++){
                    int tmpxi=xi^di;
                    int tmpyi=yi;
                    if(di>dght)tmpyi=2;
                    if(di<dight)tmpyi=0;
                    dp[i+1][tmpxi][tmpyi]+=dp[i][xi][yi];
                }
            }
        }
    }
    ll ret=0;
    ret=dp[i][0][0]+dp[i][0][1];
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&A,&B);
        ll s1=Solve(A-1);
        ll s2=Solve(B);
        printf("%lld %lld\n",B-A+1-s2+s1,s2-s1);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
