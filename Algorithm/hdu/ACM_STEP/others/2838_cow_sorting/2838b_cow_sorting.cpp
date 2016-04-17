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

ll at[MAXN];
ll tree[MAXN];

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
//		freopen("out.txt","w",stdout);
	#endif
    ll N;
    while(EOF!=scanf("%ld",&N)){
        ll res=0;
        memset(tree,0,sizeof(tree));
        for(ll ni=0;ni<N;ni++){
            scanf("%ld",at+ni);
             add(at[ni]+1,1);
             ll tt=ni-query(at[ni])*2+at[ni]-1;
             res+=(tt*at[ni]);
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
