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

const int MAXN=2e5+10;
const int MAXK=1e9+10;
const int MAXL=18;
int fac[MAXL];
int dp[MAXN][MAXL];
int tmp[MAXN];

void Init(){
     fac[0]=1;
     for(int i=1;i<MAXL;i++){
         fac[i]=2*fac[i-1];
     }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int n,k;
    cin.sync_with_stdio(false);
    Init();
    while(cin>>n>>k,n>=0||k>=0){
        if(n<=0||k<=0)continue;
        int maxval=-1;
        for(int i=1;i<=n;i++) {
            cin>>dp[i][0];
            if(dp[i][0]>maxval)maxval=dp[i][0];
        }
        int ans=k/maxval;
        if(!ans)ans=1;
        if(n<ans){
             cout<<"-1"<<endl;
             continue;
        }
        for(int j=1;j<MAXL;j++){
            int tmp=fac[j-1]-1;
            for(int i=1;i<=n;i++){
                if(i+tmp>n)break;
                dp[i][j]=max(dp[i][j-1],dp[i+fac[j-1]][j-1]);
            }
        }
        for(;ans<=n;ans++){
            int sum=0;

            int len=n/ans;
            int d=len;
            int kk=0;
            while(d/2){
                d/=2;
                kk++;
            }
            for(int i=1;i<=ans;i++){
                int l=(i-1)*len+1;
                int r=i*len;
                int tmp=max(dp[l][kk],dp[r-fac[kk]+1][kk]);
                sum+=tmp;
            }
            if(sum>k)break;
        }
        if(ans>n)ans=-1;
        cout<<ans<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
