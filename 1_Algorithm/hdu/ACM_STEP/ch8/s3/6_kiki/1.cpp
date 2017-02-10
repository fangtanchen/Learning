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
const int MODU=2;
const int MAXN=105;

class Matrix{
    public:
        int nrow,ncol;
        int mat[MAXN][MAXN];
        Matrix(int nr=0,int nc=0){
             nrow=nr;ncol=nc;
             memset(mat,0,sizeof(mat));
        }
        Matrix(const Matrix& m){
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
             for(int i=0;i<nrow;i++)
                 mat[i][i]=1;
        }
};

Matrix A,e,ans,orm;
int M,N;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d",&M)){
             char str[MAXN];
             scanf("%s",str);
             N=strlen(str);
             ans=Matrix(1,N);
             for(int i=0;i<N;i++){
                  ans.mat[0][i]=str[i]-'0';
             }
             A=Matrix(N,N);
             for(int i=0;i<A.nrow;i++){
                 A.mat[i][(i+1)%N]=1;
                 A.mat[i][i]=1;
             }
             int tmp=M;
             while(M>0){
                 if(1&M) {
                     ans=ans*A;
                 }
                 A=A*A;
                 M>>=1;
             }
             printf("%d",ans.mat[0][0]);
             for(int i=1;i<N;i++){
                  printf("%d",ans.mat[0][i]);
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
