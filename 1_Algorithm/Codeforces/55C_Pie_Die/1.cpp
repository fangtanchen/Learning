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


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n,m,k;
    cin>>n>>m>>k;
    bool flag=false;
    while(k--){
         int x,y;
         cin>>x>>y;
         if(x<=5||y<=5||n-x<5||m-y<5)
         {
             flag=true;
         }
    }
    if(flag)puts("YES");
    else puts("NO");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
