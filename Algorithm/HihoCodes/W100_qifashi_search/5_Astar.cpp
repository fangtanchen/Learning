#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAXS 363000


struct Node{
    char map[9];
    int x,y;
    int f,g,h;
    friend bool operator<(const Node &a, const Node &b){
         if(a.f==b.f)
             return a.g<b.g;
         return a.f>b.f;
    }
};

const int n=9;
const int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
const int pos[][2]={{}, {0,0},{0,1},{0,2},
                        {1.0},{1,1},{1,2},
                        {2,0},{2,1},{2,2}};
const int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool visited[MAXS];
int step[MAXS];
priority_queue<Node> qe;

void Init(){
    memset(visited,false,sizeof(visited));
    memset(step,-1,sizeof(step));
    while(!qe.empty()){
         qe.pop();
    }
}

bool Check(int x,int y){
     return x>=0&&x<=2&&y>=0&&y<=2;
}

bool Judge(const Node st){
    int cnt=0;
    for(int i=0;i<9;i++){
        if(st.map[i]==9)continue;
        for(int j=i-1;j>=0;j--){
            if(st.map[j]==9)continue;
            if(st.map[j]>st.map[i])cnt++;
        }
    }
    if(cnt%2)return false;
    return true;
}

int Cantor(const Node st){
     int ret=0;
     for(int i=0;i<n;i++){
         int cnt=0;
         for(int j=i+1;j<n;j++){
             if(st.map[j]<st.map[i])cnt++;
         }
         ret+=cnt*fac[n-i-1];
     }
     return ret;
}

int GetH(const Node st){
    int retH=0;
    for(int i=0;i<n;i++){
        if(st.map[i]==9)continue;
        int x=i/3;
        int y=i%3;
        retH+=abs(pos[st.map[i]][0]-x)+abs(pos[st.map[i]][1]-y);
    }
    return retH;
}


int BFS(const Node st){
    int num=Cantor(st);
    step[num]=0;
    if(0==num)return 0;
    qe.push(st);

    while(!qe.empty()){
        Node cur=qe.top();
        qe.pop();
        int curnum;
        curnum=Cantor(cur);
        if(visited[curnum])continue;
        visited[curnum]=true;

        for(int di=0;di<4;di++){
            Node tmp=cur;
            tmp.x=cur.x+dir[di][0];
            tmp.y=cur.y+dir[di][1];
            if(!Check(tmp.x,tmp.y))continue;
            swap(tmp.map[3*tmp.x+tmp.y],tmp.map[3*cur.x+cur.y]);
            tmp.g=cur.g+1;
            tmp.h=GetH(tmp);
            tmp.f=tmp.g+tmp.h;
            int tmpnum=Cantor(tmp);
            if(tmpnum==0)return tmp.g;
            if(visited[tmpnum])continue;
            qe.push(tmp);
        }
    }
    return -1;

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
        for(int i=0;i<n;i++){
             int a;
             scanf("%d",&a);
             start.map[i]=a;
             if(a==0){
                 start.map[i]=9;
                 start.x=i/3;
                 start.y=i%3;
             }
        }
        start.g=0;
        start.h=GetH(start);
        start.f=start.g+start.h;
        int res=BFS(start);

        if(res==-1){
            printf("No Solution!\n");
        }else{
             printf("%d\n",res);
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
