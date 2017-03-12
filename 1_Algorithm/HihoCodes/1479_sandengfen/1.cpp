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
const int MAXN=1e5+10;

int T,N;
vector<int> G[MAXN];
int pa[MAXN],w[MAXN];


void BFS(int rt){
    for(int i=0;i<G[rt].size();i++){
        int child=G[rt][i];
        BFS(child);
        w[rt]+=w[child];
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         scanf("%d",&N);
         int sum=0;
         w[0]=0;
         for(int i=1;i<=N;i++){
             scanf("%d%d",w+i,pa+i);
             G[pa[i]].push_back(i);
             sum+=w[i];
         }
         if(0!=ans%3){
              printf("0\n");
              continue;
         }
         sum/=3;
         BFS(0);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
