#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

typedef pair<int,int> pii;

const int MAXN=210;

struct Node{
    int ai,bi;
    int opi;
    Node(int a=0,int b=0,int op=0){
         ai=a;bi=b;opi=op;
    }
};

bool vis[MAXN][MAXN];
int A,B,C;
queue<Node> Q;
map<Node,Node> mp;

void Print(){

}


void BFS(){
    memset(vis,false,sizeof(vis));
    while(!Q.empty())Q.pop();
    mp.clear();
    Q.push(Node(0,0,-1));
    vis[0][0]=true;
    while(!Q.empty()){
         Node now=Q.front();
         Q.pop();
         if(now.ai==C||now.bi==C)
             Print();
         Node tmp;
         tmp=Node(A,now.bi,1);
         if(!vis[A][now.bi]){
             vis[A][now.bi]=true;
             Q.push(tmp);
         }
         tmp=Node(now.ai,B,2);
         if(!vis[tmp.ai][tmp.bi]){
             vis[tmp.ai][tmp.bi]=true;
             Q.push(tmp);
         }
         tmp=Node(0,now.bi,3);
         if(!vis[tmp.ai][tmp.bi]){
             vis[tmp.ai][tmp.bi]=true;
             Q.push(tmp);
         }
         tmp=Node(now.ai,0,4);
         if(!vis[tmp.ai][tmp.bi]){
             vis[tmp.ai][tmp.bi]=true;
             Q.push(tmp);
         }
         tmp=Node(now.ai-min(now.ai,B-now.bi),min(B,now.bi+now.ai),5);
         if(!vis[tmp.ai][tmp.bi]){
             vis[tmp.ai][tmp.bi]=true;
             Q.push(tmp);
         }
         tmp=Node(min(A,now.ai+now.bi),now.bi-min(now.bi,A-now.ai),6);
         if(!vis[tmp.ai][tmp.bi]){
             vis[tmp.ai][tmp.bi]=true;
             Q.push(tmp);
         }
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d%d",&A,&B,&C);
    BFS();

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
