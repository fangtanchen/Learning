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

LL x,y,z;
int T;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         scanf("%lld%lld%lld",&x,&y,&z);
         if(x>y)swap(x,y);
         if(x>z)swap(x,z);
         if(y>z)swap(y,z);
         LL tmp=2*(x+y);
         if(tmp<=z)printf("%lld\n",x+y);
         else printf("%lld\n",(x+y+z)/3);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
