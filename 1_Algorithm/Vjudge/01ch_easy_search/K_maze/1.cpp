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
const int MAXN=10;
const int dir[4][2]={{0,1},{0,-1},
    {1,0},{-1,0}};

class Point{
    public:
        int x,y;
        Point(int a=0,int b=0){
            x=a;
            y=b;
        }
        friend bool operator==(const Point a,const Point b){
            return (a.x==b.x)&&(a.y==b.y);
        }
        void Out(){
            cout<<"("<<x<<", "<<y<<")"<<endl;
        }
};

int maze[MAXN][MAXN];
Point path[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<Point> qe;

bool InMap(Point a){
    return (a.x>=0)&&(a.x<=4)&&(a.y>=0)
        &&(a.y<=4)&&(maze[a.x][a.y]==0);
}

bool BFS(const Point st, const Point ed){
    memset(vis,false,sizeof(vis));
    while(!qe.empty())qe.pop();
    qe.push(st);
    vis[st.x][st.y]=true;
    while(!qe.empty()){
        Point now=qe.front();
        qe.pop();
        if(now==ed)break;
        for(int di=0;di<4;di++){
            Point nex=Point(now.x+dir[di][0],now.y+dir[di][1]);
            if((!InMap(nex))||(vis[nex.x][nex.y]))continue;
            vis[nex.x][nex.y]=true;
            path[nex.x][nex.y]=now;
            qe.push(nex);
        }
    }
    Point now=ed;
    while(!(now==st)){
        now.Out() ;
        now=path[now.x][now.y];
    }
    now.Out();
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        cin.sync_with_stdio(false);
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cin>>maze[i][j];
            }
        }
        Point st(4,4),ed(0,0);
        BFS(st,ed);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
