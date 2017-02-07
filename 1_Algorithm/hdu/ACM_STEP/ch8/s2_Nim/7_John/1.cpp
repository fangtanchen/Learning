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
const int MAXN=110;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int T,N,A;
    scanf("%d",&T);
    while(T--){
         scanf("%d",&N);
         int flag=0,ans=0;
         for(int i=0;i<N;i++){
             scanf("%d",&A);
             ans^=A;
             if(A!=1)flag=1;
         }
         if(flag){
             if(ans)puts("John");
             else puts("Brother");
         }else{
             if(N&1)puts("Brother");
             else puts("John");
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
