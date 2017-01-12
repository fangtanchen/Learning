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

int kk[10010][10];
int dp[20][10][10];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int k,m;
    scanf("%d%d",&k,&m);
    int a[11];
    for(int i=0;i<10;i++){
        scanf("%d",a+i);
    }
    memset(kk,0,sizeof(kk));
    for(int i=0;i<10;i++){
        kk[i][i]=1;
        dp[0][i][i]=kk[i][i];
    }
    for(int i=10;i<20;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                kk[i][j]+=a[k]*kk[i-k-1][j];
                kk[i][j]%=m;
            }
            dp[1][i][j]=kk[i][j];
        }
    }
    for(int di=2;di<20;di++){
        printf("%10d:\n",di);
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    dp[di][i][j]+=dp[di-1][i][k]*dp[di-1][k][j];
                    dp[di][i][j]%=m;
                }
                printf("%5d",dp[di][i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
