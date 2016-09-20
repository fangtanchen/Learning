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
const int MAXN=1010;
const int MAXM=5010;

int N,M;
int first[MAXN];
int adj[MAXM];
int to[MAXM];
bool vis[MAXN];
int match[MAXN];
int top;
int tags[MAXN];

void Init(){
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(to,-1,sizeof(to));
    memset(match,-1,sizeof(match));
    memset(tags,-1,sizeof(tags));
    top=0;
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
        if(match[v]==-1||FindPath(match[v])){
            match[u]=v;
            match[v]=u;
            return true;
        }
    }
    return false;
}

void DFS_tags(int u){
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(tags[v]==-1){
            tags[v]=1-tags[u];
            DFS_tags(v);
        }
    }

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    cin.sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<M;i++){
         int a,b;
         cin>>a>>b;
         Add(a,b);
         Add(b,a);
    }
    for(int i=1;i<=N;i++){
        if(tags[i]==-1){
            tags[i]=0;
            DFS_tags(i);
        }
    }

    int ans=0;
    for(int i=1;i<=N;i++){
        if((0==tags[i])&&(-1==match[i])){
            memset(vis,false,sizeof(vis));
            vis[i]=true;
            ans+=FindPath(i);
        }
    }
    cout<<ans<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
