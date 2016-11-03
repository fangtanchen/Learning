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
const int MAXN=3030;
const int MAXK=1010;

int N,M,K;
int top,first[MAXN],adj[2*MAXN],to[2*MAXN];
int tag[MAXN];
bool vis[MAXN];
int mp[MAXN];

void Init(){
    top=0;
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(to,-1,sizeof(to));
    memset(tag,0,sizeof(tag));
    memset(vis,false,sizeof(vis));
    memset(mp,-1,sizeof(mp));
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}

bool FindPath(int u){
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(vis[v])continue;
        vis[v]=true;
        if((mp[v]==-1)||FindPath(mp[v])){
            mp[u]=v;
            mp[v]=u;
            return true;
        }
    }
    return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&N),N){
            Init();
             scanf("%d%d",&M,&K);
             int add1=K,add2=K+N;
             for(int ki=0;ki<K;ki++){
                 int i,x,y;
                 scanf("%d%d%d",&i,&x,&y);
                 x+=add1;y+=add2;
                 Add(i,x);
                 Add(i,y);
                 Add(x,i);
                 Add(y,i);
             }
             int imax=K+M+N;
             for(int i=K;i<imax;i++){
                  tag[i]=1;
             }
             int ans=0;
             for(int i=K;i<imax;i++){
                 if(mp[i]==-1){
                     memset(vis,false,sizeof(vis));
                     vis[i]=true;
                     if(FindPath(i))ans++;
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
