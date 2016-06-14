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

#define MAXS 362900

struct Node{
     char board[9];
     char space;
};
const int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int step[MAXS];
bool visited[MAXS];
queue<int> qe;
const int n=9;

void Init(){
    memset(visited,false,sizeof(visited));
    while(!qe.empty())qe.pop();
    memset(step,-1,sizeof(step));
}

int Cantor(const char *s){
    int res=0;
    for(int i=0;i<n;i++){
         int temp=0;
         for(int j=i+1;j<n;j++){
             if(s[j]<s[i])temp++;
         }
         res+=(temp*fac[n-1-i]);
    }
#ifdef U_DEBUG
//printf("%s-->%d\n",s,res);
#endif

    return res;
}

int hsh(Node st){
     return Cantor(st.board);
}

void unCantor(int num,Node &cur){
     char a[10];
     bool used[10];
     memset(used,false,sizeof(used));
     for(int i=0;i<n;i++){
          a[i]=num/fac[n-i-1];
          num%=fac[n-i-1];
          int cnt=0;
          for(int j=1;j<=n;j++){
              if(!used[j]){
                  cnt++;
                  if(cnt==a[i]+1){
                      if(j==9){
                          cur.space=i;
                      }
                      {
                          cur.board[i]=j;
                      }
                      used[j]=true;
                      break;
                  }
              }
          }
     }
}


int BFS(const Node st){
    int curnum=hsh(st);
    int curx=st.space/3;
    int cury=st.space%3;
    visited[curnum]=true;
    step[curnum]=0;
    qe.push(curnum);
    if(curnum==0)return 0;

    while(!qe.empty()){
        int curnum=qe.front();
        qe.pop();
        Node curnode;
        unCantor(curnum,curnode);
        int curx=curnode.space/3;
        int cury=curnode.space%3;
        for(int i=0;i<4;i++){
            int tempx=curx+dir[i][0];
            int tempy=cury+dir[i][1];
            if(tempx>=0&&tempx<=2&&tempy<=2&&tempy>=0){
                Node tmpnode=curnode;
                tmpnode.space=tempx*3+tempy;
                swap(tmpnode.board[tmpnode.space],tmpnode.board[curnode.space]);
                int v=hsh(tmpnode);
                if(!visited[v]){
                    step[v]=step[curnum]+1;
                    visited[v]=true;

                    if(v==0){
                         return 0;
                     }
                    qe.push(v);
                }
            }
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
        Init();
        Node start;
        for(int i=0;i<9;i++){
            int a;
            scanf("%d",&a);
            if(0==a){
                 start.board[i]=9;
                 start.space=i;
            }else{
                 start.board[i]=a;
            }
        }
        BFS(start);
        if(visited[0]){
             printf("%d\n",step[0]);
        }else{
            puts("No Solution!");
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
