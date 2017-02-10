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
const int MODU=2008;

class Matrix{
    public:
        int nrow,ncol;
        int mat[40][40];
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

map<int,int> cities;
map<int,int>::iterator it;
Matrix e,ans,A,init;

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


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int N,K;
    while(scanf("%d",&N)!=EOF){
        cities.clear();
        int pcnt=0;
        init=Matrix(35,35);
        for(int i=0;i<N;i++){
            int p[2];
            for(int j=0;j<2;j++){
                scanf("%d",p+j);
                if(cities.end()==cities.find(p[j])){
                    cities[p[j]]=pcnt++;
                }
            }
            init.mat[cities[p[0]]][cities[p[1]]]++;
        }
        init.nrow=init.ncol=pcnt;
        int K;
        scanf("%d",&K);
        while(K--){
             int v1,v2,t1,t2;
             scanf("%d%d%d%d",&v1,&v2,&t1,&t2);
             if(t1==0)t1=1;
             if(cities.end()==cities.find(v1)
                     || cities.end()==cities.find(v2)){
                 printf("0\n");
                 continue;
             }
             A.InitUnit(pcnt,pcnt);
             e.InitUnit(pcnt,pcnt);
             ans.InitUnit(pcnt,pcnt);
             A=init;

             Solve(t2-t1+1);
             int tmp=t1-1;
             A=init;
             e.InitUnit(pcnt,pcnt);
             while(tmp>0){
                  if(tmp&1)e=e*A;
                  A=A*A;
                  tmp>>=1;
             }
             ans=ans*e;
             printf("%d\n",ans.mat[cities[v1]][cities[v2]]);
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
