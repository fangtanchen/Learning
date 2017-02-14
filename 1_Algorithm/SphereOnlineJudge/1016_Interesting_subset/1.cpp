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
const int MAXM=2010;
const int MODU=1e9+7;

LL fac[MAXM];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    fac[0]=1;
    for(int i=1;i<MAXM;i++){
         fac[i]=(2*fac[i-1])%MODU;
    }
    int T;
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
         int N;
         scanf("%d",&N);
          int all=2*N;
          LL ans=0;
          for(int ni=1;ni<=N;ni++){
              LL tmp=all/ni-1;
              ans+=(fac[tmp]-1)*(fac[all-ni-tmp]);
              ans%=MODU;
          }
          printf("Case %d: %lld\n",ti,ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
