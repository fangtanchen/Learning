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
typedef unsigned long long int LL;
const int MAXN=1005;

LL N,M;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>M;
    LL ans=0;
    if(N<=M)ans=N;
    else{
         ans=M;
         LL bd=2*(N-M);
         LL l=0,r=1e9+1;
         while((l+1)<r){
             LL mid=(l+r)/2;
             if(mid*(mid+1)>=bd){
                 r=mid;
             }else{
                  l=mid;
             }
         }
         ans+=r;
    }
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
