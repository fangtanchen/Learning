#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;
typedef long long int LL;

int T;
LL N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>T;
    while(T--){
         cin>>N;
         if(1==N){
             cout<<1<<endl;
             continue;
         }
         N*=2;
         LL sn=sqrt(N)+1;
         LL ans=1;
         for(LL i=sn;i>=1;i--){
             if(N%i==0){
                 LL j=N/i;
                 LL d=abs(i-j);
                 if(d&1){
                     ans=min(i,j);
                     break;
                 }
             }
         }
         cout<<ans<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
