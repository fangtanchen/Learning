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
const int MAXN=1e5+10;

int pa[MAXN],k[MAXN];
int depth[MAXN],out[MAXN];
int N;
vector<int> G[MAXN];
bool vis[MAXN];


void DFS(int u,int fa,int di){
    depth[u]=di;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        DFS(v,u,di+1);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    memset(out,0,sizeof(out));
    memset(depth,0,sizeof(depth));
    memset(vis,false,sizeof(vis));
    pa[1]=0;
    for(int i=2;i<=N;i++){
         scanf("%d",pa+i);
         out[pa[i]]++;
         G[pa[i]].push_back(i);
    }
    for(int i=1;i<=N;i++){
        scanf("%d",k+i);
    }
    DFS(1,0,1);
    depth[0]=-10000000;
    int ans=0;
    bool flag=true;
    for(int i=1;i<=N;i++){
        if(!out[i]){
            int u=i;
            int kk=0x3f3f3f3f;
            while(u>1&&!vis[u]){
                ans++;
                int tmp=min(kk,depth[u]-k[u]);
                while(depth[u]>tmp&&(!vis[u])){
                     vis[u]=true;
                     kk=min(depth[u]-k[u],kk);
                     u=pa[u];
                }
            }
        }
    }
    cout<<ans+!vis[1]<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
