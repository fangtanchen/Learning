#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=3e6+10;

int l[MAXN],r[MAXN],x[MAXN],y[MAXN];
vector<int> v;
map<int,int> mp;
int N,Q,rk;
int cnt[MAXN],a[MAXN];
double logs[MAXN];
int dp[50][MAXN];

int lowbit(int x){
    return x&(-x);
}


void Add(int v,int k){
    int t=v;
    while(t<MAXN){
        a[t]+=k;
        t+=lowbit(t);
    }
}

int sum(int x){
    int ret=0;
    while(x!=0){
        ret+=a[x];
        x-=lowbit(x);
    }
    return ret;
}

void Init(int rk){
    for(int i=1;i<MAXN;i++){
         logs[i]=log2(i)+1e-6;
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=rk;i++){
        dp[0][i]=cnt[i];
    }
    int k=logs[rk];
    for(int i=1;i<=k;i++){
        for(int j=1;j<=rk;j++){
             if(j+(1<<(i-1))>rk)break;
             dp[i][j]=max(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
        }
    }
}

int rmq(int l,int r){
    if(r<l)return 0;
    int k=logs[r-l+1];
    return max(dp[k][l],dp[k][r-(1<<(k))+1]);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=0;i<N;i++){
         scanf("%d%d",l+i,r+i);
         v.push_back(l[i]);
         v.push_back(r[i]);
    }
    scanf("%d",&Q);
    for(int i=0;i<Q;i++){
         scanf("%d%d",x+i,y+i);
         v.push_back(x[i]);
         v.push_back(y[i]);
    }
    sort(v.begin(),v.end());
    rk=1;
    mp[v[0]]=rk;
    for(int i=1;i<v.size();i++){
        if(v[i]>v[i-1]){
            mp[v[i]]=++rk;
        }
    }
    memset(a,0,sizeof(a));
    for(int i=0;i<N;i++){
        Add(mp[l[i]],1);
        Add(mp[r[i]]+1,-1);
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=rk;i++){
         cnt[i]=sum(i);
    }
    Init(rk);
    for(int i=0;i<Q;i++){
         printf("%d\n",rmq(mp[x[i]],mp[y[i]]));
    }



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
