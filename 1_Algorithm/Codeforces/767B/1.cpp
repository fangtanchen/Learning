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
LL ts,tf,ser;
LL a[MAXN];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%lld%lld%lld",&ts,&tf,&ser);
    tf=(tf-ts)/ser*ser+ts;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
         scanf("%lld",a+i);
    }
    a[N+1]=1e13+5;
    a[0]=-1;
    int ni=1;
    LL ftm=ts,ans=1e13;
    LL ansi=-1;
    int imax=N+1;
    for(ni=1;ni<=imax;ni++){
        if(ftm<a[ni]){
            ans=0;
            ansi=ftm;
            break;
        }
        if(a[ni]!=a[ni-1]){
            LL tmp=ftm-a[ni]+1;
            if(tmp<ans){
                 ans=tmp;
                 ansi=a[ni]-1;
            }
        }
        ftm+=ser;
        if(ftm>tf-ser)break;
        if(a[ni]!=a[ni+1]){
            LL tmp=ftm-a[ni];
            if(tmp<ans){
                 ans=tmp;
                 ansi=a[ni];
            }
        }
    }
    printf("%lld\n",ansi);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
