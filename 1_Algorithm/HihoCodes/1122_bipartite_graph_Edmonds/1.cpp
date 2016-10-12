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
const int MAXN=1010;
const int MAXM=5010;

int N,M;
bool vis[MAXN];
vector<int> G[MAXN];
int partern[MAXN];

void Init(){
     memset(partern,-1,sizeof(partern));
     for(int i=0;i<MAXN;i++){
         G[i].clear();
     }
}

bool FindPath(int u){
    vis[u]=true;
    for(int i=G[u].size()-1;i>=0;i--){
        int v=G[u][i];
        if(vis[v])continue;
        vis[v]=true;
        if(-1==partern[v]||FindPath(partern[v])){
            partern[u]=v;
            partern[v]=u;
            return true;
        }
    }
    return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    Init();
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=1;i<=N;i++){
        if(-1==partern[i]){
            memset(vis,false,sizeof(vis));
            FindPath(i);
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        if(partern[i]!=-1){
            ans++;
        }
    }
    cout<<ans/2<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
