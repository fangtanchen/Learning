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
const int MOD=19999997;
int N;
long long dp[30][2][2];
int k[30];

void Init(){
    memset(dp,0,sizeof(dp));

    dp[0][0][0]=0;
    dp[0][0][1]=1;
    dp[0][1][0]=1;
    dp[0][1][1]=1;

    for(int di=0;di<29;di++){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    dp[di+1][i][j]+=dp[di][i][k]*dp[di][k][j];
                    dp[di+1][i][j]%=MOD;
                }
            }
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    Init();
    long long L[2][2]={{1,1},{0,0}};
    int klen=0;
    int tmpN=N-1;
    while(tmpN){
         k[klen]=tmpN%2;
         tmpN/=2;
         klen++;
    }

    int si=0,di=1;
    for(int ki=0;ki<klen;ki++){
        if(k[ki]==0)continue;
        for(int j=0;j<2;j++){
            L[di][j]=0;
            for(int k=0;k<2;k++){
                L[di][j]+=L[si][k]*dp[ki][k][j];
                L[di][j]%=MOD;
            }
        }
        si=1-si;
        di=1-di;
    }
    cout<<L[si][1]<<endl;



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
