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
const int MAXN=4e5+10;
const int MODU=10007;
#define lson ((rt)<<1)
#define rson ((rt<<1)|1)

struct Node{
    int sum1,sum2,sum3;
    int set,mul,add;
    Node(){
         sum1=sum2=sum3=0;
         set=-1;
         mul=1;
         add=0;
    }
};

Node tree[MAXN];

void Build(int rt,int l,int r){
    tree[rt]=Node();
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    Build(lson,l,mid);
    Build(rson,mid+1,r);
}

void Set(int rt,int l,int r,int v){
    if(v==-1)return;
    int L=(r-l+1)%MODU;
    tree[rt].sum1=L*v%MODU;
    tree[rt].sum2=L*v%MODU*v%MODU;
    tree[rt].sum3=L*v%MODU*v%MODU*v%MODU;
    tree[rt].set=v;
    tree[rt].add=0;
    tree[rt].mul=1;
}

void Mul(int rt,int l,int r,int v){
    if(v==1)return;
    tree[rt].sum1=(tree[rt].sum1*v)%MODU;
    tree[rt].sum2=(tree[rt].sum2*v)%MODU*v%MODU;
    tree[rt].sum3=(tree[rt].sum3*v)%MODU*v%MODU*v%MODU;
    tree[rt].mul=(tree[rt].mul*v)%MODU;
    tree[rt].add=(tree[rt].add*v)%MODU;
}

void Add(int rt,int l,int r,int v){
    if(v==0)return;
    int L=(r-l+1)%MODU;
    tree[rt].sum3=(tree[rt].sum3+
            3*v%MODU*tree[rt].sum2%MODU+
            3*tree[rt].sum1%MODU*v%MODU*v%MODU
            +L*v%MODU*v%MODU*v%MODU)%MODU;
    tree[rt].sum2=(tree[rt].sum2+2*v%MODU*tree[rt].sum1%MODU+L*v%MODU*v%MODU)%MODU;
    tree[rt].sum1=(tree[rt].sum1+L*v)%MODU;
    tree[rt].add=(tree[rt].add+v)%MODU;
}

void PushDown(int rt,int l,int r){
    // baseline: the leaf node
    if(l==r)return;
    // other internal node
    int mid=(l+r)/2;
    if(tree[rt].set!=-1){
        Set(lson,l,mid,tree[rt].set);
        Set(rson,mid+1,r,tree[rt].set);
        tree[rt].set=-1;
    }
    if(tree[rt].mul!=1){
        Mul(lson,l,mid,tree[rt].mul);
        Mul(rson,mid+1,r,tree[rt].mul);
        tree[rt].mul=1;
    }
    if(tree[rt].add!=0){
         Add(lson,l,mid,tree[rt].add);
         Add(rson,mid+1,r,tree[rt].add);
         tree[rt].add=0;
    }
}

void PushUp(int rt){
    tree[rt].sum1=(tree[lson].sum1+tree[rson].sum1)%MODU;
    tree[rt].sum2=(tree[lson].sum2+tree[rson].sum2)%MODU;
    tree[rt].sum3=(tree[lson].sum3+tree[rson].sum3)%MODU;
}

void Add(int rt,int l,int r,int a,int b,int v){
    if(a<=l&&r<=b){
        PushDown(rt,l,r);
        Add(rt,l,r,v);
    }else{
        PushDown(rt,l,r);
        int mid=(l+r)/2;
        if(b<=mid){
             Add(lson,l,mid,a,b,v);
        }else if(a>mid){
            Add(rson,mid+1,r,a,b,v);
        }else{
            Add(lson,l,mid,a,b,v);
            Add(rson,mid+1,r,a,b,v);
        }
        PushUp(rt);
    }
}

void Mul(int rt,int l,int r,int a,int b,int v){
    if((a<=l)&&(r<=b)){
        PushDown(rt,l,r);
        Mul(rt,l,r,v);
    }else{
        PushDown(rt,l,r);
        int mid=(l+r)/2;
        if(b<=mid){
             Mul(lson,l,mid,a,b,v);
        }else if(a>mid){
            Mul(rson,mid+1,r,a,b,v);
        }else{
             Mul(lson,l,mid,a,b,v);
            Mul(rson,mid+1,r,a,b,v);
        }
        PushUp(rt);
    }
}

void Set(int rt,int l,int r,int a,int b,int v){
    if(a<=l&&r<=b){
        PushDown(rt,l,r);
        Set(rt,l,r,v);
    }else{
        PushDown(rt,l,r);
        int mid=(l+r)/2;
        if(b<=mid){
            Set(lson,l,mid,a,b,v);
        }else if(a>mid){
             Set(rson,mid+1,r,a,b,v);
        }else{
            Set(lson,l,mid,a,b,v);
            Set(rson,mid+1,r,a,b,v);
        }
        PushUp(rt);
    }
}

int Query(int rt,int l,int r,int a,int b,int v){
    if(a<=l&&r<=b){
        if(v==1)return tree[rt].sum1;
        if(v==2)return tree[rt].sum2;
        if(v==3)return tree[rt].sum3;
    }else{
        PushDown(rt,l,r);
        int mid=(l+r)/2;
        int ans=0;
        if(b<=mid){
             ans+=Query(lson,l,mid,a,b,v);
             ans%=MODU;
        }else if(a>mid){
            ans+=Query(rson,mid+1,r,a,b,v);
            ans%=MODU;
        }else{
            ans+=Query(lson,l,mid,a,b,v);
            ans%=MODU;
            ans+=Query(rson,mid+1,r,a,b,v);
            ans%=MODU;
        }
        PushUp(rt);
        return ans;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int N,M;
    while(scanf("%d%d",&N,&M),N||M){
         Build(1,1,N);
         for(int i=0;i<M;i++){
             int op,a,b,c;
             scanf("%d%d%d%d",&op,&a,&b,&c);
             if(1==op){
                  Add(1,1,N,a,b,c);
             }else if(2==op){
                 Mul(1,1,N,a,b,c);
             }else if(3==op){
                 Set(1,1,N,a,b,c);
             }else if(4==op){
                  printf("%d\n",Query(1,1,N,a,b,c));
             }
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
