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
int dp[40][10][10];
int k,m;
int a[11];

void Create(){
    memset(kk,0,sizeof(kk));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<10;i++){
        kk[i][i]=1;
        dp[0][i][i]=kk[i][i];
    }
    for(int i=10;i<20;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                kk[i][j]+=a[k]*kk[i-k-1][j];
            }
            kk[i][j]%=m;
            dp[1][i-10][j]=kk[i][j];
        }
    }
    for(int di=2;di<40;di++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    dp[di][i][j]+=dp[di-1][i][k]*dp[di-1][k][j];
                    dp[di][i][j]%=m;
                }
            }
        }
    }
    /*
    for(int di=0;di<20;di++){
        printf("%10d:\n",di);
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                printf("%5d",dp[di][i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }*/
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    while(EOF!=scanf("%d%d",&k,&m)){
        for(int i=0;i<10;i++){
            scanf("%d",a+i);
        }
        Create();
        int tmpk=k/10;
        int fac[40];
        fac[1]=1;
        for(int i=2;i<40;i++){
             fac[i]=2*fac[i-1];
        }
        int trans[2][10][10];
        memset(trans,0,sizeof(trans));
        for(int i=0;i<10;i++){
            trans[0][i][i]=1;
        }
        int ti=1;
        for(int di=31;di>=1;di--){
            if(tmpk>=fac[di]){
                tmpk-=fac[di];
                for(int i=0;i<10;i++){
                    for(int j=0;j<10;j++){
                        trans[ti][i][j]=0;
                        for(int k=0;k<10;k++){
                             trans[ti][i][j]
                                 +=trans[1-ti][i][k]*dp[di][k][j];
                             trans[ti][i][j]%=m;
                        }
                    }
                }
                ti=1-ti;
            }
        }
        int ans=0;
        int pi=k%10;
        for(int i=0;i<10;i++){
            ans+=i*trans[1-ti][pi][i];
            ans%=m;
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
