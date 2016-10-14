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
#define MAXN 1010
#define MAXM 10
#define MAXS 1050
const int  MODN=(1e+9)+7;

int N,M;
int ans[MAXN][MAXM][MAXS];

void  Init(){
     memset(ans,0,sizeof(ans));
}

void Solve(){
    int bitarr[16] ;
    bitarr[1]=1;
    for(int i=2;i<16;i++){
         bitarr[i]=2*bitarr[i-1];
    }
    int maxs=1<<(2*M);
    int maxp=1<<M;
    for(int i=N;i>=1;i--){
        for(int j=M;j>=1;j--){
            for(int s=maxs-1;s>=0;s--){
                if((s&bitarr[j])){
                    if(M==j){
                         if (N==i)ans[i][j][s]=1;
                         else ans[i][j][s]=ans[i+1][1][s/maxp];
                    }else{
                        ans[i][j][s]=ans[i][j+1][s];
                    }
                }else{
                    if((j<M)&&(0==(s&bitarr[j+1]))){
                            ans[i][j][s]+=ans[i][j][s+bitarr[j]+bitarr[j+1]];
                            ans[i][j][s]%=MODN;
                    }
                    if((i<N)&&(0==(s&bitarr[j+M]))){
                        ans[i][j][s]+=ans[i][j][s+bitarr[j]+bitarr[j+M]];
                        ans[i][j][s]%=MODN;
                    }
                }
            }
        }
    }

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);
    Solve();
    printf("%d\n",ans[1][1][0]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
