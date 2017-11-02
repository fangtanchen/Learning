#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=53;
const int dir[4][2]={-1,0,1,0,0,1,0,-1};

struct Node{
    public:
    int ri,ci,val;
    Node(int a,int b,int c){
        ri=a;ci=b;val=c;
    }
};


int N,M;
char G[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<Node> S;
set<int> area;

bool InMap(int ri,int ci){
    return ri>=1&&ri<=N&&ci>=1&&ci<=M;
}


int DFS(int ri,int ci){
    vis[ri][ci]=true;
    int ret=1;
    for(int di=0;di<4;di++){
        int tri=ri+dir[di][0];
        int tci=ci+dir[di][1];
        if((InMap(tri,tci))
                &&(!vis[tri][tci])
                &&(G[tri][tci]=='#')){
            ret=ret+DFS(tri,tci);
        }
    }
    return ret;
}

bool Judge(int _ri,int _ci,int ri,int ci){
    vis[_ri][_ci]=vis[ri][ci]=true;
    if(G[_ri][_ci]!=G[ri][ci])return false;
    if(G[_ri][_ci]!='#')return true;
    bool ret=true;
    for(int di=0;di<4;di++){
        int _tri=_ri+dir[di][0];
        int _tci=_ci+dir[di][1];
        int tri=ri+dir[di][0];
        int tci=ci+dir[di][1];
        if(vis[_tri][_tci])continue;
        ret=ret&&Judge(_tri,_tci,tri,tci);
        if(!ret){
            cout<<_tri<<" "<<_tci<<endl;
        }
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    S.clear();
    memset(vis,false,sizeof(vis));
    memset(G,'.',sizeof(G));
    for(int ri=1;ri<=N;ri++){
         scanf("%s",G[ri]+1);
    }
    for(int ri=1;ri<=N;ri++){
        for(int ci=1;ci<=M;ci++){
            if((!vis[ri][ci])
                    &&(G[ri][ci]=='#')){
                int val=DFS(ri,ci);
                area.insert(val);
                S.push_back(Node(ri,ci,val));
            }
        }
    }
    int tmp=S.size();
    for(int i=0;i<S.size();i++){
        for(int j=i+1;j<S.size();j++){
            if(S[i].val!=S[j].val)continue;
            memset(vis,false,sizeof(vis));
            if(Judge(S[i].ri,S[i].ci,S[j].ri,S[j].ci)){
                 tmp--;
                 break;
            }
        }
    }
    printf("%d %d %d\n",S.size(),area.size(),tmp);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
