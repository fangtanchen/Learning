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
#define lson (rt<<1)
#define rson ((rt<<1)|1)
#define parent (rt>>1)
typedef long long LL;

const int MAXS=20;
const int MAXN=1e5+10;


struct Node{
    int l,r;
    LL d;
    Node(LL a=0,int b=0,int c=0)
        :d(a),l(b),r(c)
    {

    }

    inline bool operator<(const Node x) const {
        return d<x.d;
    }
};

//adjacent table
int first[MAXN],to[MAXN*2],adj[MAXN*2],val[MAXN*2],top;
//edge records
int u[MAXN],v[MAXN],w[MAXN];
LL ds[MAXN];
int d[MAXN];//distance or depth from i to root
//dfs seq
int seq[MAXN],l[MAXN],r[MAXN],seq_cnt;
int anc[MAXN][MAXS];

//segment tree
Node tree[MAXN*2];

int N,Q,K;
LL ans;

void Init(){
     top=0;
     seq_cnt=0;
     memset(first,-1,sizeof(first));
     memset(to,-1,sizeof(to));
     memset(adj,-1,sizeof(adj));
     memset(val,0,sizeof(val));
     memset(d,0,sizeof(d));
     memset(ds,0,sizeof(ds));
     memset(seq,0,sizeof(seq));
     memset(l,0,sizeof(l));
     memset(r,0,sizeof(r));
     memset(anc,0,sizeof(anc));
     ans=0;
}


void Add(int u,int v,int w){
    adj[top]=first[u];
    to[top]=v;
    val[top]=w;
    first[u]=top++;
}

void DFS(int u,int fa){
    seq_cnt++;
    seq[seq_cnt]=u;
    l[u]=seq_cnt;
    d[u]=d[fa]+1;
    anc[u][0]=fa;

    for(int i=1;i<MAXS;i++){
        anc[u][i]=anc[anc[u][i-1]][i-1];
    }

    for(int pos=first[u];pos!=-1;pos=adj[pos]){
         int v=to[pos];
         if(v==fa)continue;
         ds[v]=ds[u]+val[pos];
         DFS(v,u);
    }

    r[u]=seq_cnt;
}


LL Distance(int u,int v){
    LL res=ds[u]+ds[v];
    if(d[u]<d[v])swap(u,v);
    int diff=d[u]-d[v];
    for(int i=0;i<MAXS;i++){
        if((1<<i)&diff){
            u=anc[u][i];
        }
    }
    if(u==v)return res-2*ds[u];
    for(int i=MAXS-1;i>=0;i--){
        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    u=dp[u][0];
    return res-2*ds[u];
}

Node AddSet(Node a, Node b){
    if(a.d==-1)return b;
    if(b.d==-1)return a;
    Node c=Node(Distance(a.l,b.l),a.l,b.l);
    Node d=Node(Distance(a.l,b.r),a.l,b.r);
    Node e=Node(Distance(a.r,b.l),b.r,b.l);
    Node f=Node(Distance(a.r,b.r),a.r,b.r);
    return max(a,max(b,max(c,max(d,max(e,f)))));
}

void Build(int rt,int l,int r){
    if(l==r) {
        tree[rt]=Node(0,seq[l],seq[l]);
        return;
    }
    int mid=(l+r)>>1;
    Build(lson,l,mid);
    Build(rson,mid+1,r);
    tree[rt]=AddSet(tree[lson],tree[rson]);
    return;
}

Node query(int rt,int l,int r,int tl,int tr){
     if(tr<tl)return Node(-1,0,0);
     if((tl<=l)&&(r<=tr)){
         return tree[rt];
     }
     int mid=(l+r)>>1;
     if(tr<=mid){
         return query(lson,l,mid,tl,tr);
     }else if(tl>mid){
         return query(rson,mid+1,r,tl,tr);
     }else{
         return AddSet(query(lson,l,mid,tl,tr)
                 ,query(rson,mid+1,r,tl,tr));
     }
}

void DFS(int u){
     Node res=Node(-1,x[u],x[u]);
     int tl=l[x[u]],tr=r[x[u]];
     for(int pos=first[u];pos!=-1;pos=adj[pos]){
         int v=to[pos];
         DFS(v);
         res=AddSet(res,query(1,1,N,tl,l[x[v]]-1));
         tl=r[x[v]]+1;
     }
     res=AddSet(res,query(1,1,N,tl,tr));
     ans+=res.d;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d",&N);
    for(int i=1;i<N;i++){
        scanf("%d%d%d",u+i,v+i,w+i);
        Add(u[i],v[i],w[i]);
        Add(v[i],u[i],w[i]);
    }
    DFS(1,0);
    Build(1,1,N);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
