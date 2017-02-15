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
const int MODU=1e7+7;

int T,N;
int cnt[50];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>T;
    for(int ti=1;ti<=T;ti++){
         cin>>N;
         memset(cnt,0,sizeof(cnt));
         for(int ni=0;ni<N;ni++){
             int x;
             cin>>x;
             int i=0;
             while(x){
                 if(1&x) cnt[i]++;
                 x>>=1;
                 i++;
             }
         }
         long long int ans=0;
         for(int i=0;i<33;i++){
              ans=ans+(1LL)*cnt[i]*(N-cnt[i]);
              ans%=MODU;
         }
         ans=(ans+ans)%MODU;
         printf("Case %d: %lld\n",ti,ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
