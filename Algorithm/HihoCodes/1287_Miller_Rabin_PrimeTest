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

ll table[12]={2,3,5,7,11,13,17,19,23,29,31,37};

ll modmul(ll a,ll b,ll n){
    ll ret=0;
    a=a%n;
    while(b){
        if(b&0x01){
            ret=(ret+a)%n;
        }
        a=(a+a)%n;
        b>>=1;
    }
    return ret;
}

ll modexp(ll a, ll b, ll n){
    ll ret=1;
    a=a%n;
    while(b){
        if(b&0x1)ret=modmul(ret,a,n);
        a=modmul(a,a,n);
        b>>=1;
    }
    return ret;
}

bool IsPrime(ll n){
    if(n<=1)return false;
    if(2==n)return true;
    if(0==n&0x01)return false;

    ll p=n-1;
    while(p%2==0){
        p/=2;
    }
    for(int ti=0;ti<12;ti++){
         ll b=p;
         ll a=table[ti];
         if(a==n)continue;
         ll y=modexp(a,b,n);
         ll imax=n-1;
         while(b<imax){
             ll r=modmul(y,y,n);
             if(r==1&&y!=1&&y!=n-1)return false;
             y=r;
             b*=2;
         }
         if(y!=1)return false;
    }
    return true;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int T;
    cin>>T;
    while(T--){
         ll num;
         scanf("%ld",&num);
         if(IsPrime(num)){
             printf("Yes\n");
         }else{
              printf("No\n");
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
