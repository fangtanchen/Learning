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
const int MAXN=1005;
ll l,r;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%lld%lld",&l,&r);
    ll tmp=l^r;
    int c=0;
    while(tmp){
         tmp>>=1;
         c++;
    }
    ll ans=0;
    for(int i=0;i<c;i++){
         ans=(ans<<1)^1;
    }
    printf("%lld\n",ans);



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
