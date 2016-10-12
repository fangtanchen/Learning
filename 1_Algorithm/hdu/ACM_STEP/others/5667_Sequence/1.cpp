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

ll logmul(ll a,ll b,ll p){
    ll res=0;
    while(b){
        if(0x1&b){
            res=(res+a)%p;
        }
        a=(a+a)%p;
        b>>=1;
    }
    return res;
}

ll logexp(ll a, ll b,ll p){
    ll res=1;
    ll temp=a%p;
    while(b){
        if(0x01&b)res=logmul(res,temp,p);
        temp=logmul(temp,temp,p);
        b>>=1;
    }
    return res;
}


ll f[1000000];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    while(T--){
         ll n,a,b,c,p;
         scanf("%lld%lld%lld%lld%lld",
                 &n,&a,&b,&c,&p);
         ll f[3]={1};
         ll A=logexp(a,b,p);
         f[1]=A;
         for(int i=2;i<=n;i++){
             ll B=logexp(f[1],c,p);
             f[2]=logmul(A,B,p);
             f[2]=logmul(f[2],f[0],p);
             printf("%lld\t",f[2]);
             f[0]=f[1];f[1]=f[2];
             if(i%10==0)printf("\n");
         }

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
