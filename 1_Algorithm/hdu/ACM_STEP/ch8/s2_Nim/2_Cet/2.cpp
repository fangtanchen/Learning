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
const int fac2[11]={1,2,4,8,16,32,64,128,256,512,1024};
const int MAXN=1024;

int dp[MAXN];
int N;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d",&N)){
             memset(dp,0,sizeof(dp));
             dp[0]=0;
             for(int i=1;i<=N;i++){
                 for(int j=0;fac2[j]<=i;j++){
                     if(!dp[i-fac2[j]]){
                         dp[i]=1;
                         break;
                     }
                 }
             }
             if(dp[N])puts("Kiki");
             else puts("Cici");
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
