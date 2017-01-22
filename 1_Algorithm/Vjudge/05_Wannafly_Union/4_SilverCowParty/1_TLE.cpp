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
const int MAXN=1010;
const int INF=0x3f3f3f3f;

int dp[MAXN][MAXN];
int N,M,X;

void Init(){
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<MAXN;i++){
        dp[i][i]=0;
    }
}

void Floyd(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            if(i==k)continue;
            if(dp[i][k]==INF)continue;
            for(int j=1;j<=N;j++){
                if((i==j)||(k==j)||dp[k][j]==INF)continue;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}

int scan(){
    int ch=0;
    while((ch=getchar()),ch<'0'||ch>'9')
        ;
    int ret=ch-'0';
    while((ch=getchar()),ch>=0&&(ch<=9)){
        ret=ret*10+ch-'0';
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

    while(EOF!=scanf("%d%d%d",&N,&M,&X)){
        Init();
        for(int mi=0;mi<M;mi++){
            int u,v,c;
            u=scan();
            v=scan();
            c=scan();
            dp[u][v]=min(c,dp[u][v]);
        }
        Floyd();
        int ans=0;
        for(int i=1;i<=N;i++){
            if(dp[i][X]==INF||dp[X][i]==INF)continue;
            int tmp=dp[i][X]+dp[X][i];
            ans=max(tmp,ans);
        }
        printf("%d\n",ans);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
