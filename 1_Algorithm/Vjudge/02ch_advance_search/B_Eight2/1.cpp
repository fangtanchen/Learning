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

const int MAXN=5e5+10;
const int dir[2][4][2]={
    {1,0,0,-1,0,1,-1,0},
    {-1,0,0,1,0,-1,1,0}
};



struct Status{
    char eight[9];
    int status;
    int space;
    Status(){
         memset(eight,0,sizeof(eight));
         status=0;
         space=0;
    }
};

char vis[MAXN];
int father1[MAXN],move1[MAXN];
int father2[MAXN],move2[MAXN];
queue<Status> Q1,Q2;
Status s1,s2,s,t;
int T,N;
int found,status;
int fac_n[10]={1,1,2,6,24,120,720,5040,40320,362880};
char ans[MAXN];
int anslen;

int Cantor(char s[]){
     int ret=0;
     for(int i=0;i<9;i++){
         int cnt=0;
         for(int j=i+1;j<9;j++){
            if(s[i]>s[j]) cnt++;
         }
         ret+=cnt*fac_n[9-1-i];
     }
     return ret;
}


bool InMap(int ri,int ci){
     return ri>=0&&ri<3&&ci>=0&&ci<3;
}

void BFS(queue<Status> &Q,bool flag){
    s=Q.front();
    Q.pop();
    int k=s.space;
    int x=k/3,y=k%3;
    for(int di=0;di<4;di++){
        t=s;
        int xx=x;
        int yy=y;
        if(flag){
            xx+=dir[0][di][0];
            yy+=dir[0][di][1];
        }
        else {
            xx+=dir[1][di][0];
            yy+=dir[1][di][1];
        }
        if(!InMap(xx,yy))continue;
        t.space=3*xx+yy;
        swap(t.eight[t.space],t.eight[k]);
        t.status=Cantor(t.eight);
        if(flag){
            if(vis[t.status]!=1){
                move1[t.status]=di;
                father1[t.status]=s.status;
                if(vis[t.status]==2){
                     found=true;
                     status=t.status;
                     return;
                }
                vis[t.status]=1;
                Q1.push(t);
            }
        }else{
            if(vis[t.status]!=2){
                move2[t.status]=di;
                father2[t.status]=s.status;
                if(vis[t.status]==1){
                     found=true;
                     status=t.status;
                     return;
                }
                vis[t.status]=2;
                Q2.push(t);
            }
        }
    }
}

void TBFS(){
    while(!Q1.empty())Q1.pop();
    while(!Q2.empty())Q2.pop();
    memset(vis,0,sizeof(vis));
    Q1.push(s1);
    Q2.push(s2);
    father1[s1.status]=-1;
    father2[s2.status]=-1;
    vis[s1.status]=1;
    vis[s2.status]=2;
    found=false;
    while((!Q1.empty())||(!Q2.empty())){
        if(!Q1.empty())BFS(Q1,true);
        if(found)return;
        if(!Q2.empty())BFS(Q2,false);
        if(found)return;
    }
}

void PrintPath1(int father[],int move[]){
    int u=status;
    int path[1000];
    int pi=0;
    while(u!=s1.status){
        path[pi++]=move[u];
        u=father[u];
    }
    for(int i=pi-1;i>=0;i--){
        switch(path[i]){
            case 0:
                ans[anslen++]='d';
                break;
            case 1:
                ans[anslen++]='l';
                break;
            case 2:
                ans[anslen++]='r';
                break;
            case 3:
                ans[anslen++]='u';
                break;
        }
    }
}
void PrintPath2(int father[],int move[]){
    int u=status;
    int path[1000];
    int pi=0;
    while(u!=s2.status){
        path[pi++]=move[u];
        u=father[u];
    }
    for(int i=0;i<pi;i++){
        switch(path[i]){
            case 0:
                ans[anslen++]='d';
                break;
            case 1:
                ans[anslen++]='l';
                break;
            case 2:
                ans[anslen++]='r';
                break;
            case 3:
                ans[anslen++]='u';
                break;
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>T;
    for(int ti=1;ti<=T;ti++){
         cin>>s1.eight>>s2.eight;
         for(int i=0;i<9;i++){
             if(s1.eight[i]=='X'){
                 s1.space=i;
                 s1.eight[i]=9;
             }else{
                 s1.eight[i]-='0';
             }
             if(s2.eight[i]=='X'){
                 s2.space=i;
                 s2.eight[i]=9;
             }else{
                 s2.eight[i]-='0';
             }
         }
         s1.status=Cantor(s1.eight);
         s2.status=Cantor(s2.eight);


         TBFS();
         anslen=0;
         if(status!=s1.status)PrintPath1(father1,move1);
         if(status!=s2.status)PrintPath2(father2,move2);
         printf("Case %d: %d\n",ti,anslen);
         ans[anslen]=0;
         printf("%s\n",ans);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
