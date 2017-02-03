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
const int MAXN=50;

int e[MAXN];
ll dp[MAXN];

ll C(ll n,ll m){
    ll ret=1;
    m=min(m,n-m);
    for(int i=1;i<=m;i++){
        ret=ret*(n-i+1)/i;
    }
    return ret;
}

void DFS(int a,int step,int num,int sum){
    if(sum>num)return;
    if(sum==num){
        ll s=1;
        int k=1;
        for(int i=1;i<step;i++){
            if(e[i]!=e[i-1]){
                s*=C(dp[e[i-1]]+k-1,k);
                k=0;
            }
            k++;
        }
        s*=C(dp[e[step-1]]+k-1,k);
        dp[num+1]+=s;
        return;
    }
    int imax=num-sum;
    for(int i=a;i<=imax;i++){
        e[step]=i;
        DFS(i,step+1,num,sum+i);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    memset(dp,0,sizeof(dp));
    dp[1]=dp[2]=1;
    for(int i=3;i<=40;i++){
         DFS(1,0,i-1,0);
    }
    int n;
    while(EOF!=scanf("%d",&n)){
         printf("%lld\n",dp[n]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
