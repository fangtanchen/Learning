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
const int MAXN=1005;
LL ts,tf,ser;
LL a[MAXN];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%lld%lld%lld",&ts,&tf,&ser);
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
         scanf("%d",a+i);
    }
    LL ans=max(ts-a[1]+1,0);
    LL ftm=ts;
    int ni=1;
    for(;a[ni]<ts;ni++){
        ftm+=t;
        if(a[ni]!=a[ni+1]){
            LL tmp=
        }
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
