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
const int MAXN=30;
const int MAXR=5;
const int MAXC=6;
const int dir[5][2]={0,0,0,1,0,-1,1,0,-1,0};

int A[MAXN+10][MAXN+10];
int B[MAXN+10];
int *pA[MAXN+10];
int px[MAXN*10],py[MAXN*10],plen;
int val[MAXN+10];

int pt2int(int ri,int ci){
    return ri*MAXC+ci-MAXC;
}

void Gaussian(int *_a[MAXN+10],int *_b,int *_val){
    int nrows=30,ncols=30;
    int rankle=min(nrows,ncols);
    for(int ri=1;ri<=rankle;ri++){
        bool flag=false;
        for(int tri=ri;tri<=nrows;tri++){
            if(_a[tri][ri]!=0){
                flag=true;
                swap(_a[tri],_a[ri]);
                swap(_b[tri],_b[ri]);
                break;
            }
        }
        if(!flag){
            continue;
        }
        for(int tri=ri+1;tri<=nrows;tri++){
            if(_a[tri][ri]==0)continue;
            for(int ci=ri;ci<=ncols;ci++){
                _a[tri][ci]^=_a[ri][ci];
            }
            _b[tri]^=_b[ri];
        }
    }
    plen=0;
    for(int ri=rankle;ri>=1;ri--){
        for(int ci=ri+1;ci<=ncols;ci++){
            _b[ri]^=_a[ri][ci]*_val[ci];
        }
        _val[ri]=_b[ri];
        if(_val[ri]){
            plen++;
        };
    }
    printf("%d\n",plen);
    for(int ri=1;ri<=MAXR;ri++){
        for(int ci=1;ci<=MAXC;ci++){
            int id=pt2int(ri,ci);
            if(_val[id]){
                printf("%d %d\n",ri,ci);
            }
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        for(int ri=1;ri<=MAXR;ri++){
            for(int ci=1;ci<=MAXC;ci++){
                int id=pt2int(ri,ci);
                scanf("%1d",B+id);
                B[id]^=1;
            }
        }
        memset(A,0,sizeof(A));
        for(int ri=1;ri<=MAXR;ri++){
            for(int ci=1;ci<=MAXC;ci++){
                int id=pt2int(ri,ci);
                for(int di=0;di<5;di++){
                    int tri=ri+dir[di][0];
                    int tci=ci+dir[di][1];
                    if(tri<1||tri>MAXR||tci<1||tci>MAXC)continue;
                    A[pt2int(ri,ci)][pt2int(tri,tci)]=1;
                }
                pA[id]=A[id];
            }
        }
        Gaussian(pA,B,val);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
