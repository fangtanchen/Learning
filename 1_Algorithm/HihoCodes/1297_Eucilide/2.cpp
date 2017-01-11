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

ll s1,s2,v1,v2,m;
ll gcd(ll x,ll y){
     if(0==y)return x;
     else return gcd(y,x%y);
}

void exgcd(ll A,ll B,ll &x,ll &y){
    if(A%B==0){// when B=1
        x=0;
        y=1;
        return;
    }
    ll a,b;
    exgcd(B,A%B,a,b);
    x=b;
    y=a-A/B*b;
}

ll Solve(ll s1,ll s2,ll v1,ll v2,ll m){
    ll A=v1-v2;
    ll B=m;
    ll C=s2-s1;
    while(A<=0){
        A+=m;
    }
    ll D=gcd(A,B);
    if(0!=C%D)return -1;
    A/=D;B/=D;C/=D;
    ll x,y;
    exgcd(A,B,x,y);
    x=(x*C)%B;
    while(x<0){
         x+=B;
    }
    return x;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%lld%lld%lld%lld%lld",&s1,&s2,&v1,&v2,&m);
    printf("%lld\n",Solve(s1,s2,v1,v2,m));

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
