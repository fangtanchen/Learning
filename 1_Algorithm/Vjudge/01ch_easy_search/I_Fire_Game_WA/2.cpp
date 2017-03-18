#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=20;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
typedef long long LL;

int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};

struct Node{
     int ri,ci;
     int cnt;
     Node(int a,int b,int c){
         ri=a;ci=b;cnt=c;
     }
};

vector<Node> v;
char mp[MAXN][MAXN];
bool vis[MAXN][MAXN];

int T,N,M;

bool InMap(int ri,int ci){
    return (ri>=1)&&(ri<=N)&&(ci>=1)&&(ci<=M);
}

int BFS(Node x,Node y){
    memset(vis,false,sizeof(vis));
    queue<Node> Q;
    Q.push(x);
    Q.push(y);
    vis[x.ri][x.ci]=vis[y.ri][y.ci]=true;
    int ret=0;
    while(!Q.empty()){
        Node now=Q.front();
        ret=now.cnt;
        Q.pop();
        for(int di=0;di<4;di++){
             int tri=now.ri+dx[di];
             int tci=now.ci+dy[di];
             int tcnt=now.cnt+1;
             if((InMap(tri,tci))
                     &&(mp[tri][tci]=='#')
                     &&(!vis[tri][tci])){
                 vis[tri][tci]=true;
                 Q.push(Node(tri,tci,tcnt));
             }
        }
    }
    return ret;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        v.clear();
         scanf("%d%d",&N,&M);
         for(int ni=1;ni<=N;ni++){
             scanf("%s",mp[ni]+1);
             for(int mi=1;mi<=M;mi++){
                 if(mp[ni][mi]=='#')
                     v.push_back(Node(ni,mi,0));
             }
         }
         int ans=INF;
         for(int i=0;i<v.size();i++){
             for(int j=i;j<v.size();j++){
                 int tmp=BFS(v[i],v[j]);
                 if(tmp>=ans)continue;
                 bool flag=true;
                 for(int ri=1;ri<=N;ri++){
                     for(int ci=1;ci<=M;ci++){
                         if(mp[ri][ci]=='#'&&(false==vis[ri][ci])){
                             flag=false;
                             break;
                         }
                     }
                     if(!flag)break;
                 }
                 if(flag){
                     ans=min(ans,tmp);
                 }
             }
         }
         if(ans==INF)ans=-1;
         printf("Case %d: %d\n",ti,ans);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
