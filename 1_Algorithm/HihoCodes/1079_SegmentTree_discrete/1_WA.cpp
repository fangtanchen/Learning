#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;
const int MAXL=1e9+10;
#define lson (id<<1)
#define rson ((id<<1)+1)

struct Node{
    int l,r;
    int lazy;
}tree[4*MAXN];


int a[2*MAXN];
int b[2*MAXN];
map<int,int> c;
int ci=1;
int numnodes;
int N,M;
int posters[MAXN];

void Build(int l,int r,int id){
    numnodes++;
    tree[id].l=l;
    tree[id].r=r;
    if(1==r-l)return;
    int mid=(l+r)/2;
    Build(l,mid,lson);
    Build(mid,r,rson);
}

void Send(int id){
    if(tree[id].lazy==0)return;
    if(lson<numnodes){
        tree[lson].lazy=tree[id].lazy;
    }
    if(rson<numnodes){
        tree[rson].lazy=tree[id].lazy;
    }
    tree[id].lazy=0;
}

void Mark(int l,int r,int lazy,int id){
    if(tree[id].l==l &&(r==tree[id].r)){
        tree[id].lazy=lazy;
        return;
    }
    Send(id);
    int mid=(tree[id].l+tree[id].r)/2;
    if((mid>=r))Mark(l,r,lazy,lson);
    else if(mid<=l)Mark(l,r,lazy,rson);
    else{
        Mark(l,mid,lazy,lson);
        Mark(mid,r,lazy,rson);
    }
}

void PostOrder(int id){
    if(tree[id].lazy){
        posters[tree[id].lazy]=1;
        return;
    }
    if(lson<numnodes)PostOrder(lson);
    if(rson<numnodes)PostOrder(rson);
}




int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    int imax=2*N;
    for(int i=1;i<=imax;i+=2){
         cin>>a[i]>>a[i+1];
         b[i]=a[i];b[i+1]=a[i+1];
    }
    sort(b+1,b+imax+1);
    ci=1;
    map<int,int>::iterator it;
    for(int i=1;i<=imax;i++){
        if(c.find(b[i])==c.end()){
             c[b[i]]=ci++;
        }
    }
    numnodes=1;
    Build(1,ci-1,1);
    for(int i=1,flag=1;i<=imax;i+=2,flag++){
        int l=c[a[i]],r=c[a[i+1]];
        Mark(l,r,flag,1);
    }
    memset(posters,0,sizeof(posters));
    PostOrder(1);
    int ans=0;
    for(int i=1;i<=N;i++){
         ans+=posters[i];
    }
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
