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
const int MAXN=60;
const LL MODU=(1000000000LL*200000000LL)+3;
const LL DIFF=(1000000000LL*100000000LL);

LL A[MAXN][MAXN];
LL in[MAXN][MAXN];
LL ans[MAXN];
int T,N;


LL ModMul(LL a,LL b,LL p){
    LL ret=0;
    while(b){
        if(b&1)ret=(ret+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return ret;
}

LL ModExp(LL a,LL b,LL p){
     LL ret=1;
     while(b){
         if(b&1)ret=ModMul(ret,a,p);
         b>>=1;
         a=ModMul(a,a,p);
     }
     return ret;
}

void SwapRow(LL *x,LL *y,int n){
    for(int i=0;i<n;i++){
        swap(x[i],y[i]);
    }
}

void Gaussian(){
    for(int i=0,j=0;i<N&&j<N;j++){
        int mu=i;
        for(int ti=i;ti<N;ti++){
            if(A[ti][j]){
                mu=ti;
                break;
            }
        }
        if(A[mu][j]==0)continue;
        if(mu!=i)SwapRow(A[mu],A[i],N+1);

        LL vv=ModExp(A[i][j],MODU-2,MODU);
        LL tmp=ModExp(A[i][j],MODU-1,MODU);
        for(int ti=i+1;ti<N;ti++){
            if(A[ti][j]==0)continue;
            LL P=ModMul(A[ti][j],vv,MODU);
            for(int tj=i;tj<=N;tj++){
                A[ti][tj]=(A[ti][tj]-ModMul(A[i][tj],P,MODU)+MODU)%MODU;
            }
        }
        i++;
    }
    memset(ans,0,sizeof(ans));
    for(int i=N-1;i>=0;i--){
        for(int j=i+1;j<N;j++){
             A[i][N]=(A[i][N]-ModMul(A[i][j],ans[j],MODU)+MODU)%MODU;
        }
        ans[i]=ModMul(A[i][N],ModExp(A[i][i],MODU-2,MODU),MODU);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
         printf("Case %d:\n",ti);
         scanf("%d",&N);
         for(int i=0;i<=N;i++){
             in[i][N]=0;
             for(int j=0;j<N;j++){
                  scanf("%lld",in[i]+j);
                  in[i][j]+=DIFF;
                  in[i][N]=(in[i][N]+ModMul(in[i][j],in[i][j],MODU))%MODU;
             }
         }
         for(int i=0;i<N;i++){
             for(int j=0;j<N;j++){
                 A[i][j]=(in[i+1][j]-in[i][j])*2%MODU;
                 A[i][j]=(A[i][j]+MODU)%MODU;
             }
             A[i][N]=(in[i+1][N]-in[i][N]+MODU)%MODU;
         }
         Gaussian();
         printf("%lld",ans[0]-DIFF);
         for(int i=1;i<N;i++){
              printf(" %lld",ans[i]-DIFF);
         }
         printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
