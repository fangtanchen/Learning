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
typedef long long int LL;
const int MAXN=4005;

LL dp[2][MAXN];
int si,di;
int w[MAXN],c[MAXN];
int maxw,N,S;

void DFS(int L,int R){
    if(R<=3000){
        swap(si,di);
        memset(dp[di],0,sizeof(dp[di]));
        for(int i=0;i+L<=R;i++){
            dp[di][i]=dp[si][i+L];
        }
        return;
    }

    int l=max((L-maxw)/2,0);
    int r=(R+maxw)/2;
    DFS(l,r);
    swap(si,di);
    memset(dp[di],0,sizeof(dp[di]));
    for(int i=0;i+l<=r;i++){
        for(int j=i;j+l<=r;j++){
            int tmp=i+l+j+l;
            if(tmp<L)continue;
            if(tmp>R)break;
            dp[di][tmp-L]=max(dp[di][tmp-L],dp[si][i]+dp[si][j]);
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&S);
    maxw=0;
    for(int i=0;i<N;i++){
        scanf("%d%d",w+i,c+i);
        maxw=max(maxw,w[i]);
    }
    si=0;di=1;
    for(int i=0;i<N;i++){
        for(int j=w[i];j<=3000;j++){
            dp[di][j]=max(dp[di][j],dp[di][j-w[i]]+c[i]);
        }
    }
    DFS(S,S);
    printf("%lld\n",dp[di][0]);



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
