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
const int MAXN=1e5+10;
const int MAXS=17;

int R[MAXS][MAXN];
int h[MAXN];
int N;
int fac[MAXS];

int RMQ(int l,int r){
    if(r<l)return -1;
    if(l==r)return R[0][l];
    int si=0,d=r-l+1;
    while(fac[si]<d){
        si++;
    }
    si--;
    return max(R[si][l],R[si][r-fac[si]+1]);
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    fac[0]=1;
    for(int i=1;i<MAXS;i++)fac[i]=2*fac[i-1];
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d",h+i);
            R[0][i]=h[i];
        }
        for(int si=1;si<MAXS;si++){
            int maxni=N-fac[si]+1;
            for(int ni=1;ni<=maxni;ni++){
                R[si][ni]=max(R[si-1][ni],R[si-1][ni+fac[si-1]]);
            }
        }
        int maxh=RMQ(1,N);
        for(int i=1;i<=N;i++){
            if(maxh<=h[i]){
                printf("-1 -1\n");
                continue;
            }
            int l=1,r=i-1;
             int a=RMQ(l,r);
             if(a>h[i]){
                 while(l<r){
                     int mid=(l+r)>>1;
                     int b=RMQ(mid+1,r);
                     if(b>h[i])l=mid+1;
                     else r=mid;
                 }
                 a=l;
             }else a=-1;
             if(a==-1){
                  l=i+1;r=N;
                  a=RMQ(l,r);
                  while(l<r){
                      int mid=(l+r)>>1;
                      int b=RMQ(mid+1,r);
                      if(b>h[i])l=mid+1;
                      else r=mid;
                  }
                  a=l;
             }
             printf("%d ",a);

             l=i+1;r=N;
             a=RMQ(l,r);
             if(a>h[i]){
                 while(l<r){
                     int mid=(l+r)>>1;
                     int b=RMQ(l,mid);
                     if(b>h[i])r=mid;
                     else l=mid+1;
                 }
                 a=l;
             }else a=-1;
             if(a==-1){
                 l=1;r=i-1;
                 while(l<r){
                     int mid=(l+r)>>1;
                     int b=RMQ(l,mid);
                     if(b>h[i])r=mid;
                     else l=mid+1;
                 }
                 a=l;
             }
             printf("%d\n",a);
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
