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
const int MAXN=8005;

const int fac[5]={0,1,2,5};
int num[5];
int dp[2][MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d%d%d",num+1,num+2,num+3),num[1]||num[2]||num[3]){
            int sum=0;
            for(int i=1;i<=3;i++){
                sum+=num[i]*fac[i];
            }
            int now=0,la=1;
            for(int i=0;i<=num[1];i++)
                dp[now][i]=1;
            int jmax=num[1];
            for(int i=2;i<=3;i++){
                swap(now,la);
                memset(dp[now],0,sizeof(dp[now]));
                for(int j=0;j<=jmax;j++){
                    if(!dp[la][j])continue;
                    for(int k=0,v=0;k<=num[i];k++,v+=fac[i]){
                         dp[now][j+v]+=dp[la][j];
                    }
                }
                jmax+=num[i]*fac[i];
            }
            int ans=1;
            for(;dp[now][ans];ans++)
                ;
            printf("%d\n",ans);
        }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
