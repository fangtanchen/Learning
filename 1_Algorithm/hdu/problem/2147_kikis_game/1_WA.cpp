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
#define A 0
#define B 1

const int dir[3][2]={{1,0},{0,-1},{1,-1}};
const int MAXN=2005;

int N,M;
char dp[MAXN][MAXN];


int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    dp[N][1]=A;
    memset(dp,0,sizeof(dp));
    for(int i=2;i<MAXN;i++){
        dp[N][i]=1-dp[N][i-1];
    }
    for(int i=MAXN-1;i>=1;i--){
        dp[i][1]=1-dp[i+1][1];
    }
    for(int i=MAXN-1;i>=1;i--){
        for(int j=2;j<=MAXN;j++){
            for(int di=0;di<3;di++){
                if(dp[i+dir[di][0]][j+dir[di][1]]==A){
                    dp[i][j]=B;
                    break;
                }
            }

        }
    }
    while(scanf("%d%d",&N,&M),N||M){
        if(A==dp[1][M]){
            printf("What a pity!\n");
        }else{
            printf("Wonderful!\n");
        }
    }

#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
