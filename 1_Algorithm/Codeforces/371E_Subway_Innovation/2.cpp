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

typedef long long int ll;

const int MAXN=3e5+5;

ll x[MAXN],id[MAXN];
ll sum[MAXN];
int N,K;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int ni=1;ni<=N;ni++){
         scanf("%lld",x+ni);
         id[ni]=ni;
    }
    sort(id+1,id+1+N,[](int a,int b){return x[a]<x[b];});
    sort(x+1,x+1+N);

    sum[0]=0;
    for(int ni=1;ni<=N;ni++){
        sum[ni]=sum[ni-1]+x[ni];
    }

    scanf("%d",&K);
    ll index=1,pt=0,tmp=0;

    for(int ki=K+1;ki<=N;ki++){
        tmp+=(K-1)*(x[ki]+x[ki-K])-2*(sum[ki-1]-sum[ki-K]);
        if(tmp<pt)pt=tmp,index=ki-K+1;
    }
    for(int ki=index,i=1;i<=K;i++,ki++){
         printf("%lld%c",id[ki],i==K?'\n':' ');
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
