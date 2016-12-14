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

const int dir[5][2]={0,0,-1,0,1,0,0,-1,0,1};

int A[MAXN+5][MAXN+5];
int B[MAXN+5];
int val[MAXN+5];

void Swap(int (*a)[MAXN+5],int *b,int ri,int rj){
    if(ri==rj)return;
    for(int ci=1;ci<=MAXN;ci++){
        swap(a[ri][ci],a[rj][ci]);
    }
    swap(b[ri],b[rj]);
}

void Print(int (*a)[35]){
    for(int ri=1;ri<=MAXN;ri++){
        for(int ci=1;ci<=MAXN;ci++){
            printf("%d ",a[ri][ci]);
        }
        printf("%d",B[ri]);
        printf("\n");
    }
}

void Solve(int (*_a)[MAXN+5],int *_b,int *_val,int _flag){
    for(int ri=1;ri<=MAXN;ri++){
        bool Flag=false;
        for(int tmpri=ri;tmpri<=MAXN;tmpri++){
            if(_a[tmpri][ri]!=0){
                Flag=true;
                Swap(_a,_b,ri,tmpri);
                break;
            }
        }
        if(!Flag){
             _flag=2;
             continue;
        }
        for(int tmpri=ri+1;tmpri<=MAXN;tmpri++){
            if(_a[tmpri][ri]==0)continue;
            for(int ci=ri;ci<=MAXN;ci++){
                _a[tmpri][ci]^=_a[ri][ci];
            }
            _b[tmpri]^=_b[ri];
        }
    }
    for(int ri=1;ri<=MAXN;ri++){
        bool Flag=false;
        for(int ci=1;ci<=MAXN;ci++){
            if(_a[ri][ci]!=0){
                Flag=true;
            }
        }
        if((!Flag)&&(_b[ri]!=0)){
             _flag=-1;
             return;
        }
    }
    if(_flag==2){
         return;
    }
    for(int ri=MAXN;ri>=1;ri--){
        for(int ci=ri+1;ci<=MAXN;ci++){
            _b[ri]^=_val[ci]*_a[ri][ci];
        }
        _val[ri]=_b[ri];
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        for(int i=1;i<=MAXN;i++){
             scanf("%1d",B+i);
             B[i]^=1;
        }
        memset(A,0,sizeof(A));
        for(int ri=1;ri<=5;ri++){
            for(int ci=1;ci<=6;ci++){
                for(int di=0;di<5;di++){
                    int tmpri=ri+dir[di][0];
                    int tmpci=ci+dir[di][1];
                    if(tmpri<1||tmpri>5||tmpci<1||tmpci>6)continue;// important

                    int tmpid=6*tmpri+tmpci-6;
                    int id=6*ri+ci-6;
                    A[tmpid][id]=1;
                };
            }
        }
        int flag;
        Solve(A,B,val,flag);
        int len=0;
        for(int i=1;i<=MAXN;i++){
            len+=val[i];
        }
        printf("%d\n",len);
        for(int ri=1;ri<=5;ri++){
            for(int ci=1;ci<=6;ci++){
                int tmp=ri*6+ci-6;
                if(val[tmp]){
                     printf("%d %d\n",ri,ci);
                }
            }
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
