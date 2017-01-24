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

const int MAXN=3e5+10;


int N,K;
ll x[MAXN],id[MAXN];
long long int sum[MAXN];


bool cmp(int i1,int i2){
    return x[i1]<x[i2];
}

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
    sort(id+1,id+N+1,cmp);
    sort(x+1,x+N+1);
    scanf("%d",&K);

    sum[0]=0;
    for(int i=1;i<=N;i++){
         sum[i]=sum[i-1]+x[i];
    }
    ll pt=0;
    for(int ki=2;ki<=K;ki++){
        pt=pt+(ki-1)*x[ki]-sum[ki-1];
    }
    int index=K;
    ll tmp=pt;
    for(int ki=K+1;ki<=N;ki++){
        tmp=tmp+(K-1)*(x[ki]+x[ki-K])-2*(sum[ki-1]-sum[ki-K]);
        if(tmp<pt){
             index=ki;pt=tmp;
        }
    }
    for(int ki=index-K+1;ki<=index;ki++){
         printf("%lld%c",id[ki],(ki==index?'\n':' '));
    }



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
