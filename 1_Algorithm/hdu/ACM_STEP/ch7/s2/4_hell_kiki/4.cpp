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

ll M[10],R[10];
ll N,T;

ll gcd(ll x,ll y){
    if(y==0)return x;
    else return gcd(y,x%y);
}

ll extend_gcd(ll A,ll B,ll &x,ll &y){
    if(B==1){
        x=0;y=1;
        return 0;
    }
    ll tx,ty;
    extend_gcd(B,A%B,tx,ty);
    x=ty;
    y=tx-A/B*ty;
    return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%lld",&T);
    for(ll ti=1;ti<=T;ti++){
         scanf("%lld",&N);
         for(ll ni=0;ni<N;ni++){
             scanf("%lld",M+ni);
         }
         for(ll ni=0;ni<N;ni++){
             scanf("%lld",R+ni);
         }
         ll tmpM=M[0],tmpA=R[0];
         bool flag=true;
         for(ll ni=1;ni<N;ni++){
             ll A=tmpM,B=M[ni];
             ll C=R[ni]-tmpA;
             while(A<=0)A+=B;
             ll D=gcd(A,B);
             if(C%D!=0){
                 flag=false;
                 break;
             }
             A/=D,B/=D,C/=D;
             ll x,y;
             extend_gcd(A,B,x,y);
             x=x*C%B;
             while(x<=0)x+=B;// cannot output 0
             tmpA=x*tmpM+tmpA;
             tmpM=tmpM/D*M[ni];
             tmpA%=tmpM;// important
         }
         while(tmpA<=0)tmpA+=tmpM;
         if(flag){
             printf("Case %lld: %lld\n",ti,tmpA);
         }else{
             printf("Case %lld: %d\n",ti,-1);
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
