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
const int MAXM=(1<<20)+10;
typedef long long LL;

LL A[MAXN];
int N,T;
LL vis[MAXM];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
        memset(vis,-1,sizeof(vis));
         scanf("%d",&N);
         LL ans=0;
         for(int i=0;i<N;i++){
             scanf("%lld",A+i);
             LL tmpA=A[i];
             do{
                 if(vis[tmpA]!=-1){
                     ans=max(ans,vis[tmpA]*A[i]*(A[i]&vis[tmpA]));
                 }
                  if(vis[tmpA]<A[i])vis[tmpA]=A[i];
                  tmpA=(tmpA-1)&A[i];
             }while(tmpA<A[i]);
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
