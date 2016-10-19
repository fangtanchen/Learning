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
const int MAXN=1e8+10;
const int MAXM=6;
const int MAXS=8;
const int MOD=12357;


class Matrix{
    public:
    int trans[MAXS+1][MAXS+1];
    int nrow,ncol;
    Matrix(int r=MAXS,int c=MAXS){
        nrow=r;
        ncol=c;
        memset(trans,0,sizeof(trans));
    }
    void Output(){
        for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
                printf("%d ",trans[i][j]);
            }
            printf("\n");
        }
    }
    friend Matrix operator*(const Matrix x,const Matrix y){
        Matrix ret(x.nrow,y.ncol);
        for(int i=0;i<x.nrow;i++){
            for(int j=0;j<y.ncol;j++){
                for(int k=0;k<x.ncol;k++){
                    ret.trans[i][j]+=x.trans[i][k]*y.trans[k][j];
                    ret.trans[i][j]%=MOD;
                }
            }
        }
        return ret;
    }
};



Matrix T;
int fac[20];
int N;

void Init(){
    fac[0]=1;
    for(int i=1;i<20;i++){
        fac[i]=fac[i-1]*2;
    }
    for(int i=0;i<MAXS;i++){
        T.trans[i][MAXS-i-1]=1;
    }
    T.trans[3][7]=1;
    T.trans[6][7]=1;
    T.trans[7][3]=T.trans[7][6]=1;
}

Matrix Solve(Matrix x,Matrix T,int N){
    while(N){
        if(N%2){
            x=x*T;
            N--;
        }
        N/=2;
        T=T*T;
    }
    return x;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    cin>>N;
    if(N%2){
         printf("0\n");
    }else{
        Matrix x(1,MAXS);
        x.trans[0][7]=1;
        Matrix ret=Solve(x,T,N);
        printf("%d\n",ret.trans[0][7]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
