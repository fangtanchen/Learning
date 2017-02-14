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
const int MAXN=1005;

int T,R,C,K;
int a[MAXN][MAXN],f[MAXN][MAXN],U[MAXN],D[MAXN];

int Calc(int k){
    int ret=0;
    memset(f,0,sizeof(f));
    for(int ri=1;ri<=R;ri++){
        for(int ci=1;ci<=C;ci++){
            if(a[ri][ci]>=k)f[ri][ci]=f[ri][ci-1]+1;//##important part
            else f[ri][ci]=0;
        }
    }
    for(int ci=1;ci<=C;ci++){
        for(int ri=1;ri<=R;ri++){
            int now=ri-1;
            for(;now&&(f[ri][ci]<=f[now][ci]);now=U[now])
                ;
            U[ri]=now;
        }
        for(int ri=R;ri;ri--){
             int now=ri+1;
             for(;(now!=R+1)&&(f[ri][ci]<=f[now][ci]);now=D[now])
                 ;
             D[ri]=now;
        }
        for(int ri=1;ri<=R;ri++){
             ret=max(ret,(D[ri]-U[ri]-1)*f[ri][ci]);
        }
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         scanf("%d%d%d",&R,&C,&K);
         for(int ri=1;ri<=R;ri++){
             for(int ci=1;ci<=C;ci++){
                 scanf("%d",a[ri]+ci);
             }
         }
         int l=1,r=1e9+10;
         while(l<=r){
              int mid=(l+r)>>1;
              if(Calc(mid)>=K){
                  l=mid+1;
              }else{
                  r=mid-1;
              }
         }
         printf("%d %d\n",r,Calc(r));
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
