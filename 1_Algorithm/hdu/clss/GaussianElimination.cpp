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

double A[MAXR][MAXC],B[MAXR];
int val[MAXC];

bool Zeros(double x){
    return fabs(x)<1e-6;
}

void Swap(double (*_a)[MAXC],double *_b,int ri,int rj){
    if(ri==rj)return;
    int ncols=_a[0][1];
    for(int ci=1;ci<=ncols;ci++){
        swap(_a[ri][ci],_a[rj][ci]);
    }
    swap(_b[ri],_b[rj]);
}

void Gaussian(double (*_a)[MAXC],double *_b,int *_val,int &_flag){
    int nrows=_a[0][0],ncols=_a[0][1];
    int rankle=min(nrows,ncols);
    for(int ri=1;ri<=rankle;ri++){
        bool flag=false;
        for(int tri=ri;tri<=nrows;tri++){
            if(!Zeros(_a[tri][ri])){
                 flag=true;
                 Swap(_a,_b,ri,tri);
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
            _b[tri]=_b[tri]-_b[ri]*tt;
        }
    }
    for(int ri=1;ri<=nrows;ri++){
        bool flag=false;
        for(int ci=1;ci<=ncols;ci++){
            if(!Zeros(_a[ri][ci])){
                flag=true;
            }
        }
        if((!flag)&&(!Zeros(_b[ri]))){
             _flag=-1;
             return;
        }
    }
    if(2==_flag){
        return;
    }
    _flag=1;
    for(int ri=rankle;ri>=1;ri--){
        for(int ci=ri+1;ci<=ncols;ci++){
            _b[ri]=_b[ri]-_a[ri][ci]*_val[ci];
            _a[ri][ci]=0;
        }
        _val[ri]=_b[ri]/_a[ri][ri]+0.5;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int nrows,ncols;
    scanf("%d%d",&ncols,&nrows);
    A[0][0]=nrows,A[0][1]=ncols;
    for(int ri=1;ri<=nrows;ri++){
        for(int ci=1;ci<=ncols;ci++){
            scanf("%lf",A[ri]+ci);
        }
        scanf("%lf",B+ri);
    }
    int flag=-1;
    Gaussian(A,B,val,flag);
    if(flag==-1){
        puts("No solutions");
    }else if(2==flag){
        puts("Many solutions");
    }else{
        for(int ci=1;ci<=ncols;ci++){
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
