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
const int MAXF=26;
const int MAXN=1e6+10;
const int MODN=1e9+7;

int fac[28];
int a[MAXN];
int dp[2][MAXN];
int n;
int sum[28];

void Init(){
    fac[1]=fac[2]=1;
    for(int i=3;i<MAXF;i++){
        fac[i]=fac[i-1]+fac[i-2];
        //cout<<i<<": "<<fac[i]<<endl;
    }
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
         cin>>a[i];
         dp[0][i]=dp[0][i-1]+(a[i]==1);
    }
    int total=dp[0][n]%MODN;
    sum[1]=dp[0][n];
    int si=0,di=1;
    for(int fi=2;fi<MAXF;fi++){
        dp[di][0]=0;
        bool flag=false;
        for(int i=1;i<=n;i++){
            dp[di][i]=dp[di][i-1];
            if(a[i]==fac[fi]){
                flag=true;
                dp[di][i]=(dp[di][i]+dp[si][i-1])%MODN;
            }
        }
        if(!flag)break;
        sum[fi]=dp[di][n];
        total=(total+sum[fi])%MODN;
        si=1-si;
        di=1-di;
    }
    cout<<total<<endl;




	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
