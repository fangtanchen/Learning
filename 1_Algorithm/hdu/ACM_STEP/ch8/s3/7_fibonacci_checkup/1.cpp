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
const int MAXN=3;
int MODU,T,N;

class Matrix{
     public:
         int nrow,ncol;
         int mat[MAXN][MAXN];
         Matrix(int nr=0,int nc=0){
              nrow=nr;ncol=nc;
              memset(mat,0,sizeof(mat));
         }
         Matrix(const Matrix &m){
              nrow=m.nrow;
              ncol=m.ncol;
              memcpy(mat,m.mat,sizeof(mat));
         }
         friend Matrix operator*(const Matrix &A,const Matrix &B){
              Matrix tmp(A.nrow,B.ncol);
              for(int i=0;i<A.nrow;i++){
                  for(int k=0;k<A.ncol;k++){
                      if(A.mat[i][k]==0)continue;
                      for(int j=0;j<B.ncol;j++){
                          if(B.mat[k][j]==0)continue;
                          tmp.mat[i][j]+=A.mat[i][k]*B.mat[k][j];
                          tmp.mat[i][j]%=MODU;
                      }
                  }
              }
              return tmp;
         }
         void Init(){
              for(int i=0;i<nrow;i++)mat[i][i]=1;
         }
}ans,e,A;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&MODU);
        int tmpN=2*N;
        ans=Matrix(1,2);
        ans.mat[0][0]=0;ans.mat[0][1]=1;
        e.Init();
        A=Matrix(2,2);
        A.mat[0][1]=A.mat[1][0]=A.mat[1][1]=1;
        while(tmpN>0){
            if(1&tmpN)ans=ans*A;
            A=A*A;
            tmpN>>=1;
        }
        printf("%d\n",ans.mat[0][0]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
