#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef long long int LL;
const int MAXN=1e5+10;

vector<LL> G[10010];
bool isPrime[MAXN];
int primeList[MAXN];
int pcnt;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    pcnt=0;
    memset(isPrime,true,sizeof(isPrime));
    for(int i=2;i<MAXN;i++){
        if(isPrime[i]){
            primeList[pcnt++]=i;
        }
        for(int pi=0;pi<pcnt;pi++){
            LL tmp=primeList[pi]*i;
            if(tmp>=MAXN)break;
            isPrime[tmp]=false;
            if(i%primeList[pi]==0)break;
        }
    }
    for(int ni=2;ni<MAXN;ni++){
         int tmpn=ni;
         int pp=1;
         for(int pi=0;pi<pcnt;pi++){
             if(primeList[pi]*primeList[pi]>tmpn)break;
             if(tmpn%primeList[pi]==0){
                 int k=0;
                 while(tmpn%primeList[pi]==0){
                      tmpn/=primeList[pi];
                      k++;
                 }
                 pp=pp*(2*k+1);
             }
         }
         if(tmpn!=1)pp*=3;;
         if(pp>=1e4)continue;
         G[pp].push_back(1LL*ni*ni);
    }
    int C,K;
    LL L,R;
    scanf("%d",&C);
    while(C--){
         scanf("%d%lld%lld",&K,&L,&R);
         int l=-1,r=G[K].size();
         while(l+1<r){
             int mid=(l+r)/2;
             if(G[K][mid]>=L){
                  r=mid;
             }else{
                 l=mid;
             }
         }
         int a1=r;
         l=-1,r=G[K].size();
         while(l+1<r){
             int mid=(l+r)/2;
             if(G[K][mid]<=R){
                  l=mid;
             }else{
                 r=mid;
             }
         }
         int a2=l;
         printf("%d\n",a2-a1+1);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
