#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;
typedef long long LL;

LL n;
LL a[MAXN];
vector<int> G[MAXN];
LL cnt[MAXN],mx[MAXN];

LL gcd(LL x,LL y){
    if(y==0)return x;
    else return gcd(y,x%y);
}

LL lcm(LL x,LL y){
    return x/gcd(x,y)*y;
}

void dfs(int u,int fa){
    int nchild=0;
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        if(v==fa)continue;
        dfs(v,u);
        // record the result of the child nodes
        if(nchild==0){
            mx[u]=mx[v];
            cnt[u]=cnt[v];
        }else{
            if(cnt[u]<1e14)cnt[u]=lcm(cnt[u],cnt[v]);
            mx[u]=min(mx[u],mx[v])/cnt[u]*cnt[u];
        }
        nchild++;
    }
    // update the node u
    if(nchild==0)mx[u]=a[u],cnt[u]=1;
    else{
        mx[u]=nchild*mx[u];
        if(cnt[u]<1e14)cnt[u]=nchild*cnt[u];
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>n;
    LL ans=0;
    for(int i=1;i<=n;i++){
         cin>>a[i];
         ans+=a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans-mx[1]<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
