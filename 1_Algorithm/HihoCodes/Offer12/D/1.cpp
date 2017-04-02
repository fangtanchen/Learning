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
const int MAXN=1e5+10;
typedef long long LL;

LL A[MAXN];
int N,T;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         scanf("%d",&N);
         for(int i=0;i<N;i++){
             scanf("%lld",A+i);
         }
         LL ans=0;
         for(int i=0;i<N;i++){
             for(int j=i+1;j<N;j++){
                 LL tmp=A[i]*A[j]*(A[i]&A[j]);
                 ans=max(ans,tmp);
             }
         }
         printf("%lld\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
