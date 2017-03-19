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
typedef long long LL;
const int MAXN=2e5+10;


LL A[MAXN];
LL pairs[MAXN];
LL T,N,K;
LL pre[MAXN],npre[MAXN];

map<int,vector<int> > G;

LL Solve(LL bord){
    LL ret=0;
    memset(pairs,0,sizeof(pairs));
    for(int ni=1;ni<=N;ni++){
        pairs[ni]=0;
        LL l=1,r=ni-1;
        while(l+1<r){
            LL mid=(l+r)/2;
        }
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%lld",&T);
    while(T--){
        G.clear();
         scanf("%lld%lld",&N,&K);
         if(K<=N){
              printf("0\n");
              continue;
         }
         A[0]=-1;
         for(int ni=1;ni<=N;ni++){
             scanf("%lld",A+ni);
             G[A[ni]].push_back(ni);
         }
         LL l=-1,r=(N*(N+1))/2;
         while(l+1<r){
             LL mid=(l+r)/2;
             LL tmp=Solve(mid);
             if(tmp<K){
                 l=mid;
             }else{
                  r=mid;
             }
         }
         printf("%lld\n",r);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
