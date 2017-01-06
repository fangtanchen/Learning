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
const int MAXN=35;
const int dir[6][3]={{1,0,0},{-1,0,0},
    {0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};


char map[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
int L,R,C;

class Point{
    public:
        int l,r,c;
        int s;
        Point(int a=0,int b=0,int t=0,int pt=0){
            l=a;
            r=b;
            c=t;
            s=pt;
        }
        bool operator==(const Point x) const{
            return (x.l==l)&&(x.r==r)&&(x.c==c);
        }
};
Point st,ed;
queue<Point> qe;


bool InMap(Point x){
    return (x.l>=1)&&(x.l<=L)&&(x.r>=1)&&(x.r<=R)
        &&(x.c>=1)&&(x.c<=C)&&(map[x.l][x.r][x.c]!='#');
}

int BFS(Point st,Point ed){
    memset(vis,false,sizeof(vis));
    while(!qe.empty()){
        qe.pop();
    }

    qe.push(st);
    vis[st.l][st.r][st.c]=true;
    while(!qe.empty()){
        Point now=qe.front();
        qe.pop();
        if(now==ed){
             return now.s;
        }
        for(int di=0;di<6;di++){
            Point nex(now.l+dir[di][0],
                    now.r+dir[di][1],
                    now.c+dir[di][2],
                    now.s+1);
            if(vis[nex.l][nex.r][nex.c]||(!InMap(nex)))continue;
            vis[nex.l][nex.r][nex.c]=true;
            qe.push(nex);
        }
    }
    return -1;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d%d%d",&L,&R,&C),L||R||C){
            for(int i=1;i<=L;i++){
                for(int j=1;j<=R;j++){
                    scanf("%s",map[i][j]+1);
                    for(int k=1;k<=C;k++){
                        if(map[i][j][k]=='S'){
                             st=Point(i,j,k,0);
                        }
                        else if(map[i][j][k]=='E'){
                            ed=Point(i,j,k,0);
                        }
                    }
                }
            }
            int ans=BFS(st,ed);
            if(-1==ans)printf("Trapped!\n");
            else{
                 printf("Escaped in %d minute(s).\n",ans);
            }
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
