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
const int MAXN=505;
const int MODU=1e9+7;
typedef long long int ll;

ll C[MAXN][MAXN];
ll trans[MAXN][MAXN],tmptrans[MAXN][MAXN];
ll v[MAXN],tmpv[MAXN];


ll VecPMat(ll *vec,ll (*mat)[MAXN],int nrows){
    memset(tmpv,0,sizeof(tmpv));
    for(int j=0;j<=nrows;j++){
        if(vec[j]==0)continue;
        for(int k=0;k<=nrows;k++){
            tmpv[k]=tmpv[k]+vec[j]*mat[j][k];
            tmpv[k]%=MODU;
        }
    }
    for(int j=0;j<=nrows;j++){
        vec[j]=tmpv[j];
    }
    return 0;
}

ll MatPMat(ll (*mat)[MAXN],int nrows){
    memset(tmptrans,0,sizeof(tmptrans));
    for(int i=0;i<=nrows;i++){
        for(int k=0;k<=nrows;k++){
            if(mat[i][k]==0)continue;
            for(int j=0;j<=nrows;j++){
                if(mat[k][j]==0)continue;
                tmptrans[i][j]+=(mat[i][k]*mat[k][j]);
                tmptrans[i][j]%=MODU;
            }
        }
    }
    for(int i=0;i<=nrows;i++){
        for(int j=0;j<=nrows;j++){
            mat[i][j]=tmptrans[i][j];
        }
    }
    return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    memset(C,0,sizeof(C));
    C[0][0]=1;
    for(int i=1;i<MAXN;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MODU;
        }
    }
    /*
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            printf("%lld ",C[i][j]);
        }
        printf("\n");
    }
        printf("\n\n\n");
        */
    while(T--){
        int N,a,r;
        scanf("%d%d%d",&N,&a,&r);
        memset(trans,0,sizeof(trans));
        for(int i=0;i<=r;i++){
            for(int j=0;j<=r;j++){
                trans[j][i]=(C[i][j]*a)%MODU;//transpose ,important in order
            }
            trans[r+1][i]=1;
        }
        trans[r+1][r+1]=1;
        int tmpN=N;
        for(int i=r+1;i>=0;i--){
            v[i]=a;
        }
        tmpN-=1;
        while(tmpN){
            if(tmpN&0x01){
                VecPMat(v,trans,r+1);
            }
             tmpN>>=1;
             MatPMat(trans,r+1);
        }
        printf("%lld\n",v[r]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
