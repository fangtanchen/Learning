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
int N;
int ans;

void DFS(int ri,int ci){
    if(N-ri+1<=ans||N-ci+1<=ans)return;
    int tmp=0;
    bool flag=true;
    for(tmp=0;(ri+tmp)<=N &&(ci+tmp<=N);tmp++){
        int rmax=ri+tmp,cmax=ci+tmp;
        for(int i=1;i<=rmax;i++){
            if((A[i][cmax]!=A[i-1][cmax]+1 )
                    ||(A[i][cmax]!=A[i][cmax-1]+1)){
                flag=false;
            }
        }
        for(int i=1;i<=cmax;i++){
            if((A[rmax][i]!=A[rmax-1][i]+1 )
                    ||(A[rmax][i]!=A[rmax][i-1]+1)){
                flag=false;
            }
        }
        if(!flag)break;
    }
    tmp--;
    ans=max(ans,tmp+1);
    DFS(ri+tmp+1,ci);
    DFS(ri,ci+tmp+1);
}

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
    ans=1;
    DFS(1,1);
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
