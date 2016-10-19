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
const int MAXN=1e8+9;
const int MAXM=7;
const int MAXS=200;
const int MOD=12357;

class Matrix{
    public:
    int nrow,ncol;
    int val[MAXS+1][MAXS+1];
    Matrix(int r=MAXS,int c=MAXS){
        nrow=r;
        ncol=c;
        memset(val,0,sizeof(val));
    }

    friend Matrix operator*(const Matrix x,const Matrix y){
        Matrix ret(x.nrow,y.ncol);
        for(int i=0;i<x.nrow;i++){
            for(int j=0;j<y.ncol;j++){
                for(int k=0;k<x.ncol;k++){
                    ret.val[i][j]+=x.val[i][k]*y.val[k][j];
                    ret.val[i][j]%=MOD;
                }
            }
        }
        return ret;

    }

    void Output(){
        for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
                printf("%d ",val[i][j]);
            }
            printf("\n");
        };
    }
};


int K,N;
int fac[20];


Matrix Solve(Matrix x,Matrix T,int n){
    while(n){
        if(n&1){
            x=x*T;
        }
        n>>=1;
        T=T*T;
    }
    return x;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

    fac[0]=1;
    for(int i=1;i<20;i++){
         fac[i]=2*fac[i-1];
    }
    cin>>K>>N;
    if((K&1)&&(N&1)){
        printf("0\n");
        return 0;
    }
    int maxs=(1<<K);
    Matrix T(maxs,maxs);
    int himax=K/2;
    for(int sq=0;sq<maxs;sq++) {
        int sp=maxs-1-sq;
        T.val[sp][sq]=1;
        for(int hi=1;hi<=himax;hi++){
            for(int pi=K-hi*2;pi>=0;pi--){
                int cnt=0;
                int sp=maxs-1-sq;
                for(int j=pi;j<K;j++){
                    if((j<K-1)&&((sq&fac[j])&&(sq&fac[j+1]))){
                        sp=sp+fac[j]+fac[j+1];
                        cnt++;
                    }
                }
                if(cnt==hi){
                    T.val[sp][sq]=1;
                }
            };
        }
    }
    T.Output();
    Matrix x(1,maxs);
    x.val[0][maxs-1]=1;
    Matrix ans=Solve(x,T,N);
    printf("%d\n",ans.val[0][maxs-1]);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
