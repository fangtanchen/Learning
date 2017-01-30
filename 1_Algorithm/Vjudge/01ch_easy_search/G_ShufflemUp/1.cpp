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
const int MAXC=2100;

char dp[2][MAXC];
char ed[MAXC];
int C,N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int ni=1;ni<=N;ni++){
        scanf("%d",&C);
        int now=0,la=1;
        scanf("%s",dp[now]);
        scanf("%s",dp[now]+C);
        scanf("%s",ed);
        int ans=-1;
        for(int ki=1;ki<200;ki++){
            swap(now,la);
            for(int i=0;i<C;i++)
                dp[now][i*2+1]=dp[la][i];
            for(int i=0;i<C;i++)
                dp[now][2*i]=dp[la][i+C];
            dp[now][2*C]=0;
            if(strcmp(dp[now],ed)==0){
                ans=ki;
                break;
            }
        }
        printf("%d %d\n",ni,ans);

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
