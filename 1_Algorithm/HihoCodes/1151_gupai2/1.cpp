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
const int MAXN=1e8+10;
const int MAXS=64;
const int MOD=12357;

int N;
int A[4][MAXS][MAXS],T[4][MAXS][MAXS];
int dp[2][MAXS];
int D[30][MAXS][MAXS];


void OutputMatrix(int a[][MAXS],int len=MAXS){
    printf("\n\n\nMatrix %d:\n",1);
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            cout<<a[i][j]<<" ";
        }
        printf("\n");
    }
}

void Init(){
    //j=0
    memset(A,0,sizeof(A));
    memset(T,0,sizeof(T));
    memset(dp,0,sizeof(dp));
    for(int j=0;j<3;j++){
        for(int si=0;si<MAXS;si++) {
            if(1==(si&(0x1<<j)))continue;
            if((0==(si&(0x1<<(j+1))))&&(j!=2)){
                A[j][si][si|(0x3<<j)]=1;
            }
            if((0==(si&(0x1<<(j+3))))){
                A[j][si][si|(0x1<<j)|(0x1<<(3+j))]=1;
            }
        }
    }
    for(int si=0;si<8;si++){
        A[3][(si<<3)|(0x7)][si]=1;
    }
    /*
    for(int ai=0;ai<3;ai++){
     //   printf("\n\nMatrix %d:\n",ai);
        int bi=ai+1;
        for(int i=0;i<MAXS;i++){
            for(int j=0;j<MAXS;j++){
      //          printf("%d ",A[ai][i][j]);
                for(int k=0;k<MAXS;k++){
                    T[ai][i][j]+=A[ai][i][k]*A[bi][k][j];
                }
            }
    //        printf("\n");
        }
    }
    */
    for(int i=0;i<MAXS;i++){
        for(int j=0;j<MAXS;j++){
            T[0][i][j]=A[0][i][j];
        }
    }
    for(int ai=1;ai<4;ai++){
        int bi=ai-1;
        for(int i=0;i<MAXS;i++){
            for(int j=0;j<MAXS;j++){
                for(int k=0;k<MAXS;k++){
                     T[ai][i][j]+=T[bi][i][k]*A[ai][k][j];
                     T[ai][i][j]%=MOD;
                }
            }
        }
    }
    OutputMatrix(T[3]);
    for(int i=0;i<MAXS;i++){
        for(int j=0;j<MAXS;j++){
            D[0][i][j]=T[3][i][j];
        }
    }
    for(int di=1;di<30;di++){
        for(int i=0;i<MAXS;i++){
            for(int j=0;j<MAXS;j++){
                for(int k=0;k<MAXS;k++){
                     D[di][i][j]+=D[di-1][i][k]*D[di-1][k][j];
                     D[di][i][j]%=MOD;
                }
            }
        }
        //OutputMatrix(D[di]);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    if(N%2)printf("0\n");
    else{
        Init();
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        OutputMatrix(A[0]);
        OutputMatrix(A[1]);
        OutputMatrix(A[2]);



        int klen=0;
        int k[30];
        int tmpN=N;
        while(tmpN){
            k[klen] =tmpN%2;
            tmpN/=2;
            klen++;
        }
        int si=0,di=1;
        for(int ki=0;ki<klen;ki++){
            if(k[ki]==0)continue;
            for(int j=0;j<MAXS;j++){
                for(int k=0;k<MAXS;k++){
                    dp[di][j]+=(dp[si][k]*D[ki][k][j]);
                    dp[di][j]%=MOD;
                }
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
