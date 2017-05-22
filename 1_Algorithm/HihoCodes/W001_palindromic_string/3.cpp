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
const int MAXN=1005;
const int MAXM=1e6+10;

char in[MAXM],str[2*MAXM];
int dp[2*MAXM];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    while(N--){
         cin>>in;
         memset(str,'$',sizeof(str));
         int i,j;
         for(i=0,j=1;in[i];i++,j+=2){
              str[j]=in[i];
         }
         str[j]=0;
         int slen=j;
         memset(dp,0,sizeof(dp));
         int ans=0;
         int keyj=0;
         for(int si=1;si<slen;si++){
             if(si<=keyj+dp[keyj])
                 dp[si]=min(dp[2*keyj-si],dp[keyj]+keyj-si);
             dp[si]=max(dp[si],0);
             int l,r;
             for(l=si-dp[si],r=si+dp[si];l>=0&&r<slen&&str[l]==str[r];l--,r++){

             }
             dp[si]=r-si-1;
             ans=max(ans,dp[si]);
             if(keyj+dp[keyj]<si+dp[si]){
                  keyj=si;
             }
         }
         cout<<ans<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
