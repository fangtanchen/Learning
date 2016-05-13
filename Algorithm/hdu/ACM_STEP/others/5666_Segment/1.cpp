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

typedef long long ll;


ll logmul(ll a, ll b, ll p){
    ll res=0;
    while(b){
        if(b&0x1)res=(res+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return res%p;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    ll p,q;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&q,&p);
        ll res=0;
        res=logmul(q-2,(q-1)/2,p);
        printf("%lld\n",res);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
