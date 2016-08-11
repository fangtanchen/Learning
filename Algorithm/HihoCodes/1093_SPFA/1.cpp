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

map< pair<int,int>,int > mp;
vector<int> G[MAXN];
int dis[MAXN];
bool inq[MAXN];
int N,M,S,T;
queue<int> que;

void Init(){
    memset(dis,INF,sizeof(dis));
    for(int i=1;i<=N;i++){
        G[i].clear();
    }
    mp.clear();
    memset(inq,false,sizeof(inq));
}

void BFS(int s,int t){
   while(!que.empty()){
       que.pop();
   }
   dis[s]=0;
   que.push(s);
   inq[s]=true;
   while(!que.empty()){
       int pi=que.front();
       que.pop();
       inq[pi]=false;
       for(int i=G[pi].size()-1;i>=0;i--){
            int ki=G[pi][i];
            int tmpdis=dis[pi]+mp[make_pair(pi,ki)];
            if(inq[ki]){
                if(tmpdis<dis[ki])dis[ki]=tmpdis;
            }else{
                if(dis[ki]==INF||(tmpdis<dis[ki])){
                    dis[ki]=tmpdis;
                    que.push(ki);
                }
            }
       }
   };
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
