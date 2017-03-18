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
const int MAXN=1010;
const int INF=0x3f3f3f3f;
const int dir[4][2]={-1,0,1,0,0,1,0,-1};

struct Node{
    int ri,ci;
    int cnt;
    Node(int a=0,int b=0,int c=0){
        ri=a;
        ci=b;
        cnt=c;
    }
};

char G[MAXN][MAXN];
int T,R,C;
bool vis[MAXN][MAXN];
queue<Node> QFire[2],QJoe;

bool InMap(int ri,int ci){
     return ri>=1&&ri<=R&&ci>=1&&ci<=C;
}
int BFS(){
    memset(vis,false,sizeof(vis));
    vis[QJoe.front().ri][QJoe.front().ci]=true;
    int si=0,di=1;
    int ans=INF;
    while(!QJoe.empty()){
        Node u=QJoe.front();
        QJoe.pop();
        if(u.cnt!=ans){
            ans=u.cnt;
            swap(si,di);
            while(!QFire[si].empty()){
                Node ufire=QFire[si].front();
                QFire[si].pop();
                for(int ki=0;ki<4;ki++){
                    int ri=ufire.ri+dir[ki][0];
                    int ci=ufire.ci+dir[ki][1];
                    if(InMap(ri,ci)&&(G[ri][ci]=='.')){
                        G[ri][ci]='F';
                        QFire[di].push(Node(ri,ci,0));
                    }
                }
            }
        }
        for(int ki=0;ki<4;ki++){
            int ri=u.ri+dir[ki][0];
            int ci=u.ci+dir[ki][1];
            int cnt=u.cnt+1;
            if(!InMap(ri,ci))return cnt;
            else if(G[ri][ci]=='.'&&(!vis[ri][ci])){
                 vis[ri][ci]=true;
                 QJoe.push(Node(ri,ci,cnt));
            }
        }
    }
    return -1;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<2;i++)
            while(!QFire[i].empty())QFire[i].pop();
        while(!QJoe.empty())QJoe.pop();

         scanf("%d%d",&R,&C);
         Node J,F;
         for(int ri=1;ri<=R;ri++){
             scanf("%s",G[ri]+1);
             for(int ci=1;ci<=C;ci++){
                 if(G[ri][ci]=='J'){
                     QJoe.push(Node(ri,ci,0));
                     G[ri][ci]='.';
                 }
                 if(G[ri][ci]=='F'){
                     QFire[1].push(Node(ri,ci,0));
                 }
             }
         }
         int ans=BFS();
         if(ans==-1)puts("IMPOSSIBLE");
         else printf("%d\n",ans);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
