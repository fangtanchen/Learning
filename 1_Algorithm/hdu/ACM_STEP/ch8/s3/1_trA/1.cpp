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
const int MAXN=14;
const int MODU=9973;

class Matrix{
    public:
     int nrow,ncol;
     int a[MAXN][MAXN];
     Matrix(int r=0,int c=0){
         nrow=r;
         ncol=c;
         memset(a,0,sizeof(a));
     }
     Matrix(const Matrix &m){
         nrow=m.nrow;
         ncol=m.ncol;
         for(int i=1;i<=nrow;i++){
             for(int j=1;j<=ncol;j++){
                 a[i][j]=m.a[i][j];
             }
         }
     }
     friend Matrix operator*(const Matrix A,const Matrix B){
          Matrix tmp(A.nrow,B.ncol);
          for(int i=1;i<=A.nrow;i++){
              for(int k=1;k<=A.ncol;k++){
                  if(A.a[i][k]==0)continue;
                  for(int j=1;j<=B.ncol;j++){
                      tmp.a[i][j]+=(A.a[i][k]*B.a[k][j]);
                      tmp.a[i][j]%=MODU;
                  }
              }
          }
          return tmp;
     }
};

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T,N,K;
    scanf("%d",&T);
    while(T--){
         scanf("%d%d",&N,&K);
         Matrix mat(N,N);
         for(int i=1;i<=N;i++){
             for(int j=1;j<=N;j++){
                  scanf("%d",mat.a[i]+j);
             }
         }
         Matrix ans(N,N);
         for(int i=1;i<=N;i++){
              ans.a[i][i]=1;
         }
         while(K){
             if(K&1)ans=ans*mat;
             K>>=1;
             mat=mat*mat;
         }
         int tt=0;
         for(int i=1;i<=N;i++){
              tt+=ans.a[i][i];
         }
         tt%=MODU;
         printf("%d\n",tt);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
