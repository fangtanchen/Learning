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
const int MODU=1234567891;


class Matrix{
    public:
        int nrow,ncol;
        LL mat[35][35];
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
        friend Matrix operator+(const Matrix &A,const Matrix &B){
             Matrix tmp(A.nrow,B.ncol);
             for(int i=0;i<A.nrow;i++){
                 for(int k=0;k<A.ncol;k++){
                     tmp.mat[i][k]=(A.mat[i][k]+B.mat[i][k])%MODU;
                 }
             }
             return tmp;
        }
};

int T,N,K;
Matrix A,ans,e;

void Solve(int p){
    if(p==0)return;
    if(p==1){
        ans=A;
        e=A;
        return;
    }
    Solve(p/2);
    Matrix tmp=(ans)*e+ans;
    e=e*e;
    if(p&0x01){
         e=e*A;
         tmp=tmp+e;
    }
    ans=tmp;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         scanf("%d%d",&N,&K);
         e=Matrix(K+1,K+1);
         A=Matrix(K+1,K+1);
         ans=Matrix(K+1,K+1);
         for(int i=0;i<=K;i++){
             e.mat[i][i]=1;
             ans.mat[i][i]=1;
         }
         for(int j=1;j<=K;j++){
              A.mat[j][j]=j;
              A.mat[j-1][j]=K-j+1;
         }
         Solve(N);
         /*for(int i=0;i<=K;i++){
             ans.mat[i][i]+=1;
             ans.mat[i][i]%=MODU;
         }*/

         printf("%lld\n",ans.mat[0][K]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
