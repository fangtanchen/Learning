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
#define MAXS 363000

struct Node{
    int map[9];
    int space;
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
                        {1,0},{1,1},{1,2},
                        {2,0},{2,1},{2,2}};
const int dir[][2]={1,0,-1,0,0,1,0,-1};
bool vis[MAXS];
priority_queue<Node> Q;

void Init(){
     memset(vis,false,sizeof(vis));
     while(!Q.empty()){
         Q.pop();
     }
}

int Cantor(const Node st){
    int ret=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i+1;j<n;j++){
            if(st.map[j]<st.map[i]){
                cnt++;
            }
        }
        ret+=cnt*fac[n-1-i];
    }
    return ret;
}

int GetH(const Node st){
    int reth=0;
    for(int i=0;i<n;i++){
        if(st.map[i]==9)continue;
        int x=i/3;
        int y=i%3;
        int k=st.map[i];
        reth+=abs(pos[k][0]-x)+abs(pos[k][1]-y);
    }
    return reth;
}


int BFS(const Node st){
    int num=Cantor(st);
    Q.push(st);
    if(0==num)return 0;

    while(!Q.empty()){
         Node cur,tmp;
         int curnum,tmpnum,curx,cury;
         cur=Q.top();
         Q.pop();
         curnum=Cantor(cur);
         curx=cur.space/3;
         cury=cur.space%3;
         if(vis[curnum])continue;
         vis[curnum]=true;
         for(int di=0;di<4;di++){
             tmp=cur;
             int tmpx=curx+dir[di][0];
             int tmpy=cury+dir[di][1];
             if(tmpx<0||tmpx>2||tmpy<0||tmpy>2)continue;
             tmp.space=3*tmpx+tmpy;
             swap(tmp.map[tmp.space],tmp.map[cur.space]);
             tmp.g+=1;
             tmp.h=GetH(tmp);
             tmp.f=tmp.g+tmp.h;
             tmpnum=Cantor(tmp);
             if(tmpnum==0)return tmp.g;
             if(vis[tmpnum])continue;
             Q.push(tmp);
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
    cin>>t;
    Node start;
    while(t--){
        Init();
         int a;
         for(int i=0;i<n;i++){
            scanf("%d",&a);
            start.map[i]=a;
            if(a==0){
                 start.map[i]=9;
                 start.space=i;
            }
         }
         start.g=0;
         start.h=GetH(start);
         start.f=start.g+start.h;
         int res=BFS(start);
         if(res==-1)
             printf("No Solution!\n");
         else{
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
