#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>
#include<set>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=110;
const int dir[4][2]={-1,0,1,0,0,-1,0,1};
typedef pair<int,int> pii;
typedef pair< pii,pii > ppi;

int N,M;
char G[MAXN][MAXN];
int vis[MAXN][MAXN];


bool InMap(int ri,int ci){
    return ri>=1&&ri<=N&&ci>=1&&ci<=M;
}

int BFS(pii st,pii ed){
    queue<ppi> Q;
    Q.push(make_pair(st,make_pair(0,0)));
    while(!Q.empty()){
        ppi u=Q.front();
        Q.pop();
        int uri=u.first.first;
        int uci=u.first.second;
        int ustatus=u.second.first;
        int ucnt=u.second.second;
        if((vis[uri][uci]|ustatus)==vis[uri][uci])continue;
        if(uri==ed.first&&uci==ed.second)return ucnt;
        for(int di=0;di<4;di++){
             int vri=uri+dir[di][0];
             int vci=uci+dir[di][1];
             int vcnt=ucnt+1;
             int vstatus=ustatus;
             if(!InMap(vri,vci)||G[vri][vci]=='0')continue;
             if(G[vri][vci]>='A'&&G[vri][vci]<='Z'){
                 int tmp=G[vri][vci]-'A';
                 if(!(vstatus&(1<<tmp))){
                     continue;
                 }
             }
             if(G[vri][vci]>='a'&&G[vri][vci]<='z'){
                  int tmp=G[vri][vci]-'a';
                  vstatus|=(1<<tmp);
             }
             if((vis[vri][vci]|vstatus)==vis[vri][vci])continue;
             Q.push(make_pair(make_pair(vri,vci),make_pair(vstatus,vcnt)));
        }
    }
    return -1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>M;
    pii st,ed;
    for(int ri=1;ri<=N;ri++){
         scanf("%s",G[ri]+1);
         for(int ci=1;ci<=M;ci++){
             if(G[ri][ci]=='2'){
                  st=make_pair(ri,ci);
             }
             if(G[ri][ci]=='3'){
                 ed=make_pair(ri,ci);
             }
         }
    }
    int ans=BFS(st,ed);
    cout<<ans<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
