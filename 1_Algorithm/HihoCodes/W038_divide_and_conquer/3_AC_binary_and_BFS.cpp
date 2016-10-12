#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=10010;
const int MAXM=200010;
const int INF=0x7f7f7f7f;

int first[MAXN];
int to[MAXM];
int dist[MAXM];
int adj[MAXM];
int top;

int depth[MAXN];
int sim[MAXN];
bool inq[MAXN];
queue<int> qe;


int N,M,K,T;

void Init(){
    memset(first,-1,sizeof(first));
    memset(to,-1,sizeof(to));
    memset(dist,INF,sizeof(dist));
    memset(adj,-1,sizeof(adj));
    top=0;
}

void Add(int u,int v,int w){
    adj[top]=first[u];
    to[top]=v;
    dist[top]=w;
    first[u]=top++;
}

bool BFS(int S,int T,int K,int cost){
    while(!qe.empty()){
         qe.pop();
    }
    memset(depth,0x7f,sizeof(depth));
    memset(sim,0x7f,sizeof(sim));
    memset(inq,false,sizeof(inq));
    qe.push(S);
    depth[S]=0;
    sim[S]=0;
    inq[S]=true;
    while(!qe.empty()){
        int u=qe.front();
        qe.pop();
        inq[u]=false;

        if(depth[u]>K)continue;
        if((u==T)&&(sim[u]<=cost))return true;

        for(int pos=first[u];pos!=-1;pos=adj[pos]){
            int v=to[pos];
            int w=dist[pos];

            int tempdepth=depth[u]+1;
            int tempv=max(sim[u],w);
            if((depth[v]>tempdepth)&&(tempv<=cost)){
                 depth[v]=tempdepth;
                 sim[v]=tempv;
                 if(!inq[v]){
                    qe.push(v);
                }
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
    cin.sync_with_stdio(false);
    Init();
    cin>>N>>M>>K>>T;
    for(int i=0;i<M;i++){
         int u,v,w;
         cin>>u>>v>>w;
         Add(u,v,w);
         Add(v,u,w);
    }

    int left=0,right=1e6;
    int mid;
    while(left+1<right){
         mid=(left+right)/2;
         if(BFS(1,T,K,mid)){
             right=mid;
         }else{
             left=mid;
         }
    }
    cout<<right<<endl;



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
