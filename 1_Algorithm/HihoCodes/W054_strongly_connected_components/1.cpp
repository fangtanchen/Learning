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
#define MEM(x,a) memset(x,a,sizeof(x));
const int MAXN=2e4+10;
const int MAXM=1e5+10;

int top,first[MAXN],adj[MAXM],to[MAXM];
int newtop,newfirst[MAXN],newadj[MAXM],newto[MAXM];
int weight[MAXN];
bool vis[MAXN];
bool instack[MAXN];
int sta[MAXN],tag[MAXN];
int dfn[MAXN],low[MAXN];
int indegree[MAXN];
int N,M;
int num_components=0;
int newweight[MAXN];

void Init(){
    top=0;
    MEM(first,-1);
    MEM(adj,-1);
    MEM(to,-1);
    newtop=0;
    MEM(newfirst,-1);
    MEM(newadj,-1);
    MEM(newto,-1);
    MEM(vis,false);
    MEM(instack,false);
    MEM(tag,-1);
    MEM(indegree,0);
    MEM(newweight,0);
    sta[0]=0;
}

void Stack_Push(int x){
    sta[++sta[0]]=x;
}

int Stack_Top(){
     return sta[sta[0]];
}

void Stack_Pop(){
    sta[0]--;
}

void Add(int u,int v,int c){
    if(c==1){
        adj[top]=first[u];
        to[top]=v;
        first[u]=top++;
    }else{
        newadj[newtop]=newfirst[u];
        newto[newtop]=v;
        newfirst[u]=newtop++;
    }
}

void Tarjan(int u){
    static int counter=0;
    low[u]=dfn[u]=counter++;
    vis[u]=true;
    Stack_Push(u);
    instack[u]=true;

    for(int pos=first[u];pos!=-1;pos=adj[pos]){
         int v=to[pos];
         if(!vis[v]){
             Tarjan(v);
             low[u]=min(low[u],low[v]);
         }else if(instack[v]){
              low[u]=min(low[u],dfn[v]);
         }
    }
    if(low[u]==dfn[u]){
        num_components++;
        int v;
        do{
            v=Stack_Top();
            Stack_Pop();
            instack[v]=false;
            tag[v]=num_components;
        }while(v!=u);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);
    for(int ni=1;ni<=N;ni++){
         scanf("%d",weight+ni);
    }
    for(int mi=0;mi<M;mi++){
         int u,v;
         scanf("%d%d",&u,&v);
         Add(u,v,1);
    }

    Tarjan(1);
    MEM(indegree,0);
    for(int ni=1;ni<=N;ni++){
        if((tag[ni]!=-1)){
             newweight[tag[ni]]+=weight[ni];
        }
    }




	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
