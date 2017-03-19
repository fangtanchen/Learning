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
const int MODU=1e9+7;

LL dp[2][2][10];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    memset(dp,0,sizeof(dp));
    cin>>N;
    int si=0,di=1;
    dp[di][0][0]=1;
    for(int i=0;i<N;i++){
         swap(si,di);
         memset(dp[di],0,sizeof(dp[di]));
         for(int ai=0;ai<2;ai++){
             for(int j=0;j<9;j++){
                  int x=j/3,y=j%3;
                  dp[di][ai][y*3+0]+=dp[si][ai][j];
                  dp[di][ai][y*3+0]%=MODU;
                  if(ai+1<2){
                      dp[di][ai+1][y*3+1]+=dp[si][ai][j];
                      dp[di][ai+1][y*3+1]%=MODU;
                  }
                  if(x!=2||y!=2){
                       dp[di][ai][y*3+2]+=dp[si][ai][j];
                       dp[di][ai][y*3+2]%=MODU;
                  }
             }
         }
    }
    LL ans=0;
    for(int ai=0;ai<2;ai++){
        for(int j=0;j<9;j++){
            ans+=dp[di][ai][j];
            ans%=MODU;
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
