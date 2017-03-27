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
const int MAXN=5e4+10;
const int MODU=1e9+7;

int N,B,K,X;
int A[MAXN];
int cnt[11];
class Mat{
    public:
    int nrows,ncols;
    long long int arr[110][110];
    Mat(int r=0,int c=0){
        nrows=r;ncols=c;
        memset(arr,0,sizeof(arr));
    }
    Mat(const Mat &a){
        nrows=a.nrows;ncols=a.ncols;
        for(int i=0;i<nrows;i++){
            for(int j=0;j<ncols;j++)
                arr[i][j]=a.arr[i][j];
        }
    }
    Mat operator=(const Mat &a){
        nrows=a.nrows;ncols=a.ncols;
        for(int i=0;i<nrows;i++){
            for(int j=0;j<ncols;j++)
                arr[i][j]=a.arr[i][j];
        }
    }
}O,E,T;


Mat MatMul(const Mat &x,const Mat &y){
    Mat ret(x.nrows,y.ncols);
    for(int i=0;i<x.nrows;i++){
        for(int j=0;j<y.ncols;j++){
            for(int k=0;k<x.ncols;k++){
                ret.arr[i][j]+=x.arr[i][k]*y.arr[k][j];
                ret.arr[i][j]%=MODU;
            }
        }
    }
    return ret;
}
Mat MatPow(Mat x,int t){
    Mat ret(1,x.nrows);
    ret.arr[0][0]=1;
    while(t){
        if(t&1){
            ret=MatMul(ret,x);
        }
        x=MatMul(x,x);
        t>>=1;
    }
    return ret;
}

int main(){
#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d%d%d",&N,&B,&K,&X);
    for(int i=0;i<N;i++){
        scanf("%d",A+i);
        cnt[A[i]%X]++;
    }
    E=Mat(X,X);O=Mat(X,X);T=Mat(X,X);

    for(int i=0;i<X;i++){
         E.arr[i][i]=1;
    }
    for(int i=0;i<X;i++){
        for(int j=0;j<10;j++){
            T.arr[i][(10*i+j)%X]+=cnt[j];
            T.arr[i][(10*i+j)%X]%=MODU;
        }
    }
    T=MatPow(T,B);
    printf("%lld\n",T.arr[0][K]);



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
