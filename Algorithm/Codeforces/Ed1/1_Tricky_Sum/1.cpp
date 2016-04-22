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

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    while(T--){
         ll n;
         scanf("%lld",&n);
         ll ans=n*(n+1)/2;
         for(int i=1;i<=n;i*=2){
             ans=ans-2*i;
         }
         printf("%lld\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
