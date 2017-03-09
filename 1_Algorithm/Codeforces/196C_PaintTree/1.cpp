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
typedef pair<long long int,long long int> pii;
const int MAXN=2005;

pii pt[MAXN],lowpt;
int id[MAXN];
int ans[MAXN];
int child[MAXN];
int keypp;
vector<int> P[MAXN],G[MAXN];

bool Cmp1(int x,int y){
    return pt[x]<pt[y];
}

bool Cmp2(int x,int y){
    return (pt[x].first-pt[keypp].first)*(pt[y].second-pt[keypp].second)
        -(pt[x].second-pt[keypp].second)*(pt[y].first-pt[keypp].first)>0;
}


void DFS(int rt,int l,int r){
    if(l==r){
        ans[id[l]]=rt;
        return;
    }
    sort(id+l,id+r+1,Cmp1);
    ans[id[l]]=rt;
    keypp=id[l];
    sort(id+l+1,id+r+1,Cmp2);
    int k=l;
    for(int i=0;i<G[rt].size();i++){
         int u=G[rt][i];
         DFS(u,k+1,k+child[u]);
         k=k+child[u];
    }
}

void BFS(int rt){
    child[rt]=1;
    for(int i=0;i<P[rt].size();i++){
        if(child[P[rt][i]]!=0)continue;
        BFS(P[rt][i]);
        child[rt]+=child[P[rt][i]];
        G[rt].push_back(P[rt][i]);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
         int u,v;
         cin>>u>>v;
         P[u].push_back(v);
         P[v].push_back(u);
    }
    int root=1;
    memset(child,0,sizeof(child));
    BFS(root);

    lowpt.second=1e9+10;
    int mini=1;
    for(int i=1;i<=n;i++){
        cin>>pt[i].second>>pt[i].first;
         id[i]=i;
    }
    DFS(root,1,n);
    for(int i=1;i<=n;i++){
         cout<<ans[i]<<" ";
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
