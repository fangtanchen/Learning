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
int K,MODU;


class Matrix{
    public:
        int nrow,ncol;
        int mat[11][11];
        Matrix(int nr=10,int nc=10){
            nrow=nr;
            ncol=nc;
            memset(mat,0,sizeof(mat));
        }
        Matrix(const Matrix &A){
             nrow=A.nrow;
             ncol=A.ncol;
             memcpy(mat,A.mat,sizeof(mat));
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
};

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int a[11];
    Matrix A(10,10);
    int p[20][10];

    while(EOF!=scanf("%d%d",&K,&MODU)){
        if(K<10){
            printf("%d\n",K%MODU);
            continue;
        }
        for(int i=1;i<11;i++){
            scanf("%d",a+i);
        }
        memset(p,0,sizeof(p));
        for(int i=0;i<10;i++){
            p[i][i]=1;
        }
        for(int i=10;i<20;i++){
            for(int k=1;k<=10;k++){
                if(a[k]==0)continue;
                for(int j=0;j<10;j++){
                    if(p[i-k][j]==0)continue;
                     p[i][j]+=p[i-k][j]*a[k];
                     p[i][j]%=MODU;
                }
            }
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                A.mat[i][j]=p[i+10][j];
            }
        }
        int h=K/10;
        Matrix ans(10,1);
        for(int i=0;i<10;i++)ans.mat[i][0]=i;
        while(h){
             if(h&1)ans=A*ans;
             A=A*A;
             h>>=1;
        }
        printf("%d\n",ans.mat[K%10][0]);

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
