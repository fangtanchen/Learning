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
const int MAXM=10010;

int first[MAXN];
int to[MAXM];
int adj[MAXM];
int top;

int N,M;
bool vis[MAXN];
int match[MAXN];
int tag[MAXN];

void Init(){
     memset(first,-1,sizeof(first));
     memset(to,-1,sizeof(to));
     memset(adj,-1,sizeof(adj));
     memset(vis,false,sizeof(vis));
     memset(match,-1,sizeof(match));
     memset(tag,-1,sizeof(tag));
     top=0;
}

void Add(int u,int v){
     adj[top]=first[u];
     first[u]=top;
     to[top]=v;
     top++;
}

void DFS_tag(int u){
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(-1==tag[v]){
            tag[v]=1-tag[u];
            DFS_tag(v);
        }
    }
}

bool FindPath(int u){
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(vis[v])continue;
        vis[v]=true;
        if((-1==match[v])||(FindPath(match[v]))){
            match[u]=v;
            match[v]=u;
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
    cin>>N>>M;
    Init();
    for(int i=0;i<M;i++){
         int a,b;
         cin>>a>>b;
         Add(a,b);
         Add(b,a);
    }
    for(int i=1;i<=N;i++){
        if(-1==tag[i]){
            tag[i]=0;
            DFS_tag(i);
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        if(1==(tag[i])&&(-1==match[i])){
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
