#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef pair<int,int >  pii;
const int MAXN=100010;
int N;
int w[2*MAXN];
int rec[MAXN][20];
vector<int> G[2*MAXN];
vector<pii> len;
int pa[20][MAXN];
int in[2*MAXN];
int ans[MAXN];

void Init(){
    memset(rec,-1,sizeof(rec));
    memset(in,0,sizeof(in));
    for(int i=2*MAXN-1;i>=0;i--){
         G[i].clear();
    }
    memset(pa,0,sizeof(pa));
    memset(ans,0,sizeof(ans));
}


void PostOrder(int u,int fa){
    if(G[u].size()==0){
        return;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=1;i<N;i++){
         int A,B;
         scanf("%d%d",&A,&B);
         if(A>B)swap(A,B);
         G[A].push_back(B);
         pa[0][B]=A;
         in[B]++;
    }
    for(int i=1;i<20;i++){
        for(int j=1;j<=N;j++){
            pa[i][j]=pa[i-1][pa[i-1][j]];
        }
    }
    for(int i=1;i<=N;i++){
         scanf("%d",w+i);
    }
    PostOrder(1,0);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
