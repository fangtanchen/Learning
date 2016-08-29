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
const int MAXN=110;
const int INF=0x7f7f7f7f;
int G[MAXN][MAXN];
int fa[MAXN];
int dist[MAXN];

bool vis[MAXN];
int N,Q;

void Init(){
    for(int i=1;i<MAXN;i++){
         fa[i]=i;
    }
    memset(vis,false,sizeof(vis));
    memset(dist,0x7f,sizeof(dist));
}

int Find(int x){
    if(fa[x]==x)return x;
    fa[x]=Find(fa[x]);
    return fa[x];
}

int Prim(){
    int rt=Find(1);
    vis[rt]=true;
    int ret=0;
    for(int i=1;i<=N;i++){
        int pa=Find(i);
        if(vis[pa])continue;
        dist[pa]=G[rt][pa];
    }
    do{
        int maxi=-1,maxv=INF;
        for(int i=1;i<=N;i++){
             int pa=Find(i);
             if(vis[pa])continue;
             if(dist[pa]<maxv){
                 maxi=pa;
                 maxv=dist[pa];
             }
        }
        if(-1==maxi)break;
        ret+=maxv;
        vis[maxi]=true;
        for(int i=1;i<=N;i++){
           int pa=Find(i) ;
           if(vis[pa])continue;
           if(G[maxi][pa]<dist[pa]){
               dist[pa]=G[maxi][pa];
           }
        }
    }while(1);
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    while(cin>>N){
        Init();
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                cin>>G[i][j];
            }
        }
        cin>>Q;
        while(Q--){
             int a,b;
             cin>>a>>b;
             int pa=Find(a),pb=Find(b);
             if((pa!=pb))fa[pa]=pb;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                int pa=Find(i),pb=Find(j);
                if((pa!=pb)&&(G[i][j]<G[pa][pb])){
                    G[pa][pb]=G[pb][pa]=G[i][j];
                }
            }
        }
        cout<<Prim()<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
