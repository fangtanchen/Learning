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
const int MAXN=1005;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;


typedef long long int ll;

int N;

ll gcd(ll a,ll b){
    if(0==b)return a;
    else return gcd(b,a%b);
}

ll Solve(ll m1,ll r1, ll m2,ll r2){
    ll A=m1,B=m2,C=r2-r1;
    while(A<0)A+=B;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    ll m1,r1,m2,r2;
    scanf("%lld%lld",&m1,&r1);
    for(int i=1;i<N;i++){
         scanf("%lld%lld",&m2,&r2);
         r1=Solve(m1,r1,m2,r2);
         m1=m1/gcd(m1,m2)*m2;
    }
    printf("%lld\n",r1);
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
