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
const int MAXL=19;
int dp[MAXN][MAXL];
int fac[MAXL];
int n,k;

void Init(){
    fac[0]=1;
    for(int i=1;i<MAXL;i++){
        fac[i]=2*fac[i-1];
    }
}

void RMQ(int n){
    for(int j=1;j<MAXL;j++){
        int kk=fac[j]-1;
        for(int i=1;i<=n;i++){
            if(i+kk>n){
                break;
            }
            dp[i][j]=max(dp[i][j-1],dp[i+fac[j-1]][j-1]);
        }
    }
}

bool Check(int m){
    int d=n/m;
    int tmpd=n/m;
    int kk=0;
    while(tmpd/2){
        tmpd/=2;
        kk++;
    }
    int sum=0;
    for(int i=1;i<=m;i++)
    {
         int l=(i-1)*d+1;
         int r=i*d;
         int tmp=max(dp[l][kk],dp[r-fac[kk]+1][kk]);
         sum+=tmp;
    }
    return sum>k;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    Init();
    while(cin>>n>>k,n>=0||k>=0){
        int maxval=-1;
        int tmpsum=0;
        for(int i=1;i<=n;i++){
            cin>>dp[i][0];
            if(dp[i][0]>maxval)maxval=dp[i][0];
            tmpsum+=dp[i][0];
        }
        if(k>=tmpsum){
            cout<<"-1\n";
            continue;
        }
        RMQ(n);
        int minm=1;
        int maxm=n;
        while(minm<maxm){
            int mid=(minm+maxm)/2;
            if(Check(mid))maxm=mid;
            else minm=mid+1;
        }
        cout<<maxm<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
