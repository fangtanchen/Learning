#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef long long int LL;
int MODU=2008;
int K,B,N,M;

class Matrix{
    public:
        int nrow,ncol;
        LL mat[4][4];
        Matrix(int nr=0,int nc=0){
            nrow=nr;ncol=nc;
            memset(mat,0,sizeof(mat));
        }
        Matrix(const Matrix& m){
            nrow=m.nrow;
            ncol=m.ncol;
            memcpy(mat,m.mat,sizeof(mat));
        }
        void InitUnit(int nr,int nc){
            nrow=nr;ncol=nc;
            memset(mat,0,sizeof(mat));
            for(int i=0;i<nrow;i++)mat[i][i]=1;
        }
        friend Matrix operator*(const Matrix &A,const Matrix &B){
            Matrix tmp=Matrix(A.nrow,B.ncol);
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
            Matrix tmp=Matrix(A.nrow,B.ncol);
            for(int i=0;i<A.nrow;i++){
                for(int k=0;k<A.ncol;k++){
                    tmp.mat[i][k]=(A.mat[i][k]+B.mat[i][k])%MODU;
                }
            }
            return tmp;
        }
};

Matrix e,ans,A,init,C;


void Solve(int p){
    if(0>=p)return;
    if(1==p){
        e=A;
        ans=A;
        return;
    }
    Solve(p/2);
    ans=(ans*e)+ans;
    e=e*e;
    if(1&p){
         e=e*A;
         ans=ans+e;
    }
}

Matrix ModExp(Matrix B,int b){
    Matrix tmp;
    Matrix A=B;
    tmp.InitUnit(2,2);
    while(b){
         if(1&b)tmp=tmp*A;
         A=A*A;
         b>>=1;
    }
    return tmp;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    while(scanf("%d%d%d%d",&K,&B,&N,&M)!=EOF){
        MODU=M;
        init=Matrix(2,2);
        init.mat[0][1]=init.mat[1][0]=init.mat[1][1]=1;
        A=ModExp(init,K);
        ans.InitUnit(2,2);
        e.InitUnit(2,2);
        Solve(N-1);
        e.InitUnit(2,2);
        ans=ans+e;
        C.InitUnit(2,2);
        int tt=B;
        A=init;
        while(tt>0){
             if(1&tt)C=C*A;
             A=A*A;
             tt>>=1;
        }
        ans=C*ans;
        printf("%lld\n",ans.mat[1][0]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
