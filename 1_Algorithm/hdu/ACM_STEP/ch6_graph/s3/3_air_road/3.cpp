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
const int MAXN=2000;
const int MAXM=20010;

int N,M;
int top,first[MAXN],to[MAXM],adj[MAXM];
int mp[MAXN];
bool vis[MAXN];


void Init(){
    top=0;
    memset(first,-1,sizeof(first));
    memset(to,-1,sizeof(to));
    memset(adj,-1,sizeof(adj));
    memset(mp,-1,sizeof(mp));
    memset(vis,false,sizeof(vis));
}

void Add(int u,int v){
    to[top]=v;
    adj[top]=first[u];
     first[u]=top++;
}



int FindPath(int u){
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(vis[v])continue;
        vis[v]=true;
        if((mp[v]==-1)||FindPath(mp[v])){
            mp[u]=v;
            mp[v]=u;
            return 1;
        }
    }
    return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    while(T--){
        Init();
         scanf("%d%d",&N,&M);
         for(int mi=0;mi<M;mi++){
             int u,v;
             scanf("%d%d",&u,&v);
             Add(u,v+200);
             Add(v+200,u);
         }
         int ans=N;
         for(int i=1;i<=N;i++){
             if(mp[i]==-1){
                 memset(vis,false,sizeof(vis));
                 vis[i]=true;
                 ans-=FindPath(i);
             }
         }
         printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
