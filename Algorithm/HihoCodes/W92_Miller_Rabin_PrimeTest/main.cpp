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


#define MAXA 12
#define MAX 1000000000;
typedef long long int ll;
ll ta[12]={2,3,5,7,11,13,17,19,23,29,31,37};

ll modpro(ll a,ll b,ll num){
    ll ret=0;
    ll tmp=a%num;
    while(b){
        if(b&0x01){
            ret=ret+tmp;
            if(ret>num)ret-=num;
        }
        tmp=(tmp*2);
        if(tmp>num)tmp-=num;
        b>>=1;
    }
    return ret;
}

ll modexp(ll a, ll b, ll num){
    ll ret=1;
    ll tmp=a%num;
    while(b){
        if(b&0x1)ret=modpro(ret,tmp,num);
        tmp=modpro(tmp,tmp,num);
        b>>=1;
    }
    return ret;
}
bool Miller_Rabin_Test(ll num){
    if(num<=1)return false;
    if(2==num)return true;
    if(0==num&0x1)return false;
    for(ll i=0;i<MAXA;i++){
        if(ta[i]==num)return true;
    }

    ll p=num-1;
    while((p)%2==0){
         p=(p)/2;
    }

    for(ll i=0;i<MAXA;i++){
         ll b=p;
         ll a=ta[i];
         ll ret=modexp(a,b,num);
//         int ma=num-1;
         while(b<num){
             ll temp=modpro(ret,ret,num);
             b*=2;
             if(1==temp && ret!=1 &&ret!=num-1)return false;
             ret=temp;
         }
         if(1!=ret)return false;
    }
    return true;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    ll T;
    scanf("%ld",&T);
    ll num;
    for(ll i=0;i<T;i++){
         scanf("%ld",&num);
         bool ans= Miller_Rabin_Test(num);
         if(ans)printf("Yes\n");
         else printf("No\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
