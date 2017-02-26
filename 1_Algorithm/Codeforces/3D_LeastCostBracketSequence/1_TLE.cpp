#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;

int dp[2][MAXN],N;
int path[MAXN];
char str[MAXN];
int a,b;
map<int,int> mp[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%s",str);
    int len=strlen(str);
    int si=0,ti=1;
    memset(dp,0x3f,sizeof(dp));
    memset(path,-1,sizeof(path));
    dp[ti][0]=0;
    int cnt=0;
    for(int i=0;str[i];i++){
        swap(si,ti);
        memset(dp[ti],0x3f,sizeof(dp[ti]));
        int jmax=len-i+5;
        if(str[i]=='('){
            for(int j=0;j<jmax;j++){
                dp[ti][j+1]=dp[si][j];
            }
            continue;
        }else if(str[i]==')'){
            for(int j=1;j<jmax;j++){
                dp[ti][j-1]=dp[si][j];
            }
            continue;
        }
        scanf("%d%d",&a,&b);
        dp[ti][0]=min(dp[ti][0],dp[si][1]+b);
        for(int j=1;j<jmax;j++){
            if(dp[si][j]+b<dp[ti][j-1]){
                 dp[ti][j-1]=dp[si][j]+b;
            }
            if(dp[si][j-1]+a<dp[ti][j]){
                 dp[ti][j]=dp[si][j-1]+a;
            }
        }
    }
    printf("%d\n",dp[ti][0]);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
