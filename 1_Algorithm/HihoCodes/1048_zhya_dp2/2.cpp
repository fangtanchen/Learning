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
#define MODN 1000000007
#define MAXN 1010
#define MAXM 7
#define MAXS 1025

int N,M;
int ans[MAXN][MAXM][MAXS];

void init(){
    memset(ans,0,sizeof(ans));
}


void solve(){

    int bitarr[15];

    bitarr[1]=0x01;
    for(int i=1;i<15;i++){
        bitarr[i+1]=bitarr[i]<<1;
    }
    int maxs=1<<(2*M);
    maxs--;
    int maxp=1<<M;
    ans[N][M-1][maxs-1-]

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int s=0;s<maxs;s++){
                if(bitarr[j]&s){
                    if(M==j){
                        ans[i][j][s]=ans[i+1][1][s/maxp];
                    }
                    if(j<M){
                        ans[i][j][s]=ans[i][j+1][s];
                    }
                }else{
                    if((bitarr[j+1]==0)&&(j<M)){
                        ans[i][j][s]+=ans[i][j][s+bitarr[j]+bitarr[j+1]];
                        ans[i][j][s]%=MODN;
                    }
                    if((bitarr[j+M]==0)&&(i<N)){
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
    init();
    scanf("%d%d",&N,&M);
    solve();
    printf("%d\n",ans[1][1][0]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
