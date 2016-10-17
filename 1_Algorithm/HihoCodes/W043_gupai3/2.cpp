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
const int MAXK=10;
const int MAXS=200;
const int MOD=12357;

class Matrix{
     public:
         int val[MAXS][MAXS];
         int nrow,ncol;
         Matrix(int r=MAXS,int c=MAXS){
             memset(val,0,sizeof(val));
             nrow=r;
             ncol=c;
         }
         friend Matrix operator*(const Matrix x,const Matrix y){
             Matrix ret(x.nrow,y.ncol);
             for(int i=0;i<x.nrow;i++){
                 for(int j=0;j<y.ncol;j++){
                     for(int k=0;k<x.ncol;k++){
                         ret.val[i][j]+=(x.val[i][k]*y.val[k][j]);
                         ret.val[i][j]%=MOD;
                     }
                 }
             }
             return ret;
         }
};

int N,K;
Matrix T,A;

void DFS(int x,int y,int col){
    if(col==K){
        T.val[y][x]=1;
        return;
    }
    DFS((x<<1),(y<<1)|1,col+1);
    DFS((x<<1)|1,y<<1,col+1);
    if(col+2<=K){
         DFS((x<<2)|3,(y<<2)|3,col+2);
    }
}

Matrix Solve(Matrix &x, Matrix &y,int num){
    while(num){
        if(num&1){
            x=x*y;
        }
        num>>=1;
        y=y*y;
    }
    return x;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>K>>N;
    int maxs=1<<K;
    T=Matrix(maxs,maxs);
    DFS(0,0,0);
    A=Matrix(1,maxs);
    A.val[0][maxs-1]=1;
    Matrix ans=Solve(A,T,N);
    cout<<ans.val[0][maxs-1]<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
