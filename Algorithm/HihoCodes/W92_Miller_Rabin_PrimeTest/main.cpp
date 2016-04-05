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

class BigInt{
   ll a[5];
   BigInt(){
        a[0]=1;
        //a[1]=a[2]=0;
        for(int i=1;i<5;i++)a[i]=0;
   }

   Multiply(BigInt x){
       int c=0;
       for(int i=0;i<3;i++){
       }
   }
};

ll modexp(ll a, ll b, ll num){
    ll ret=1;
    ll tmp=a;
    while(b){
        if(b&0x1)ret=ret*tmp%num;
        ret=(ret*ret);
    }
}
bool Miller_Rabin_Test(ll num){
    if(num==1)return false;
    if(2==num)return true;
    if(num%2==0)return false;

    ll p=num-1;
    while((p)%2==0){
         p=(p)/2;
    }

    for(int i=0;i<MAXA;i++){
         int u=p;
         int a=ta[i];
    }

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    ll num;
    for(int i=0;i<T;i++;){
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
