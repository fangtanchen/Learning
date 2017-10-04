#include<iostream>
#include<cstring>

using namespace std;
const int MAXN=110;

char str[MAXN];
int dp[MAXN][MAXN];

int main(){
    cin>>str;
    int slen=strlen(str);
    int ans=0;
    for(int mid=0;mid<slen-1;mid++){
        char a[MAXN];
        char b[MAXN];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<=mid;i++){
            a[i+1]=str[i];
        }
        for(int i=1,j=mid+1;j<slen;i++,j++){
            b[i]=str[j];
        }
        int alen=mid+1;
        int blen=slen-mid-1;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=alen;i++){
            for(int j=1;j<=blen;j++){
                if(a[i]==b[j]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        ans=max(ans,dp[alen][blen]);
    }
    cout<<2*ans<<endl;

    return 0;
}
