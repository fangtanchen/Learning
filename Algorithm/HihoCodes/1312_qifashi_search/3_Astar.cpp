#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAXS  363000


struct Node{
  int f,h,g;
  int x,y;
  char map[3][3];
  friend bool operator<(const Node& a,const Node &b){
       if(a.f==b.f)return a.g<b.g;
       return a.f>b.f;
  }
};
int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
bool visited[MAXS];
const int pos[][2]={{0,0},{0,1},{0,2},
                    {1,0},{1,1},{1,2},
                    {2,0},{2,1},{2,2}};
const int dir[][2]={0,1,0,-1,1,0,-1,0};
Node start;


int check(){
     int i,j,k;
     int s[20];
     int cnt;
     for(int i=0;i<3;i++){
         for(int j=0;j<3;j++){
             int temp=3*i+j;
             s[temp]=start.map[i][j];
             if(s[temp]=='x'){
                  continue;
             }
             for(int k=temp-1;k>=0;k--){
                 if(s[k]=='x')continue;
                 if(s[k]>s[temp])cnt++;
             }
         }
     }
     if(cnt%2)return 0;
     return 1;
}

int Solve(Node a){
    int i,j,k;
    int s[20];
    int ans=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int temp=3*i+j;
            s[temp]=a.map[i][j];
            int cnt=0;
            for(int k=temp-1;k>=0;k--){
                 if(s[k]>s[temp])cnt++;
            }
            ans=ans+fac[temp]*cnt;
        }
    }
    return ans;
}

int get_h(Node  a){
    int i,j;
    int ans=0;
    for(i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a.map[i][j]=='x')
                continue;
            int k=a.map[i][j]-1;
            ans+=abs(pos[k][0]-i)+abs(pos[k][1]-j);
        }
    }
    return ans;
}

int bfs(){
     memset(visited,false,sizeof(visited));
     priority_queue<Node> Q;
     start.g=0;
     start.h=get_h(start);
     start.f=start.h+start.g;
     int curnum=Solve(start);
     visited[curnum]=true;
     if(0==curnum)return 0;
     Q.push(start);
     Node nex;

     while(!Q.empty()){
          Node a=Q.top();
          Q.pop();
          int k_s=Solve(a);
          visited[k_s]=true;
          for(int i=0;i<4;i++){
              nex=a;
              nex.x+=dir[i][0];
              nex.y+=dir[i][1];
              if(nex.x<0||nex.x>2||nex.y<0||nex.y>0)
                  continue;
              nex.map[a.x][a.y]=a.map[nex.x][nex.y];
              nex.map[nex.x][nex.y]='x';
              nex.g+=1;
              nex.h=get_h(nex);
              nex.f=nex.g+nex.h;
              if(visited[Solve(nex)])continue;
              Q.push(nex);
              if(Solve(nex)==0)return nex.g;
          }
     }

}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int t;
    for(scanf("%d",&t);t--;){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int a;
                scanf("%d",&a);
                start.map[i][j]=a;
                if(a==0){
                    start.map[i][j]='x';
                    start.x=i;
                    start.y=j;
                }
            }
        }
        if(!check()){
             puts("No Solution!");
        }
        else{
            printf("%d\n",bfs());
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
