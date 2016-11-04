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
const int MAXN=200;

int mp[MAXN][MAXN];
int cx[MAXN],cy[MAXN];
bool vis[MAXN];
int N,M,K;

void Init(){
    memset(mp,0,sizeof(mp));
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));

}

bool Path(int u){
    for(int v=0;v<M;v++){
        if(mp[u][v]&&(!vis[v])){
            vis[v]=true;
            if(cy[v]==-1||Path(cy[v])){
                cx[u]=v;
                cy[v]=u;
                return true;
            }
        }
    }
    return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while((3==scanf("%d%d%d",&N,&M,&K))&&N){
             Init();
             for(int ki=0;ki<K;ki++){
                 int i,x,y;
                 scanf("%d%d%d",&i,&x,&y);
                 if(x==0||y==0)continue;
                 mp[x][y]=1;
             }
             int ans=0;
             for(int i=0;i<N;i++){
                 if(cx[i]==-1){
                     memset(vis,false,sizeof(vis));
                     if(Path(i))ans++;
                 }
             }
             printf("%d\n",ans);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
