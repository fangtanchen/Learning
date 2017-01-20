#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=128;
double M[MAXN][MAXN];
double p[MAXN];
int N,x;
double tmpp[MAXN],tmpmat[MAXN][MAXN];

void VecPMat(double *v,double (*mat)[MAXN],int num){
    memset(tmpp,0,sizeof(tmpp));
    for(int k=0;k<=num;k++){
        for(int i=0;i<=num;i++){
            tmpp[i]+=mat[i][k]*v[k];
        }
    }
    for(int i=0;i<=num;i++){
        v[i]=tmpp[i];
    }
}

void MatPMat(double (*mat1)[MAXN],double (*mat2)[MAXN],int num){
    memset(tmpmat,0,sizeof(tmpmat));
    for(int i=0;i<=num;i++){
        for(int k=0;k<=num;k++){
            for(int j=0;j<=num;j++){
                tmpmat[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    for(int i=0;i<=num;i++){
        for(int k=0;k<=num;k++){
            mat1[i][k]=tmpmat[i][k];
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&x);
    memset(M,0,sizeof(M));
    memset(p,0,sizeof(p));
    for(int ni=0;ni<=x;ni++){
         scanf("%lf",p+ni);
    }
    for(int i=0;i<MAXN;i++){
        for(int j=0;j<MAXN;j++){
            M[i][j]=p[i^j];
        }
    }
    int tmpN=N-1;
    while(tmpN){
         if(1&tmpN)VecPMat(p,M,MAXN-1);
         MatPMat(M,M,MAXN-1);
         tmpN>>=1;
    }
    printf("%.8lf\n",1-p[0]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
