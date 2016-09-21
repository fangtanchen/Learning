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
int tag[MAXN];
int match[MAXN];

void Init(){
     memset(first,-1,sizeof(first));
     memset(to,-1,sizeof(to));
     memset(adj,-1,sizeof(adj));
     memset(vis,false,sizeof(vis));
     memset(tag,-1,sizeof(tag));
     memset(match,-1,sizeof(match));
     top=0;
}


void Add(int u,int v){
     adj[top]=first[u];
     to[top]=v;
     first[u]=top++;
}

void DFS_tag(int u){
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(tag[v]==-1){
            tag[v]=1-tag[u];
            DFS_tag(v);
        }
    }
}
int FindPath(int u){
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(vis[v])continue;
        vis[v]=true;
        if((-1==match[v])||(FindPath(match[v]))){
             match[v]=u;
             match[u]=v;
             return 1;
        }
    }
    return 0;
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
         Add(a,b);
         Add(b,a);
    }

    for(int i=1;i<=N;i++){
        if(tag[i]==-1){
            tag[i]=0;
            DFS_tag(i);
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        if((0==tag[i])&&(match[i]==-1)){
            memset(vis,false,sizeof(vis));
            vis[i]=true;
            ans+=FindPath(i);
        }
    }
    cout<<ans<<endl;
    cout<<N-ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
