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
typedef long long LL;
const int MAXN=1005;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    LL X;
    cin>>X;
    X*=2;
    LL l=0,r=1e9;
    while((l+1)<r){
        LL mid=(l+r)/2;
        LL tmp=(mid+1)*mid;
        if(tmp>=X){
            r=mid;
        }else{
             l=mid;
        }
    }
    printf("%lld\n",r);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
