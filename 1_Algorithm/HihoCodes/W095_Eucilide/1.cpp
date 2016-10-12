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

ll s1,s2,v1,v2,m;

ll gcd(ll a,ll b){
     if(a%b==0)return b;
     return gcd(b,a%b);
}

ll ext_gcd(ll A,ll B,ll &x,ll &y){
    if(A%B==0){
        x=0;y=1;return 0;
    }
    ll tempx,tempy;
    ext_gcd(B,A%B,tempx,tempy);
    x=tempy;
    y=tempx-(A/B)*tempy;
    return 0;
}

ll solve(){
     ll A=v1-v2;
     ll B=m;
     ll C=s2-s1;
     if(A<0)A=A+m;
     ll D=gcd(A,B);

     if(C%D)return -1;

     A=A/D;
     B=B/D;
     C=C/D;
     ll x,y;
     ext_gcd(A,B,x,y);
     x=(x*C)%B;
     while(x<0){
          x=x+B;
     }
     return x;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    while(EOF!=scanf("%lld%lld%lld%lld%lld",
                &s1,&s2,&v1,&v2,&m)){
         printf("%lld\n",solve());
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
