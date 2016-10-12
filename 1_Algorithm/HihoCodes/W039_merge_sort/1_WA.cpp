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
const int MAXN=1e5+10;

int dp[2][MAXN];
int dpi;
int N;
int ans;

void DFS(int l,int r,int si){
    if(l==r)return;
    int mid=(l+r)/2;
    int di=1-si;
    DFS(1,mid,di);
    DFS(mid+1,r,di);
    int i=l,j=mid+1;
    int pt=l;
    while((j<=r)&&(i<=mid)){
        if(dp[si][j]>dp[si][i]){
            dp[di][pt]=dp[si][i];
            pt++;i++;
        }else{
            dp[di][pt]=dp[si][j];
            //ans+=i-l+1;
            ans+=mid-i+1;
            pt++;j++;
        }
    }
    while(j<=r){
        dp[di][pt++]=dp[si][j++];
    }
    while(i<=mid){
        dp[di][pt++]=dp[si][i++];
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    dpi=0;
    for(int i=1;i<=N;i++){
         cin>>dp[dpi][i];
    }
    ans=0;
    DFS(1,N,dpi);
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
