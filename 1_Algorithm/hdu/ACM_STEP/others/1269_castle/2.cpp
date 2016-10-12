#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAXN 10010
#define MAXM 100010

int N,M;
int Bcnt,Top,Index;
int belong[MAXN],stack[MAXN];
int dfn[MAXN],low[MAXN];
bool visited[MAXN];
bool instack[MAXN];
vector<int> G[MAXN];

void Init(){
     Bcnt=Top=Index=0;
     memset(belong,0,sizeof(belong));
     memset(instack,false,sizeof(instack));
     memset(dfn,0,sizeof(dfn));
     memset(low,0,sizeof(low));
     memset(visited,false,sizeof(visited));
     memset(stack,0,sizeof(stack));
     for(int i=1;i<=N;i++)G[i].clear();
}

void Tarjan(int u){
    dfn[u]=low[u]=Index++;
    stack[Top++]=u;
    instack[u]=true;
    for(int i=G[u].size()-1;i>=0;i--){
         int v=G[u][i];
         if(!dfn[v]){
             Tarjan(v);
            low[u]=min(low[u],low[v]);
         }else if(instack[v]){
            low[u]=min(low[u],low[v]);
         }
    }
    if(dfn[u]==low[u]){
        int v;
        do{
            v=stack[--Top];
            instack[v]=false;
            belong[v]=Bcnt;
        }while(v!=u);
        Bcnt++;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d%d",&N,&M),N+M){
            Init();
             int a,b;
             for(int i=0;i<M;i++){
                 scanf("%d%d",&a,&b);
                 G[a].push_back(b);
             }
             for(int i=1;i<=N;i++){
                 if(!dfn[i])Tarjan(i);
             }
             if(Bcnt==1)printf("Yes\n");
             else printf("No\n");

        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
