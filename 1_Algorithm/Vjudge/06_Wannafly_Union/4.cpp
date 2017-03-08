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
const int MAXN=1025;
const int MODU=1e9+7;
typedef long long int LL;

int N,M,T;;
int cnt[MAXN];
LL fac[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    fac[0]=1;
    for(int i=1;i<MAXN;i++){
        fac[i]=fac[i-1]*i%MODU;
    }
    cin>>T;
    while(T--){
        cin>>N>>M;
        memset(cnt,0,sizeof(cnt));
        for(int ri=1;ri<=N;ri++){
            for(int ci=1;ci<=M;ci++){
                cnt[ri^ci]++;
            }
        }
        LL ans=1;
        for(int i=0;i<MAXN;i++){
            ans=ans*fac[cnt[i]]%MODU;
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
