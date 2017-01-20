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
typedef long long int ll;

ll a,b,w,x,c;
ll blist[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%lld%lld%lld%lld%lld",&a,&b,&w,&x,&c);
    if(c<=a){
         printf("0\n");
         return  0;
    }
    blist[0]=b;
    ll blen=0;
    ll da,dc;
    da=dc=0;

    for(int i=1;i<MAXN;i++){
        dc++;
        if(b>=x){
            b=b-x;
        }else{
            da++;
            b=w-(x-b);
        }
        if(b!=blist[0]){
            blist[i]=b;
        }else{
            blen=i;
            break;
        }
    }
    ll tmp=(c-a)/(dc-da)-1;
    ll ans=tmp*(blen);
    a=a-da*tmp;
    c=c-dc*tmp;
    while(c>a){
        c--;
        ans++;
        if(b>=x){
            b=b-x;
        }else{
            a--;
            b=w-(x-b);
        }
    }
    printf("%lld\n",ans);




	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
