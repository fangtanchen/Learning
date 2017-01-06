#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<string>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e6+10;
const int MAXS=26;

typedef long long int ll;

string dict[MAXN];
int trie[MAXN][MAXS];
int dp[MAXN];
int tcnt,N;

void Insert(string str){
    int now=0;
    int len=str.length();
    for(int si=len-1;si>=0;si--){
        int d=str[si]-'a';
        if(trie[now][d]==-1){
            trie[now][d]=++tcnt;
        }
        now=trie[now][d];
        dp[now]++;
    }
}


ll Calculate(string str){
     int now=0;
     int len=str.length();
     ll ret=0;
     for(int si=len-1;si>=0;si--){
         int d=str[si]-'a';
         for(int i=d+1;i<MAXS;i++){
              if(trie[now][i]!=-1)ret+=dp[trie[now][i]];
         }
         now=trie[now][d];
     }
     //longer than you
     for(int i=0;i<MAXS;i++){
         ret+=dp[trie[now][i]];
     }
     return ret;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int ni=0;ni<N;ni++){
        cin>>dict[ni];
    }
    sort(dict,dict+N);

    memset(trie,-1,sizeof(trie));
    memset(dp,0,sizeof(dp));
    tcnt=0;
    ll ans=0;
    for(int ni=0;ni<N;ni++){
        Insert(dict[ni]);
        ans+=Calculate(dict[ni]);
    }
    printf("%lld\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
