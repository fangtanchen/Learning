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

int N,T;
LL dp[21][11][11][4][4];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>T;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            dp[2][0][0][i][j]=(i!=j);
        }
    }
    for(int i=2;i<N;i++){
        for(int j=0;j<=T;j++){
            for(int k=0;k<T;k++){
                for(int r=0;r<4;r++){
                    for(int s=0;s<4;s++){
                        if(r==s)continue;
                        for(int t=0;t<4;t++){
                            if(t==s)continue;
                            if((r<s)&&(s>t)){
                                 dp[i+1][j+1][k][s][t]+=dp[i][j][k][r][s];
                            }
                            else if((r>s)&&(s<t)){
                                dp[i+1][j][k+1][s][t]+=dp[i][j][k][r][s];
                            }else
                            dp[i+1][j][k][s][t]+=dp[i][j][k][r][s];
                        }
                    }
                }
            }
        }
    }
    LL ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            ans+=dp[N][T][T-1][i][j];
        }
    }
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
