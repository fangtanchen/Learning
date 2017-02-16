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
typedef long long int LL;
const int MAXN=1e5+10;
const int MAXM=4e5+10;
#define lson (id<<1)
#define rson ((id<<1)|1)

struct Node{
    int l,r;
    LL v;
    Node(int a=0,int b=0,LL c=0){
         l=a;r=b;v=c;
    }
}tree[MAXM];

int n,rt;
LL a[MAXN];


LL Gcd(LL x,LL y){
    if(y==0)return x;
    else return Gcd(y,x%y);
}

void Build(int id,int l,int r){
    tree[id].l=l;
    tree[id].r=r;
    if(l==r){
        tree[id].v=a[l];
        return;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    Build(lson,l,mid);
    Build(rson,mid+1,r);
    tree[id].v=Gcd(tree[lson].v,tree[rson].v);
}

LL Query(int id,int l,int r){
    if(l>r)return -1;
    if(l==tree[id].l && tree[id].r==r)return tree[id].v;
    int mid=(tree[id].l+tree[id].r)/2;
    if(l>mid)return Query(rson,l,r);
    else if(r<=mid)return Query(lson,l,r);
    return Gcd(Query(lson,l,mid),Query(rson,mid+1,r));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
         scanf("%lld",a+i);
    }
    if(n==1)return 0*printf("%lld\n",a[1]+1);
    Build(1,1,n);

    LL ans;

    for(int i=1;i<=n;i++){
        int l1=1,r1=i-1;
        int l2=i+1,r2=n;
        LL a1=Query(1,l1,r1);
        LL a2=Query(1,l2,r2);
        if(a1==-1){
             ans=a2;
        }else{
            if(a2==-1)ans=a1;
            else ans=Gcd(a1,a2);
        }
        if(a[i]%ans)break;
    }
    printf("%lld\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
