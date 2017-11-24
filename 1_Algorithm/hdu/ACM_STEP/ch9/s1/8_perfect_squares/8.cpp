#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXR=20;
const int MODU=1e4+7;

class Matrix{
    public:
        int arr[MAXR][MAXR];
        int nrows,ncols;
        Matrix(){
            memset(arr,0,sizeof(arr));
            nrows=ncols=0;
        }
        Matrix(const Matrix &A){
            nrows=A.nrows;
            ncols=A.ncols;
            for(int i=0;i<nrows;i++){
                for(int j=0;j<ncols;j++){
                    arr[i][j]=A.arr[i][j];
                }
            }
        }
        void operator = (const Matrix &A){
            nrows=A.nrows;
            ncols=A.ncols;
            for(int i=0;i<nrows;i++){
                for(int j=0;j<ncols;j++){
                    arr[i][j]=A.arr[i][j];
                }
            }
        }
        Matrix operator*(const Matrix &B){
            Matrix C;
            C.nrows=nrows;
            C.ncols=B.ncols;
            for(int i=0;i<C.nrows;i++){
                for(int j=0;j<C.ncols;j++){
                    int temp=0;
                    for(int k=0;k<ncols;k++){
                        temp=temp+arr[i][k]*B.arr[k][j];
                    }
                    temp%=MODU;
                    C.arr[i][j]=temp;
                }
            }
            return C;
        }

};

int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int T,N;
    cin>>T;
    for(int ti=1;ti<=T;ti++){
         Matrix A,B;
         A.nrows=A.ncols=2;
         A.arr[0][0]=4;
         A.arr[0][1]=0;
         A.arr[1][0]=-5;
         A.arr[1][1]=1;
         B.nrows=1,B.ncols=2;
         B.arr[0][0]=2;B.arr[0][1]=1;

         cin>>N;
         if(N&1){
             N=(N+1)/2-1;
         }else{
             N=N/2-1;
             A.arr[1][0]=-4;
         }
         while(N){
             if(1&N){
                 B=B*A;
             }
             A=A*A;
             N/=2;
         }
         B.arr[0][0]=(B.arr[0][0]+MODU)%MODU;
         printf("Case #%d: %d\n",ti,B.arr[0][0]);
    }


#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif

    return 0;
}
