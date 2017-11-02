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
const int MAXN=1005;

vector<int> G[MAXN];
int N,K;
int pa[MAXN];
bool vis[MAXN];

void DFS(int rt){
    if(vis[rt])return;
    vis[rt]=true;
    for(int i=0;i<G[rt].size();i++){
        int v=G[rt][i];
        if(vis[v])continue;
        pa[v]=rt;
        DFS(v);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>K;
    for(int i=1;i<N;i++){
         int a,b;
         cin>>a>>b;
         G[a].push_back(b);
         G[b].push_back(a);
    }
    pa[K]=0;
    DFS(K);

    cout<<pa[1];
    for(int i=2;i<=N;i++){
         cout<<" "<<pa[i];
    }
    cout<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
