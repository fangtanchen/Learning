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
const int MAXN=1e5+10;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;


LL pre[MAXN],suf[MAXN],a[MAXN];
int N;




LL Gcd(LL x,LL y){
    if(y==0)return x;
    else return Gcd(y,x%y);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
         scanf("%lld",a+i);
    }
    if(N==1)return 0*printf("%lld\n",a[1]+1);
    pre[1]=a[1];
    for(int i=2;i<=N;i++){
        pre[i]=Gcd(pre[i-1],a[i]);
    }
    suf[N]=a[N];
    for(int i=N-1;i>=1;i--){
         suf[i]=Gcd(suf[i+1],a[i]);
    }
    LL ans;
    for(int i=1;i<=N;i++){
        LL a1=pre[i-1];
        LL a2=suf[i+1];
        if(a1==0){
             ans=a2;
        }else{
            if(a2==0)ans=a1;
            else ans=Gcd(a1,a2);
        }
        if(a[i]%ans)break;
    }
    printf("%lld\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
