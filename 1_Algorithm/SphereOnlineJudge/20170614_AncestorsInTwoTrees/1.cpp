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
const int MAXT=10010;
const int MAXN=5e5+5;
#define lson ((rt)<<1)
#define rson (((rt)<<1)|1)

vector<int> G[2*MAXN];
vector<int> L[4*MAXN],R[MAXN*4];

int T,N;
int dfs[2*MAXN],Left[2*MAXN],Right[2*MAXN],cnt;

void Init(){
    memset(dfs,0,sizeof(dfs));
    memset(Left,0,sizeof(Left));
    memset(Right,0,sizeof(Right));
    for(int i=2*MAXN-1;i>=0;i--){
        G[i].clear();
    }
    for(int i=4*MAXN-1;i>=0;i--){
        L[i].clear();
        R[i].clear();
    }
}

inline void DFS(int u){
    dfs[u]=Left[u]=++cnt;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!dfs[v]){
            DFS(v);
        }

    }
    Right[u]=cnt;
}

inline void Insert(int rt,int l,int r, int left,int right,int down,int up){
    if(l==left && r==right){
        L[rt].push_back(down);
        R[rt].push_back(up);
        return;
    }
    int mid=(l+r)/2;
    if(right<=mid){
         Insert(lson,l,mid,left,right,down,up);
    }else if(left>mid){
         Insert(rson,mid+1,r,left,right,down,up);
    }else{
         Insert(lson,l,mid,left,mid,down,up);
         Insert(rson,mid+1,r,mid+1,right,down,up);
    }
}

int Calc(int rt,int l,int r,int left,int down){
    int will=0;
    int ll=0,rr=L[rt].size()+1;
    while(ll+1<rr){
        int mid=(ll+rr)/2;
        if(L[rt][mid-1]<down)ll=mid;
        else rr=mid;
    }
    will=ll;
    ll=0,rr=R[rt].size()+1;
    while(ll+1<rr){
        int mid=(ll+rr)/2;
        if(R[rt][mid-1]<down)ll=mid;
        else rr=mid;
    }
    will-=ll;
    if(l==r)return will;
    int mid=(l+r)/2;
    if(left<=mid){
         return will+Calc(lson,l,mid,left,down);
    }else{
        return will+Calc(rson,mid+1,r,left,down);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>T;
    while(T--){
        Init();
         cin>>N;
         for(int i=1;i<N;i++){
             int u,v;
             cin>>u>>v;
             G[u].push_back(v);
             G[v].push_back(u);
         }
         for(int i=1;i<N;i++){
              int u,v;
              cin>>u>>v;
              G[u+N].push_back(v+N);
              G[v+N].push_back(u+N);
         }
         cnt=0;
         memset(dfs,0,sizeof(dfs));
         DFS(1);
         DFS(1+N);
         for(int i=1;i<=N;i++){
              Insert(1,1,N,Left[i],Right[i],Left[i+N],Right[i+N]);
         }
         for(int i=4*N;i>=1;i--){
              sort(L[i].begin(),L[i].end());
              sort(R[i].begin(),R[i].end());
         }
         for(int i=1;i<=N;i++){
             cout<<Calc(1,1,N,dfs[i],dfs[i+N]);
             if(i<N)cout<<" ";
             else cout<<endl;
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
