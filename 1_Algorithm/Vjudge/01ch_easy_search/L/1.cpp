#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=110;
const int dir[10][2]={
    -1,-1,-1,0,-1,1,
    0,-1,0,1,
    1,-1,1,0,1,1
};

char G[MAXN][MAXN];
int R,C;
bool vis[MAXN][MAXN];
struct Node{
    int ri,ci;
    Node(int a=0,int b=0){
         ri=a;ci=b;
    }
};

bool InMap(int ri,int ci){
     return ri>=1&&ri<=R&&ci>=1&&ci<=C;
}

void BFS(int ri,int ci){
    queue<Node> Q;
    Q.push(Node(ri,ci));
    vis[ri][ci]=true;
    while(!Q.empty()){
        Node u=Q.front();
        Q.pop();
        for(int di=0;di<8;di++){
             int ri=u.ri+dir[di][0];
             int ci=u.ci+dir[di][1];
             if(InMap(ri,ci)
                     &&(G[ri][ci]=='@')
                     &&(!vis[ri][ci])){
                  vis[ri][ci]=true;
                  Q.push(Node(ri,ci));
             }
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    while(scanf("%d%d",&R,&C),R){
        for(int ri=1;ri<=R;ri++){
            scanf("%s",G[ri]+1);
        }
        int ans=0;
        memset(vis,false,sizeof(vis));
        for(int ri=1;ri<=R;ri++){
            for(int ci=1;ci<=C;ci++){
                if(G[ri][ci]=='@'&&(!vis[ri][ci])){
                    ans++;
                    BFS(ri,ci);
                }
            }
        }
        printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
