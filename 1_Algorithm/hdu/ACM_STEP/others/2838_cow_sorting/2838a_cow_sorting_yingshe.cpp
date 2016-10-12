#include<iostream>
#include<cstdio>
//#include<stdio.h>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define  MAXN 100010
typedef long long int ll;
ll num[MAXN];
ll at[MAXN];
ll bt[MAXN];

ll tree[MAXN];
ll sum[MAXN];

ll lowbit(ll k){
     return k&-k;
}

ll add(ll k,ll a){
    while(k<MAXN){
        tree[k]+=a;
        k+=lowbit(k);
    }
    return 0;
}

ll query(ll k){
    ll ret=0;
     while(k>0){
         ret+=tree[k];
         k-=lowbit(k);
     }
     return ret;
}

int  main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    ll N;
    while(EOF!=scanf("%d",&N)){
        for(ll ni=1;ni<=N;ni++){
            scanf("%d",at+ni);
        }
        at[0]=-1;
        memcpy(num,at,sizeof(at));
        sort(num,num+N+1);
        for(ll i=1;i<=N;i++){
             bt[num[i]]=i;
        }

        memset(tree,0,sizeof(tree));
        ll res=0;
        for(ll ni=0;ni<N;ni++){
             ll p=bt[at[ni+1]];
             add(p+1,1);
             ll tt=ni-query(p)*2+p-1;
             res+=(tt*at[ni+1]);
        }
        printf("%ld\n",res);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
