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
int dp[2000];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int N,M;
    while(EOF!=scanf("%d%d",&M,&N)){
        if(M<=N){
            for(int i=M;i<=N;i++)
                printf("%d%c",i,(i==N?'\n':' '));
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[M]=1;
        int sum=0;
        for(int i=M-N-1;i>=0;i--){
            if(sum)dp[i]=0;
            else dp[i]=1;
            sum=sum-dp[i+N]+dp[i];
        }
        if(!dp[0]){
            bool flag=false;
            for(int i=1;i<=N;i++) {
                if(dp[i]){
                    if(flag)putchar(' ');
                    printf("%d",i);
                    flag=true;
                }
            }
            printf("\n");
        }else printf("none\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
