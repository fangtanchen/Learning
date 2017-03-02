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
typedef long long int LL;
const int MAXN=1005;

bool IsPrime(int x){
    if(x==1)return false;
    if(x==2)return true;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}

LL Gcd(LL x,LL y){
    if(y==0)return x;
    else return Gcd(y,x%y);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T;
    cin>>T;
    while(T--){
         int N;
         cin>>N;
         LL l=N,r=N+1;
         while(!IsPrime(l))
             l--;
         while(!IsPrime(r))
             r++;
         LL u=l*r-2*r-2*l+2*N+2;
         LL d=2*l*r;
         LL p=Gcd(u,d);
         printf("%lld/%lld\n",u/p,d/p);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
