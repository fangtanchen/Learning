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

typedef long long int  ll;
const int maxn=1010;
ll N;
ll m[maxn],r[maxn];


void init(){
    memset(m,0,sizeof(m));
    memset(r,0,sizeof(r));
}
ll gcd(ll a, ll b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

ll Ext_gcd(ll A,ll B, ll &X, ll &Y){
    if(A%B==0){
        X=0;Y=1;
        return 0;
    }
    // a,b huzhi
    ll x,y;
    Ext_gcd(B,A%B,x,y);
    X=y;
    Y=x-(A/B)*y;
    return 0;
}

ll Solve(){
    ll M,R,X;
    M=m[0];R=r[0];
    for(int i=1;i<N;i++){
        ll D=gcd(M,m[i]);
        ll C=r[i]-R;
        if(C%D)return -1;
        ll x,y;
        ll A=M/D,B=m[i]/D;
        C=C/D;
        Ext_gcd(A,B,x,y);
        x=(C*x)%(B);
        while(x<0)x+=B;

        R=R+x*M;
        M=A*m[i];
        R=(R)%M;
    }
    if(R<0)R+=M;
    return R;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    scanf("%ld",&N);
    for(int i=0;i<N;i++){
         scanf("%ld%ld",m+i,r+i);
    }
    ll res=Solve();
    printf("%ld\n",res);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
