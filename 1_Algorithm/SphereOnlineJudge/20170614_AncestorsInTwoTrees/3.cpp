#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int MAXN=5e5+10;
struct node{
    node *next;
    int where;
}*first[2*MAXN],a[4*MAXN];

vector<int> L[4*MAXN],R[4*MAXN];
int test,n,l,dfs[2*MAXN],Left[2*MAXN],Right[2*MAXN],cnt;

inline void makelist(int x,int y){
     a[++l].where=y;
     a[l].next=first[x];
     first[x]=&a[l];
}

inline void soso(int now){
     Left[now]=dfs[now]=++cnt;
     for(node *x=first[now];x;x=x->next)
         if(!dfs[x->where])
             soso(x->where);
     Right[now]=cnt;
}

inline void insert(int k,int Left,int Right,int s,int t,int x,int y){
    if(Left==s&& Right==t){
        L[k].push_back(x);
        R[k].push_back(y);
        return;
    }
    int i=(Left+Right)>>1;
    if(t<=i)insert(k+k,Left,i,s,t,x,y);
    else if(s>i)insert(k+k+1,i+1,Right,s,t,x,y);
    else{
         insert(k+k,Left,i,s,i,x,y);
         insert(k+k+1,i+1,Right,i+1,t,x,y);
    }
}


int calc(int k,int Left,int Right,int x,int y){
     int l=0,r=R[k].size()+1,m=(l+r)>>1;
     for(;l+1<r;m=(l+r)>>1){
         if(R[k][m-1]<y)
             l=m;
         else r=m;
     }
     int will=R[k].size()-l;
     l=0;r=R[k].size()+1;m=(l+r)>>1;
     for(;l+1<r;m=(l+r)>>1){
          if(L[k][m-1]>y)
              r=m;
          else
              l=m;
     }
     will-=R[k].size()+1-r;
     if(Left==Right)return will;
     int i=(Left+Right)>>1;
     if(x<=i)
         return will+calc(k+k,Left,i,x,y);
     else
         return will+calc(k+k+1,i+1,Right,x,y);
}

int main(){
     freopen("in.txt","r",stdin);
     scanf("%d",&test);
     while(test--){
         scanf("%d",&n);
         for(int i=1;i<=2*n;i++)
             dfs[i]=0;
         memset(first,0,sizeof(first));
         l=0;
         for(int i=1;i<n;i++){
             int x,y;
             scanf("%d%d",&x,&y);
             makelist(x,y);
             makelist(y,x);
         }
         for(int i=1;i<n;i++){
              int x,y;
              scanf("%d%d",&x,&y);
              makelist(x+n,y+n);
              makelist(y+n,x+n);
         }
         cnt=0;
         soso(1);
         soso(1+n);
         for(int i=1;i<=n;i++)
             insert(1,1,n,Left[i],Right[i],Left[i+n],Right[i+n]);
         for(int i=1;i<=4*n;i++){
             sort(L[i].begin(),L[i].end());
             sort(R[i].begin(),R[i].end());
         };
         for(int i=1;i<=n;i++){
              printf("%d ",calc(1,1,n,dfs[i],dfs[i+n])-1);
         }
         printf("\n");
         for(int i=1;i<=4*n;i++)
             L[i].clear(),R[i].clear();

     }
}
