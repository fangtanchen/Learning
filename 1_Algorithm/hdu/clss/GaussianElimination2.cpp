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
const int MAXR=1005;
const int MAXC=1005;

double A[MAXR][MAXC];
double *pA[MAXR];
int val[MAXC];

bool Zeros(double x){
    return fabs(x)<1e-6;
}


void Gaussian(double *_a[MAXC],int *_val,int &_flag){
    int nrows=_a[0][0],ncols=_a[0][1];
    int rankle=min(nrows,ncols-1);
    for(int ri=1;ri<=rankle;ri++){
        bool flag=false;
        for(int tri=ri;tri<=nrows;tri++){
            if(!Zeros(_a[tri][ri])){
                 flag=true;
                 swap(_a[ri],_a[tri]);
                 break;
            }
        }
        if(!flag){
             _flag=2;
             continue;
        }
        for(int tri=ri+1;tri<=nrows;tri++){
            double tt=_a[tri][ri]/_a[ri][ri];
            for(int ci=ri;ci<=ncols;ci++){
                _a[tri][ci]=_a[tri][ci]-_a[ri][ci]*tt;
            }
        }
    }
    for(int ri=1;ri<=nrows;ri++){
        bool flag=false;
        for(int ci=1;ci<ncols;ci++){
            if(!Zeros(_a[ri][ci])){
                flag=true;
            }
        }
        if((!flag)&&(!Zeros(_a[ri][ncols]))){
             _flag=-1;
             return;
        }
    }
    if(2==_flag){
        return;
    }
    _flag=1;
    for(int ri=rankle;ri>=1;ri--){
        for(int ci=ri+1;ci<ncols;ci++){
            _a[ri][ncols]=_a[ri][ncols]-_a[ri][ci]*_val[ci];
            _a[ri][ci]=0;
        }
        _val[ri]=_a[ri][ncols]/_a[ri][ri]+0.5;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int nrows,ncols;
    scanf("%d%d",&ncols,&nrows);
    ncols++;
    A[0][0]=nrows,A[0][1]=ncols;
    for(int ri=1;ri<=nrows;ri++){
        for(int ci=1;ci<=ncols;ci++){
            scanf("%lf",A[ri]+ci);
        }
        pA[ri]=A[ri];
    }
    pA[0]=A[0];
    int flag=-1;
    Gaussian(pA,val,flag);
    if(flag==-1){
        puts("No solutions");
    }else if(2==flag){
        puts("Many solutions");
    }else{
        for(int ci=1;ci<ncols;ci++){
            printf("%d\n",val[ci]);
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}