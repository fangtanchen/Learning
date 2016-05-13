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

int n,m;
int Bcnt;
int Top;
int Index;
int low[MAXN],dfn[MAXN];
bool instack[MAXN];
int stack[MAXN],belong[MAXN];
vector<int> g[MAXN];

void init_tarjan(){
     Bcnt=Top=Index=0;
     for(int i=0;i<=n;i++){
         g[i].clear();
     }
     memset(low,0,sizeof(low));
     memset(dfn,0,sizeof(dfn));
     memset(instack,false,sizeof(instack));
     memset(stack,0,sizeof(stack));
     memset(belong,0,sizeof(belong));
}

void Tarjan(int u){
     stack[Top++]=u;
     instack[u]=true;
     low[u]=dfn[u]=Index++;

     for(int i=g[u].size()-1;i>=0;i--){
          int v=g[u][i];
          if(!dfn[v]){
              Tarjan(v);
              low[u]=min(low[u],low[v]);
          }else if(instack[v]){
               low[u]=min(low[u],low[v]);
          }
     }
     if(low[u]==dfn[u]){
         Bcnt++;
         int v;
         do{
             v=stack[--Top];
             belong[v]=Bcnt;
             instack[v]=false;
         }while(u!=v);
     }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
