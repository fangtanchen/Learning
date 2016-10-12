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

#define MAXN 100010

int f[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    while(T--){
         int n;
         scanf("%d",&n);
         bool flag1=false,flag2=false;
         for(int i=0;i<n;i++){
             scanf("%d",f+i);
             if(!f[i])flag1=true;
             if(f[i]==1)flag2=true;
         }
         if(flag1&&flag2)printf("YES\n");
         else printf("NO\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
