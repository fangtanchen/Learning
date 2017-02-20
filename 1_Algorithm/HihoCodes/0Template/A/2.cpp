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
const int MAXN=1005;

int A[MAXN][MAXN];
int B[MAXN][MAXN];
int N;
int ans;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int ri=1;ri<=N;ri++){
        for(int ci=1;ci<=N;ci++){
            scanf("%d",A[ri]+ci);
        }
    }
    for(int i=1;i<=N;i++){
         A[i][0]=A[i][1]-1;
         A[0][i]=A[1][i]-1;
    }
    for(int ri=N;ri;ri--){
        B[ri][N]=1;
        for(int ci=N-1;ci;ci--){
            if(A[ri][ci]+1==A[ri][ci+1]){
                B[ri][ci]=B[ri][ci+1]+1;
            }else{
                 B[ri][ci]=1;
            }
        }
    }
    ans=1;
    for(int ri=1;ri<=N;ri++){
        for(int ci=1;ci<=N;){
            int kk=B[ri][ci];
            if(kk<=ans){
                ci+=kk;
                continue;
            }
            int rmax=ri+kk-1;
            if(rmax>N){
                ci+=kk;
                continue;
            }
            bool flag=true;
            for(int tmpri=ri+1;tmpri<=rmax;tmpri++){
                if(A[tmpri][ci]!=A[tmpri-1][ci]+1){
                    kk=tmpri-ri;
                    flag=false;
                    break;
                }
                if(B[tmpri][ci]>=kk) continue;
                kk=B[tmpri][ci];
                rmax=ri+kk-1;
                if(kk<=ans){
                     flag=false;
                     break;
                }
            }
            ci+=B[ri][ci];
            ans=max(ans,kk);
        }
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
