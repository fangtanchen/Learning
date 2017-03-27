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
typedef long long LL;
const int MAXK=100;
const int MODU=1e9+7;

struct Mat{
    LL a[MAXK][MAXK];
    int nrow,ncol;
    Mat(int nr=0,int nc=0){
         nrow=nr;
         ncol=nc;
         memset(a,0,sizeof(a));
    }
}E,T,O;

LL N,K;
LL C[MAXK][MAXK];
void Init(){
    for(int i=0;i<E.nrow;i++){
        E.a[i][i]=1;
    }
    C[0][0]=1;
    for(int i=1;i<=K;i++){
         C[i][0]=1;
         for(int j=1;j<=i;j++){
             C[i][j]=(C[i-1][j-1]+C[i-1][j])%MODU;
         }
    }
}

Mat MatMul(const Mat &A,const Mat &B){
    Mat ret(A.nrow,B.ncol);
    for(int i=0;i<A.nrow;i++){
        for(int j=0;j<B.ncol;j++){
            for(int k=0;k<A.ncol;k++){
                ret.a[i][j]+=A.a[i][k]*B.a[k][j];
                ret.a[i][j]%=MODU;
            }
        }
    }
    return ret;
}

Mat MatExp(const Mat& A,int b){
     Mat ret=E;
     Mat tmp=A;
     while(b){
         if(1&b){
             ret=MatMul(ret,tmp);
         }
         tmp=MatMul(tmp,tmp);
         b>>=1;
     }
     return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>K;
    E=Mat(2*K+3,2*K+3);
    O=Mat(2*K+3,2*K+3);
    T=Mat(2*K+3,2*K+3);

    Init();
    for(int i=0;i<=K;i++){
        for(int j=0;j<=i;j++){
            T.a[K+1+j][i]=T.a[K+1+j][i+K+1]
                =T.a[j][i+K+1]=C[i][j];
        }
    }
    T.a[2*K+2][2*K+2]=T.a[2*K+1][2*K+2]=1;
    Mat tmp(1,2*K+3);
    for(int i=0;i<2*K+2;i++){
         tmp.a[0][i]=1;
    }
    LL tmpN=N;
    while(tmpN){
        if(1&tmpN)tmp=MatMul(tmp,T);
        T=MatMul(T,T);
        tmpN>>=1;
    }
    cout<<tmp.a[0][2*K+2]<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
