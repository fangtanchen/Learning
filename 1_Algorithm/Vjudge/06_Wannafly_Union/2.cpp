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
const int MAXN=1005;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;
typedef long long int LL;


LL N;
int T;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>T;
    while(T--){
         cin>>N;
         N--;
         N%=6;
         int a[20]={1,3,2,-1,-3,-2};
         int ans=0;
         for(int i=0;i<=N;i++){
              ans+=a[i];
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
