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
const int MAXN=1005;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;


int Joseph(int n,int k){
    if(n==1)return 0;
    if(n<k){
        int ret=0;
        for(int i=2;i<=n;i++){
            ret=(ret+k)%i;
        }
        return ret;
    }
    int s=Joseph(n-n/k,k);
    if(s<n%k){
        return s+n-n%k;
    }else{
        int tmp=s-n%k;
        return tmp+tmp/(k-1);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    while(T--){
         int N,K;
         scanf("%d%d",&N,&K);
         int ans=Joseph(N,K);
         printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
