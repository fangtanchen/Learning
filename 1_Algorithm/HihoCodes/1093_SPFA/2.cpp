#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;
const int MAXM=1e6+10;
const int INF=1e9+10;
class Node{
    public:
    int di;
    int len;
    Node(){
        di=0;len=0;
    }
};
struct Queue1{
    public:
        Node nodes[MAXN];
        int len;
        int top,tail;
        Queue1(){
            len=0;top=0;tail=-1;
        }
        bool Empty(){
            return len==0;
        }
        Node Top(){
             return nodes[top];
        }
        void Pop(){
            int tmp=(tail+1-top)%MAXN;
            if(tmp==0)return;
            top=(top+1)%MAXN;
            len--;
        }
        void Push(int i,int j){
            int tmp=(tail-top+2)%MAXN;
            if(tmp==0)return;
            tail=(tail+1)%MAXN;
             nodes[tail].di=i;
             nodes[tail].len=j;
            len++;
        }
}que;



map< pair<int,int>,int > mp;
vector<int> G[MAXN];
int dis[MAXN];
int inq[MAXN];
int N,M,S,T;

void Init(){
    memset(dis,0x5f,sizeof(dis));
    for(int i=1;i<=N;i++){
        G[i].clear();
    }
    mp.clear();
    memset(inq,-1,sizeof(inq));
}

int BFS(int s,int t){
    que.Push(s,0);
    inq[s]=que.tail;
    while(!que.Empty()){
         Node pos=que.Top();
         que.Pop();
         int ni=pos.di,len=pos.len;
         inq[ni]=-1;
         if(len<dis[ni])dis[ni]=len;
         for(int i=G[ni].size()-1;i>=0;i--){
              int child=G[ni][i];
              int tmplen=len+mp[make_pair(ni,child)];
              if(inq[child]==-1){
                  if(dis[child]>tmplen){
                  que.Push(child,tmplen);
                  inq[child]=que.tail;
                }
              }else{
                  Node  *tp=&que.nodes[inq[child]];
                  if(tmplen<tp->len)tp->len=tmplen;
              }
         }
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M>>S>>T;
    Init();
    dis[S]=0;
    map<pair<int,int>,int>::iterator it;
    for(int i=0;i<M;i++){
         int u,v,len;
         cin>>u>>v>>len;
         it=mp.find(make_pair(u,v));
         if((it==mp.end())||((it->second)>len)){
            mp[make_pair(u,v)]=len;
            mp[make_pair(v,u)]=len;
            if(it==mp.end()){
                G[u].push_back(v);
                G[v].push_back(u);
            }
         }
    }
    BFS(S,T);
    cout<<dis[T]<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;

}
