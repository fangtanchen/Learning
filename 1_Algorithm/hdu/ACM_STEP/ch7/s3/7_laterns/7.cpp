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
const int MAXN=55;

int A[MAXN][MAXN],B[MAXN][MAXN];
int T,N,M,K,Q;


void SwapRow(int *x,int *y,int num){
    for(int i=0;i<=num;i++){
        swap(x[i],y[i]);
    }
}

int Gaussian(){
    for(int i=1,j=0;i<=N&&j<M;j++){
        int mu=i;
        for(int ti=i;ti<=N;ti++){
            if(A[ti][j]){
                mu=ti;
                break;
            }
        }
        if(A[mu][j]==0)continue;
        if(mu!=i)SwapRow(A[i],A[mu],M);
        for(int ti=i+1;ti<=N;ti++){
            if(A[ti][j]==0)continue;
            for(int tj=j;tj<=M;tj++){
                A[ti][tj]^=A[i][tj];
            }
        }
        i++;
    }
    int has=M;
    for(int i=N;i>=1;i--){
        int t=0;
        for(int j=0;j<M;j++){
            if(A[i][j]){
                t=1;
                break;
            }
        }
        if(0==t){
             if(A[i][M])return -1;
        }else
            has--;
        if(has==0)break;
    }
    return has;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
         printf("Case %d:\n",ti);
         scanf("%d%d",&N,&M);
         memset(B,0,sizeof(B));
         for(int mi=0;mi<M;mi++){
              scanf("%d",&K);
              for(int ki=0;ki<K;ki++){
                  int a;
                  scanf("%d",&a);
                  B[a][mi]=1;
              }
         }
         scanf("%d",&Q);
         while(Q--){
             memcpy(A,B,sizeof(B));
             for(int ni=1;ni<=N;ni++){
                 scanf("%d",A[ni]+M);
             }
             int ret=Gaussian();
             long long int ans=0;
             if(ret>=0)ans=(1LL<<ret);
             printf("%lld\n",ans);
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
