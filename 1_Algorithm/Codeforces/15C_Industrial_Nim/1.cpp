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
typedef long long LL;

LL Solve(LL x){
    LL t=x&3;
    if(t&1)return t/(LL)2^(LL)1;
    return t/(LL)2^x;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    LL N,M,X;
    LL ans=0;
    cin>>N;
    while(N--){
         cin>>X>>M;
         ans^=(Solve(X+M-1)^(Solve(X-1)));
    }
    if(ans)puts("tolik");
    else puts("bolik");


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
