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
const int MAXN=5e5;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;

char visited[MAXN];
int father1[MAXN];
int father2[MAXN];
int move1[MAXN];
int move2[MAXN];

struct Status{
     char eight[10];
     int space;
     int status;
};

Status s,s1,s2,t;
queue<Status> Q1;
queue<Status> Q2;

bool found;
int status;
int fac_n[]={1,1,2,6,24,120,720,5040,40320,362880};
const int dir[4][2]={-1,0,1,0,0,-1,0,1};

int Cantor(char s[]){
     int ret=0;
     for(int i=0;i<9;i++){
         int cnt=0;
         for(int j=i+1;j<9;j++){
             if(s[i]>s[j])cnt++;
         }
         ret+=cnt*fac_n[9-1-i];
     }
     return ret;
}

bool bSolve(char s[]){
     int cnt=0;
     for(int i=0;i<9;i++){
         if(s[i]==9)continue;
         for(int j=i+1;j<9;j++){
             if(s[j]==9)continue;
             if(s[i]>s[j])cnt++;
         }
     }
     if(1&cnt)return false;
     else return true;
}

bool InMap(int ri,int ci){
    return ri>=0&&ri<3&&ci>=0&&ci<3;
}
void BFS_expand(queue<Status> &Q,bool flag){
     int k,x,y;
     s=Q.front();
     Q.pop();
     k=s.space;
     x=k/3;y=k%3;
     for(int di=0;di<4;di++){
          int xx=x+dir[di][0];
          int yy=y+dir[di][1];
          if(!InMap(xx,yy))continue;
          t=s;
          t.space=3*xx+yy;
          swap(t.eight[t.space],t.eight[s.space]);
          t.status=Cantor(t.eight);
          if(flag){
              if(visited[t.status]!=1//&&(bSolve(t.eight))
                      ){
                  move1[t.status]=di;
                  father1[t.status]=s.status;
                  if(visited[t.status]==2){
                      found=true;
                      status=t.status;
                      return;
                  }
                  visited[t.status]=1;
                  Q.push(t);
              }
          }else{
              if(visited[t.status]!=2//&&(bSolve(t.eight))
                      ){
                  move2[t.status]=di;
                  father2[t.status]=s.status;
                  if(visited[t.status]==1){
                      found=true;
                      status=t.status;
                      return;
                  }
                  visited[t.status]=2;
                  Q.push(t);
              }
          }
     }
}

void TBFS(){
     memset(visited,0,sizeof(visited));
     while(!Q1.empty())Q1.pop();
     while(!Q2.empty())Q2.pop();
     found=false;
     visited[s1.status]=1;
     visited[s2.status]=2;
     father1[s1.status]=-1;
     father2[s2.status]=-1;
     Q1.push(s1);Q2.push(s2);
     while((!Q1.empty()) ||(!Q2.empty())){
         if(!Q1.empty())BFS_expand(Q1,true);
          if(found)return;
          if(!Q2.empty())BFS_expand(Q2,false);
          if(found)return;
     }
}

void PrintPath1(int father[],int move[]){
     int n,u;
     char path[1000];
     n=0;
     u=status;
     while(father[u]!=-1){
         path[n++]=move[u];
         u=father[u];
     }
     for(int i=n-1;i>=0;i--){
         switch(path[i]){
             case 0:
                 putchar('u');
                 break;
             case 1:
                 putchar('d');
                 break;
             case 2:
                 putchar('l');
                 break;
             case 3:
                 putchar('r');
                 break;
         }
     }
}
void PrintPath2(int father[],int move[]){
     int n,u;
     char path[1000];
     n=0;
     u=status;
     while(father[u]!=-1){
         path[n++]=move[u];
          u=father[u];
     }
     for(int i=0;i<n;i++){
         switch(path[i]){
             case 0:
                 putchar('d');
                 break;
             case 1:
                 putchar('u');
                 break;
             case 2:
                 putchar('r');
                 break;
             case 3:
                 putchar('l');
                 break;
         }
     }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    char ch;
    while(cin>>ch){
        if(ch=='x'){
            s1.eight[0]=9;
            s1.space=0;
        }else{
            s1.eight[0]=ch-'0';
        }
        for(int i=1;i<9;i++){
             cin>>ch;
             if(ch=='x'){
                 s1.eight[i]=9;
                 s1.space=i;
             }else{
                 s1.eight[i]=ch-'0';
             }
        }
        s1.status=Cantor(s1.eight);
        for(int i=0;i<9;i++){
            s2.eight[i]=(i+1);
        }
        s2.space=8;
        s2.status=Cantor(s2.eight);
        if(!bSolve(s1.eight)){
             puts("unsolvable");
        }else{
            TBFS();
            if(found){
                if(s1.status!=status)PrintPath1(father1,move1);
                if(s2.status!=status)PrintPath2(father2,move2);
                putchar('\n');
            }else
                puts("unsolvable");
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
