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

#define INF 0x3f3f3f3f


int dp[52][52][52][3][3][4];

void gao(int& x,int y){
     x=min(x,y);
}



void init(){
    memset(dp,INF,sizeof(dp));
    dp[1][0][0][0][0][3]=1;
    dp[0][1][0][1][0][3]=1;
    dp[0][0][1][2][0][3]=1;

    for(int i=0;i<=50;i++){
        for(int j=0;j<=50;j++){
            for(int k=0;k<=50;k++){
                for(int p1=0;p1<3;p1++){
                    for(int p2=0;p2<3;p2++){
                       for(int s=1;s<4;s++){
                            if(dp[i][j][k][p1][p2][s]!=INF){
                                for(int nxt=0;nxt<3;nxt++){
                                    int ii=i,jj=j,kk=k;
                                    if(nxt==0)ii++;
                                    if(nxt==1)jj++;
                                    if(2==nxt)kk++;

                                    int ts=s+max(p1,nxt)+2;
                                    if(ts>3)ts=3;
                                    gao(dp[ii][jj][kk][nxt][p2][ts],dp[i][j][k][p1][p2][s]+max(p1,nxt)+2);

                                    ts=max(p2,nxt)+2;
                                    int temp=max(ts-s,1);
                                    gao(dp[ii][jj][kk][nxt][p1][temp],dp[i][j][k][p1][p2][s]+temp);
                                }
                            }

                        }
                    }
                }
            }
        }
    }

}
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    init();
    dp[0][0][0][0][0][1]=0;
    int Q,N,M,K;
    scanf("%d",&Q);
    while(Q--){
         scanf("%d%d%d",&N,&M,&K);
         int ans=INF;
         for(int p1=0;p1<3;p1++){
             for(int p2=0;p2<3;p2++){
                 for(int s=1;s<4;s++){
                     if(INF!=dp[N][M][K][p1][p2][s]){
                         gao(ans,dp[N][M][K][p1][p2][s]);
                     }
                 }
             }
         }
         printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
