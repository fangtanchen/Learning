#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
//#include<vector>
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
const int n=9;
bool visited[MAXS];
int step[MAXS];
queue<int> qe;

void Init(){
    memset(visited,false,sizeof(visited));
    memset(step,-1,sizeof(step));

    while(!qe.empty())qe.pop();
}
bool Check(int x,int y){
     return x>=0&&x<=2&&y>=0&&y<=2;
}
int Cantor(const char *s){
     int ret=0;
     for(int i=0;i<n;i++){
         int cnt=0;
         for(int j=i+1;j<n;j++){
             if(s[j]<s[i])cnt++;
         }
         ret+=(cnt*fac[n-1-i]);
     }
     return ret;
}

int HashOrder(Node st){

    return Cantor(st.board);
}

void UnCantor(int num, Node &cur){
    char a[10];
    bool used[10];
    memset(used,false,sizeof(used));
    for(int i=0;i<n;i++){
        a[i]=num/fac[n-i-1];
        num%=fac[n-1-i];
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(!used[j]){
                cnt++;
                if(cnt==a[i]+1){
                    used[j]=true;
                    cur.board[i]=j;
                    if(9==j)cur.space=i;
                }
            }
        }
    }
}

void BFS(const Node st){
     int curnum=HashOrder(st);
     qe.push(curnum);
     step[curnum]=0;
     visited[curnum]=true;
     if(0==curnum)return;

     while(!qe.empty()){
          int curnum=qe.front();
          qe.pop();
          Node cur,tmp;
          UnCantor(curnum,cur);
          int curx=cur.space/3;
          int cury=cur.space%3;

          for(int di=0;di<4;di++){
               int tmpx=curx+dir[di][0];
               int tmpy=cury+dir[di][1];
               if(!Check(tmpx,tmpy))continue;
               tmp=cur;
               tmp.space=3*tmpx+tmpy;
               swap(tmp.board[tmp.space],tmp.board[cur.space]);
               int tmpnum=HashOrder(tmp);
               if(!visited[tmpnum]){
                   visited[tmpnum]=true;
                   step[tmpnum]=step[curnum]+1;
                   if(0==tmpnum)return;
                   qe.push(tmpnum);
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
         int a;
         Node start;
         for(int i=0;i<9;i++){
             scanf("%d",&a);
             if(a==0){
                 start.board[i]=9;
                 start.space=i;
             }else{
                  start.board[i]=a;
             }
         }
         BFS(start);
         if(step[0]>=0){
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
