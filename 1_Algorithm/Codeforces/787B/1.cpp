#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<set>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=10005;

set<int> s[MAXN];
int N,M,K;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    bool ans=false;
    for(int i=0;i<M;i++){
         scanf("%d",&K);
         bool flag=true;
         for(int j=0;j<K;j++){
             int x;
             scanf("%d",&x);
             if(s[i].count(-x)){
                  flag=false;
             }
             s[i].insert(x);
         }
         if(flag)ans=true;
    }
    if(ans)puts("YES");
    else puts("NO");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
