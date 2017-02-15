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
const int MAXN=2e5+10;
const LL MODU=1e9+7;

LL cnt[MAXN],cnti;
LL num[MAXN];
int vis[MAXN];
int m,p;


LL ModExp(LL a, LL b, LL p){
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ret%p;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    memset(vis,-1,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    cnti=0;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
         scanf("%d",&p);
        if(-1==vis[p]){
             num[cnti]=p;
             vis[p]=cnti++;
         }
         cnt[vis[p]]++;
    }
    LL M=1;
    for(int i=0;i<cnti;i++){
        M=M*(1+cnt[i])%(2*MODU-2);
    }
    LL ans=1;
    for(int i=0;i<cnti;i++){
         LL tmp=M*cnt[i]%(2*MODU-2)/2;
         ans=ans*ModExp(num[i],tmp,MODU)%MODU;
    }
    printf("%lld\n",ans);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
