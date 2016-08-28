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
const int MAXN=105;
const int INF=0x7f7f7f7f;
int map[MAXN][MAXN];
bool vis[MAXN];
int dist[MAXN];
int fa[MAXN];
int N;

void Init(){
    memset(dist,0x7f,sizeof(dist));
     memset(vis,false,sizeof(vis));
     for(int i=1;i<MAXN;i++){
         fa[i]=i;
     }
}

int Find(int x){
    if(x==fa[x])return x;
    fa[x]=Find(fa[x]);
    return fa[x];
}

int Prim(){
    int rt=Find(1);
    vis[rt]=true;
    for(int i=1;i<=N;i++){
        int fi=Find(i);
        if(vis[fi])continue;
        dist[fi]=map[rt][fi];
    }
    int ret=0;
    do{
        int maxi=-1;
        int maxv=INF;
        for(int i=1;i<=N;i++){
            int fi=Find(i);
            if(vis[fi])continue;
            if(dist[fi]<maxv){
                 maxi=fi;
                 maxv=dist[fi];
            }
        }
        if(-1==maxi)break;
        ret+=maxv;
        vis[maxi]=true;
        for(int i=1;i<=N;i++){
             int fi=Find(i);
             if(vis[fi])continue;
             if(map[maxi][fi]<dist[fi]){
                 dist[fi]=map[maxi][fi];
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
    while(cin>>N,N){
        Init();
        for(int i=N*(N-1)/2;i>0;i--){
            int a,b,l,s;
            cin>>a>>b>>l>>s;
            map[a][b]=map[b][a]=l;
            if(s==1){
                int pa=Find(a),pb=Find(b);
                if(pa!=pb){
                    fa[pa]=pb;
                }
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                int pa=Find(i),pb=Find(j);
                if((pa!=pb)&&(map[i][j]<map[pa][pb])){
                    map[pa][pb]=map[pb][pa]=map[i][j];
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
