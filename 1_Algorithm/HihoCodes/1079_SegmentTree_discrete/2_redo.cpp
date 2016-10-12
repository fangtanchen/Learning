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
const int MAXL=1e9+10;
#define lson (id<<1)
#define rson ((id<<1)|1)

struct Node{
    int l,r;
    int lazy;
    bool bleaf;
    Node(){
         l=r=lazy=0;
         bleaf=false;
    }
}tree[4*MAXN];

int A[MAXN*2];
int B[MAXN*2];
map<int,int> C;
int ans[MAXN];
int N,M;


void Build(int l,int r,int id){
    tree[id].l=l;tree[id].r=r;
    if(r-l==1){
        tree[id].bleaf=true;
        return;
    }
    int mid=(l+r)/2;
    Build(l,mid,lson);
    Build(mid,r,rson);
}

void Send(int id){
    if(tree[id].lazy==0)return;
    tree[lson].lazy=tree[id].lazy;
    tree[rson].lazy=tree[id].lazy;
    tree[id].lazy=0;
    return;
}

void Mark(int l,int r,int flag,int id){
    if(((tree[id].l==l) && (tree[id].r==r))
    ||(tree[id].bleaf)){
        tree[id].lazy=flag;
        return;
    }
    Send(id);
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid){
        Mark(l,r,flag,lson);
    }else if(l>=mid){
        Mark(l,r,flag,rson);
    }else{
        Mark(l,mid,flag,lson);
        Mark(mid,r,flag,rson);
    }
}

void PostOrder(int id){
    if(tree[id].lazy){
        ans[tree[id].lazy]=1;
        return;
    }
    if(tree[id].bleaf) return;
    PostOrder(lson);
    PostOrder(rson);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    int imax=2*N-1;
    int numA=0;
    for(int i=1;i<=N;i++){
        cin>>A[numA]>>A[numA+1];
        B[numA]=A[numA];
        numA++;
        B[numA]=A[numA];
        numA++;
    }
    int numB=numA;
    sort(B,B+numB);
    int numC=0;
    for(int i=0;i<numB;i++){
         map<int,int>::iterator it=C.find(B[i]);
         if(it==C.end()){
             C[B[i]]=numC++;
         }
    }
    numC--;
    Build(0,numC,1);
    for(int i=1,j=0;i<=N;i++,j+=2){
         int l=C[A[j]],r=C[A[j+1]];
         Mark(l,r,i,1);
    }
    memset(ans,0,sizeof(ans));
    PostOrder(1);
    int tt=0;
    for(int i=1;i<=N;i++){
        tt+=ans[i];
    }
    cout<<tt<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
