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
const int MAXN=1005;
double A[MAXN][MAXN],B[MAXN];
int value[MAXN];
int N,M;

int gcd(int x,int y){
    if(y==0)return x;
    else return gcd(y,x%y);
}

void Swap(double (*a)[MAXN],double *b,int ri,int rj){
    for(int ni=1;ni<=a[0][1];ni++){
        swap(a[ri][ni],a[rj][ni]);
    }
    b[ri]=b[rj];
}

void Solve(double (*a)[MAXN],double *b,int *val,int &_flag){
    //n,m are the rows and cols of a[][] respectively
    //val is the solution of the function
    //flag: -1 means no solution, 2 means many solutions, 1 means one solution
    _flag=1;
    int nrows=a[0][0],ncols=a[0][1];
    int topmax=min(nrows,ncols);
    bool Flag=false;
    for(int ri=1;ri<=topmax;ri++){
        Flag=false;
        for(int tmpri=ri;tmpri<=nrows;tmpri++){
            if(fabs(a[tmpri][ri])>1e-6){
                Flag=true;
                if(tmpri!=ri)Swap(a,b,tmpri,ri);
                break;
            }
        }
        if(Flag==false){
             _flag=2;
             continue;
        }
        for(int tmpri=ri+1;tmpri<=nrows;tmpri++){
            //int pp=a[tmpri][ri];
            for(int ci=ri+1;ci<=ncols;ci++){
                a[tmpri][ci]=a[tmpri][ci]-a[ri][ci]/a[ri][ri]*a[tmpri][ri];
                //a[tmpri][ci]=a[tmpri][ci]*a[ri][ri]/pp-a[ri][ci];
                //a[tmpri][ci]-=a[tmpri][ci]*a[ri][ri]/a[tmpri][ri];
                //a[tmpri][ci]=a[tmpri][ci]*a1-a[ri][ci]*a2;
                //a[tmpri][ci]=a[tmpri][ci]*a[ri][ri]-a[ri][ci]*a[tmpri][ri];
            }
            //b[tmpri]=b[tmpri]*a1-b[ri]*a2;
            b[tmpri]=b[tmpri]-b[ri]/a[ri][ri]*a[tmpri][ri];
            a[tmpri][ri]=0;
        }
    }
    for(int ri=1;ri<=nrows;ri++){
        bool Flag=false;
        for(int ci=1;ci<=ncols;ci++){
            if(fabs(a[ri][ci])>1e-6){
                Flag=true;
            }
        }
        if((!Flag)&&(fabs(b[ri])>1e-6)){
             _flag=-1;
             return;
        }
    }
    if(2==_flag){
         return;
    }
    for(int ri=topmax;ri>=1;ri--){
        for(int ci=ri+1;ci<=topmax;ci++) {
            b[ri]=b[ri]-a[ri][ci]*value[ci];
            a[ri][ci]=0;
        }
        value[ri]=b[ri]/a[ri][ri]+0.5;
        if(value[ri]<0){
            _flag=-1;
            return;
        }
    }


}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int nrows,ncols;
    scanf("%d%d",&ncols,&nrows);
    A[0][0]=nrows;A[0][1]=ncols;
    for(int mi=1;mi<=nrows;mi++){
        for(int ni=1;ni<=ncols;ni++){
            scanf("%lf",A[mi]+ni);
        }
        scanf("%lf",B+mi);
    }

    int flag;
    Solve(A,B,value,flag);
    if(flag==-1)printf("No solutions\n");
    else if(2==flag)printf("Many solutions\n");
    else {
        for(int i=1;i<=ncols;i++){
            printf("%d\n",(value[i]));
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
