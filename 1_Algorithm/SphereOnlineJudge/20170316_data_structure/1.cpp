#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=100005;
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;

typedef long long LL;

#define ls(x)  ((x)<<1)
#define rs(x) ((x)<<1|1)


struct node{
    int l,r;
    LL big,sma;
    LL sum,tag,cov;
    void make(int x,int y){
         l=x,r=y;
         big=sma=0;
         sum=tag=cov=0;
    }
    bool judge(int x,int y){
         return l==x&&r==y;
    }
}tr[MAXN*10];
int N,M;

inline LL read(){
     char ch=getchar();
     while(ch<'0'||ch>'9')ch=getchar();
     LL x=0;
     while(ch<='9'&&ch>='0'){
          x=x*10+ch-'0';
          ch=getchar();
     }
     return x;
}

void PushUp(int now){
    tr[now].sma=min(tr[ls(now)].sma,tr[rs(now)].sma);
    tr[now].big=max(tr[ls(now)].big,tr[rs(now)].big);
    tr[now].sum=tr[ls(now)].sum+tr[rs(now)].sum;
}

void PushDown(int x){
    if(tr[x].cov>0){
        int mid=(tr[x].l+tr[x].r)>>1;
        LL sl=mid-tr[x].l+1,sr=tr[x].r-mid;
        tr[ls(x)].sma=tr[rs(x)].sma=tr[ls(x)].big=tr[rs(x)].big
            =tr[ls(x)].cov=tr[rs(x)].cov=tr[x].cov;
        tr[ls(x)].sum=sl*tr[x].cov;
        tr[rs(x)].sum=sr*tr[x].cov;
        tr[x].cov=tr[ls(x)].tag=tr[rs(x)].tag=0;
    }
    if(tr[x].tag!=0){
        int mid=(tr[x].l+tr[x].r)>>1;
        LL sl=mid-tr[x].l+1,sr=tr[x].r-mid;
        tr[ls(x)].tag+=tr[x].tag;
        tr[ls(x)].sma+=tr[x].tag;
        tr[ls(x)].big+=tr[x].tag;
        tr[ls(x)].sum+=sl*tr[x].tag;
        tr[rs(x)].tag+=tr[x].tag;
        tr[rs(x)].sma+=tr[x].tag;
        tr[rs(x)].big+=tr[x].tag;
        tr[rs(x)].sum+=sr*tr[x].tag;
        tr[x].tag=0;
    }
}

void Build(int now,int l,int r){
    tr[now].make(l,r);
    if(l==r){
        tr[now].big=tr[now].sma=tr[now].sum=read();
        return;
    }
    int mid=(l+r)>>1;
    Build(ls(now),l,mid);
    Build(rs(now),mid+1,r);
    PushUp(now);
}

LL CalSum(int now,int l,int r){
     if(tr[now].judge(l,r))return tr[now].sum;
     int mid=(tr[now].l+tr[now].r)>>1;
     PushDown(now);
     LL s1=0,s2=0;
     if(l<=mid)s1=CalSum(ls(now),l,min(r,mid));
     if(r>mid)s2=CalSum(rs(now),max(mid+1,l),r);
     return s1+s2;
}

void Add(int now,int l,int r,LL num){
    if(tr[now].judge(l,r)){
        tr[now].sum+=1ll*(r-l+1)*num;
        tr[now].big+=num;
        tr[now].sma+=num;
        tr[now].tag+=num;
        return;
    }
    PushDown(now);
    int mid=(tr[now].l+tr[now].r)>>1;
    if(l<=mid)Add(ls(now),l,min(r,mid),num);
    if(r>mid)Add(rs(now),max(mid+1,l),r,num);
    PushUp(now);
}

void Upd(int now,int l,int r){
    if(!tr[now].judge(l,r)){
        int mid=(tr[now].l+tr[now].r)>>1;
        PushDown(now);
        if(l<=mid)Upd(ls(now),l,min(r,mid));
        if(r>mid)Upd(rs(now),max(mid+1,l),r);
        PushUp(now);
        return;
    }
    if(tr[now].big==1){
        return;
    }
    if(tr[now].l==tr[now].r){
        tr[now].sum=tr[now].sma=tr[now].big=floor(sqrt(tr[now].big));
        return;
    }
    if(tr[now].big==tr[now].sma){
        LL tmp=tr[now].big;
        tr[now].big=tr[now].sma=floor(sqrt(tr[now].big));
        tr[now].sum=(1ll)*(r-l+1)*tr[now].big;
        tr[now].tag-=(tmp-tr[now].big);
        return;
    }
    if(tr[now].big==tr[now].sma+1){
         LL tb=tr[now].big,ts=tr[now].sma;
         LL totb=tr[now].sum-(1ll)*(r-l+1)*(ts);
         LL tots=r-l+1-totb;
         tr[now].big=floor(sqrt(tr[now].big));
         tr[now].sma=floor(sqrt(tr[now].sma));
         if(tr[now].big==tr[now].sma){
             tr[now].cov=tr[now].big;
             tr[now].sum=(1ll)*(r-l+1)*tr[now].big;
             tr[now].tag=0;
             return;
         }else{
              tr[now].sum=(1ll)*totb*tr[now].big+tots*tr[now].sma;
              tr[now].tag+=(tr[now].big-tb);
              return;
         }
    }
    PushDown(now);
    int mid=(tr[now].l+tr[now].r)/2;
    if(l<=mid)Upd(ls(now),l,min(r,mid));
    if(r>mid)Upd(rs(now),max(l,mid+1),r);
    PushUp(now);
    return;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T=read();
    while(T--){
        memset(tr,0,sizeof(tr));
        N=read();
        M=read();
        Build(1,1,N);
        while(M--){
            int t,l,r;
            t=read();l=read();r=read();
            if(t==1){
                LL x=read();
                Add(1,l,r,x);
            }else if(2==t){
                Upd(1,l,r);
            }else{
                printf("%lld\n",CalSum(1,l,r));
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
