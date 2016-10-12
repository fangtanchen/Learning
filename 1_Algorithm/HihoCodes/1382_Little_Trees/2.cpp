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
const int MAXS=20;
const int MAXN=1e5+10;
typedef long long LL;

#define ls (rt<<1)
#define rs ((rt<<1)|1)
#define lson ls,l,mid
#define rson rs,(mid+1),r

struct Node{
    int l,r;
    LL d;
    Node(LL a=0,int b=0,int c=0)
        :d(a),l(b),r(c)
    {

    }
    inline bool operator<(const Node &x)const {
        return d<x.d;
    }
};

//adjcent table
int first[MAXN],adj[MAXN*4],to[MAXN*4],weight[MAXN*4],top;
int u[MAXN],v[MAXN],w[MAXN];//edges
int l[MAXN],r[MAXN],seq[MAXN],seq_cnt;
LL ds[MAXN];
int d[MAXN],anc[MAXN][MAXS];
int N,Q,K;
Node tree[MAXN*4];
int x[MAXN],st[MAXN],nn;
LL ans;


void Init(){
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(to,-1,sizeof(to));
    memset(weight,0,sizeof(weight));
    top=0;
    memset(seq,0,sizeof(seq));
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    seq_cnt=0;
    memset(ds,0,sizeof(ds));
    memset(d,0,sizeof(d));
    memset(anc,0,sizeof(anc));
    memset(tree,0,sizeof(tree));
}

void AddEdge(int u,int v,int w){
   adj[top]=first[u];
   to[top]=v;
   weight[top]=w;
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
         ds[v]=ds[u]+weight[pos];
         DFS(v,u);
     }

     r[u]=seq_cnt;
}

LL dis(int u,int v){
    LL ret=ds[u]+ds[v];
    if(d[u]<d[v])swap(u,v);
    int diff=d[u]-d[v];
    for(int i=0;i<MAXS;i++){
        if(diff&(1<<i)){
            u=anc[u][i];
        }
    }
    if(u==v)return ret-2*ds[u];
    for(int i=MAXS-1;i>=0;i--){
        if(anc[u][i]!=anc[v][i]){
            u=anc[u][i];
            v=anc[v][i];
        }
    }
    u=anc[u][0];
    return ret-2*ds[u];
}

Node AddSet(Node a,Node b){
     if(b.d==-1)return a;
     if(a.d==-1)return b;
     Node c=Node(dis(a.l,b.l),a.l,b.l);
     Node d=Node(dis(a.l,b.r),a.l,b.r);
     Node e=Node(dis(a.r,b.l),a.r,b.l);
     Node f=Node(dis(a.r,b.r),a.r,b.r);
     return max(a,max(b,max(c,max(d,max(e,f)))));
}

void Build(int rt,int l,int r){
    if(l==r) {
         tree[rt]=Node(0,seq[l],seq[l]);
         return;
    }
    int mid=(l+r)>>1;
    Build(lson);
    Build(rson);
    tree[rt]=AddSet(tree[ls],tree[rs]);
    return;
}

Node Query(int rt,int l,int r,int tl,int tr){
     if(tr<tl)return Node(-1,0,0);
     if((tl<=l)&&(tr>=r)){
         return tree[rt];
     }
     int mid=(l+r)>>1;
     if(tr<=mid){
          return Query(lson,tl,tr);
     }else if(mid<tl){
         return Query(rson,tl,tr);
     }else{
         return AddSet(Query(lson,tl,mid),Query(rson,mid+1,tr));
     }
}

bool cmp(int a,int b){
    return l[a]<l[b];
}

void DFS(int u){
    Node res=Node(-1,x[u],x[u]);
    int tl=l[x[u]],tr=r[x[u]];
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos] ;
        DFS(v);
        res=AddSet(res,Query(1,1,N,r[x[v]]+1,tr));
        tr=l[x[v]]-1;
    }
    res=AddSet(res,Query(1,1,N,tl,tr));
    ans+=res.d;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d",&N);
    for(int i=1;i<N;i++){
        scanf("%d%d%d",u+i,v+i,w+i);
        AddEdge(u[i],v[i],w[i]);
        AddEdge(v[i],u[i],w[i]);
    }
    DFS(1,0);
    Build(1,1,N);
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&K) ;
        int id;
        for(int ki=1;ki<=K;ki++){
             scanf("%d",&id);
             if(d[u[id]]>d[v[id]]){
                 x[ki]=u[id];
             }else{
                 x[ki]=v[id];
             }
        }
        memset(adj,-1,sizeof(adj));
        memset(first,-1,sizeof(first));
        memset(to,-1,sizeof(to));
        sort(x+1,x+1+K,cmp);
        x[0]=1;
        nn=1;
        st[nn]=0;
        for(int i=1;i<=K;i++){
             while(!((l[x[i]]>=l[x[st[nn]]])
                         &&(r[x[i]]<=r[x[st[nn]]]))){
                 nn--;
             }
             AddEdge(st[nn],i,0);
             st[++nn]=i;
        }
        ans=0;
        DFS(0);
        printf("%lld\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
