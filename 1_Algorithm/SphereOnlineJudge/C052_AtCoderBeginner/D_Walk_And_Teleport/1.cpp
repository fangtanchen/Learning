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
const int MAXN=1e5+10;

LL X[MAXN];
LL N;
LL A,B;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>A>>B;
    for(int ni=1;ni<=N;ni++){
         cin>>X[ni];
    }
    LL ans=0;
    for(int ni=2;ni<=N;ni++){
        LL dist=X[ni]-X[ni-1];
        ans=ans+min(dist*A,B);
    }
    printf("%lld\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
