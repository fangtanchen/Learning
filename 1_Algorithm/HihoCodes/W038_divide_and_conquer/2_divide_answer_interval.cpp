#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<queue>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=10010;
const int MAXM=2e5+10;
const int INF=0x7f7f7f7f;

int first[MAXN];
int to[MAXM];
int adj[MAXM];
int dist[MAXM];
int top;

int N,M,K,T;
bool vis[MAXN];
int result;
int depth[MAXN];
queue<int> qe;

void Init(){
     memset(first,-1,sizeof(first));
     memset(to,-1,sizeof(to));
     memset(adj,-1,sizeof(adj));
     memset(dist,0x7f,sizeof(dist));
     top=0;

     result=INF;
     memset(vis,false,sizeof(vis));
     memset(depth,0,sizeof(depth));
}

void Add(int u,int v,int d){
     adj[top]=first[u];
     to[top]=v;
     dist[top]=d;
     first[u]=top++;
}

bool BFS(int u,int dest,int cost,int depth){
    while(!qe.empty()){
         qe.pop();
    }
}

int BinarySearch(){
    int left=1;
    int right=INF;
    int ret=-1;
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        memset(depth,0,sizeof(depth));
        if(BFS(1,T,mid,depth)){
             ret=mid;
             right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    Init();
    cin>>N>>M>>K>>T;
    for(int i=0;i<M;i++){
         int u,v,w;
         cin>>u>>v>>w;
         Add(u,v,w);
         Add(v,u,w);
    }


    cout<<BinarySearch()<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
