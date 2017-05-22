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

int N,M;
struct tree{
    struct node{
        int l,r;
        int sum1,sum2,sum3;
        int mul;
        int add;
        int set;
    }f[MAXN];
    int root;
    int cnt;

    int Build(int l,int r){
         int x=cnt++;
         f[x].sum1=f[x].sum2=f[x].sum3=f[x].add=0;
         f[x].set=-1;
         f[x].mul=1;
         if(l<r){
             int mid=(l+r)/2;
             f[x].l=Build(l,mid);
             f[x].r=Build(mid+1,r);
         }
         return x;
    }

    void Init(int l,int r){
        cnt=0;
        root=Build(l,r);
    }
    tree(){
         cnt=root=0;
    }

    void Add(int x,int l,int r,int c){
         if(!c)return;
         int L=(r-l+1)%MODU;
         f[x].sum3=(f[x].sum3+(3*f[x].sum2%MODU*c)%MODU
                 +(3*f[x].sum1%MODU*c%MODU*c%MODU)%MODU
                 +L*c%MODU*c%MODU*c%MODU)%MODU;
         f[x].sum2=(f[x].sum2+2*f[x].sum1%MODU*c%MODU+L*c%MODU*c%MODU)%MODU;
         f[x].sum1=(f[x].sum1+L*c%MODU)%MODU;
         f[x].add+=c;
         f[x].add%=MODU;
    }

    void Set(int x,int l,int r,int v){
        if(v==-1)return;
        int L=(r-l+1)%MODU;
        f[x].sum1=L*v%MODU;
        f[x].sum2=L*v%MODU*v%MODU;
        f[x].sum3=L*v%MODU*v%MODU*v%MODU;
        f[x].set=v;
        f[x].add=0;
        f[x].mul=1;

    }

    void Mul(int x,int l,int r,int c){
         if(c==1)return;
         f[x].sum3=(f[x].sum3*c%MODU*c%MODU*c%MODU);
         f[x].sum2=(f[x].sum2*c%MODU*c%MODU);
         f[x].sum1=(f[x].sum1*c%MODU);
         f[x].add*=c;f[x].add%=MODU;
         f[x].mul*=c;f[x].mul%=MODU;
    }
    void PushUp(int x){
        int xl=f[x].l,xr=f[x].r;
        f[x].sum3=(f[xl].sum3+f[xr].sum3)%MODU;
        f[x].sum2=(f[xl].sum2+f[xr].sum2)%MODU;
        f[x].sum1=(f[xl].sum1+f[xr].sum1)%MODU;
    }
    void PushDown(int x,int l,int r){
        if(l==r)return;
         int mid=(l+r)>>1;
         if(f[x].set!=-1){
             Set(f[x].l,l,mid,f[x].set);
             Set(f[x].r,mid+1,r,f[x].set);
             f[x].set=-1;
         }
         if(f[x].mul!=1){
              Mul(f[x].l,l,mid,f[x].mul);
              Mul(f[x].r,mid+1,r,f[x].mul);
              f[x].mul=1;
         }
         if(f[x].add!=0){
             Add(f[x].l,l,mid,f[x].add);
             Add(f[x].r,mid+1,r,f[x].add);
             f[x].add=0;
         }
    }

    void Add(int x,int l,int r,int a,int b,int v){
        if(a<=l&&b>=r){
            PushDown(x,l,r);
            Add(x,l,r,v);
        }else{
            PushDown(x,l,r);
            int mid=(l+r)/2;
            if(b<=mid)Add(f[x].l,l,mid,a,b,v);
            else if(a>mid)Add(f[x].r,mid+1,r,a,b,v);
            else{
                 Add(f[x].l,l,mid,a,b,v);
                 Add(f[x].r,mid+1,r,a,b,v);
            }
            PushUp(x);
        }
    }

    void Mul(int x,int l,int r,int a,int b,int c){
        if(a<=l&&r<=b){
            PushDown(x,l,r);
            Mul(x,l,r,c);
        }else{
            PushDown(x,l,r);
            int mid=(l+r)/2;
            if(b<=mid)Mul(f[x].l,l,mid,a,b,c);
            else if(a>mid)Mul(f[x].r,mid+1,r,a,b,c);
            else{
                 Mul(f[x].l,l,mid,a,b,c);
                 Mul(f[x].r,mid+1,r,a,b,c);
            }
            PushUp(x);
        }
    }

    void Set(int x,int l,int r,int a,int b,int c){
        if(a<=l&&b>=r){
            PushDown(x,l,r);
            Set(x,l,r,c);
        }else{
            PushDown(x,l,r);
            int mid=(l+r)/2;
            if(b<=mid)Set(f[x].l,l,mid,a,b,c);
            else if(a>mid)Set(f[x].r,mid+1,r,a,b,c);
            else{
                 Set(f[x].l,l,mid,a,b,c);
                 Set(f[x].r,mid+1,r,a,b,c);
            }
            PushUp(x);
        }
    }

    int Query(int x,int l,int r,int a,int b,int op){
        if(a<=l&&b>=r){
            if(1==op)return f[x].sum1;
            if(2==op)return f[x].sum2;
            if(3==op)return f[x].sum3;
        }else{
             PushDown(x,l,r);
             int mid=(l+r)/2;
             int ret=0;
             if(b<=mid)ret=(ret+Query(f[x].l,l,mid,a,b,op))%MODU;
             else if(a>mid)ret=(ret+Query(f[x].r,mid+1,r,a,b,op))%MODU;
             else{
                  ret=(ret+Query(f[x].l,l,mid,a,b,op))%MODU;
                  ret=(ret+Query(f[x].r,mid+1,r,a,b,op))%MODU;
             }
             PushUp(x);
             return ret%MODU;//????
        }
    }
}t;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    while(true){
         scanf("%d%d",&N,&M);
         if((!N)&&(!M))break;
         t.Init(1,N);
         for(int i=0;i<M;i++){
             int op,l,r,p;
             scanf("%d%d%d%d",&op,&l,&r,&p);
             if(1==op){
                 t.Add(t.root,1,N,l,r,p);
             }else if(2==op){
                 t.Mul(t.root,1,N,l,r,p);
             }else if(3==op){
                 t.Set(t.root,1,N,l,r,p);
             }else if(4==op){
                  printf("%d\n",t.Query(t.root,1,N,l,r,p));
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
