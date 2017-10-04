#include<iostream>
#include<queue>
#include<vector>


using namespace std;
typedef pair<int,int> pii;

const int MAXN=55;
const int MAXL=110;


vector<int> G[MAXN];
int pa[MAXN],cnt[MAXN];
int N,L;
bool vis[MAXN];


int DFS(int &L,int u,int &ans){
    if(L==0){
        return 0;
    }
    if(!vis[u]){
        ans++;
        vis[u]=true;
    }
    priority_queue<pii,vector<pii>,less<pii> > Q;
    for(int i=0;i<G[u].size();i++){
        Q.push(make_pair(cnt[G[u][i]],G[u][i]));
    }
    /*
    while(!Q.empty()){
        pii u=Q.top();
        Q.pop();
        cout<<u.first<<" "<<u.second<<endl;
    }*/
    while(!Q.empty()){
        pii t=Q.top();
        Q.pop();
        L--;
        DFS(L,t.second,ans);
        L--;
        if(L==0)return 0;
    }
    return 0;
}

int main(){
    cin>>N>>L;
    pa[0]=0;
    for(int i=1;i<N;i++){
        cin>>pa[i];
        G[pa[i]].push_back(i);
    }
    memset(cnt,0,sizeof(cnt));
    memset(vis,false,sizeof(vis));
    for(int i=0;i<N;i++){
        int u=i;
        while(u){
            cnt[u]++;
            u=pa[u];
        }
        cnt[0]++;
    }
    //for(int i=0;i<N;i++)cout<<cnt[i]<<endl;
    int ans=0;
    DFS(L,0,ans);
    cout<<ans+1<<endl;

    return 0;
}

