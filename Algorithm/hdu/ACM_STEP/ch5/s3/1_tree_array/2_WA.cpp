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


#define MAXN 50004
int val[MAXN];
int dp[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);

    for(int ti=1;ti<=T;ti++){
         printf("Case %d:\n",ti);

         int N;
         scanf("%d",&N);
         memset(dp,0,sizeof(dp));
         for(int i=1;i<=N;i++){
              scanf("%d",val+i);
              dp[i]=dp[i-1]+val[i];
         }


        char s[55];
        int a,b;
        while(scanf("%s %d %d",s,&a,&b),strcmp("End",s)){
            if(!strcmp(s,"Query")){
               int ans=dp[b]-dp[a-1];
                printf("%d\n",ans);
            }else if(!strcmp(s,"Add")){
                val[a]+=b;
                for(int i=a;i<=N;i++){
                     dp[i]+=b;
                }
            }else if(!strcmp(s,"Sub")){
                 val[a]-=b;
                 for(int i=a;i<=N;i++){
                      dp[i]-=b;
                 }
            }
        }

    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
