#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef long long int LL;
const int MAXN=2e5+10;


LL T,N,K;
LL A[MAXN];
map<int,int> mp;
LL tot;
int num[MAXN];

int Check(LL x){
    for(int i=0;i<tot;i++){
        num[i]=0;
    }
    LL now=0;
    LL l=0;
    LL ret=0;
    for(int r=0;r<N;r++){
        now+=num[A[r]];
        num[A[r]]++;
        while(now>x){
             num[A[l]]--;
             now-=num[A[l]];
             l++;
        }
        ret+=(r-l+1);
        if(ret>=K)break;
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
        mp.clear();
         scanf("%lld%lld",&N,&K);
         tot=0;
         for(int i=0;i<N;i++){
             scanf("%lld",A+i);
             if(mp.find(A[i])==mp.end()){
                  mp[A[i]]=tot;
                  tot++;
             }
             A[i]=mp[A[i]];
         }

         LL l=-1,r=(N*(N+1))/2;
         while(l+1<r){
             LL mid=(l+r)/2;
             LL tmp=Check(mid);
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
