#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAXN 10010
#define MAXM 100010

int n,m;
vector<int> g[MAXN];

int Bcnt;
int Top;
int Index;
int low[MAXN],dfn[MAXN];
int belong[MAXN],stack[MAXN];
bool instack[MAXN];

void init_tarjan(){
     Bcnt=Top=Index=0;

     memset(low,0,sizeof(low));
     memset(dfn,0,sizeof(dfn));
     memset(instack,false,sizeof(instack));
     memset(belong,0,sizeof(belong));
     memset(stack,0,sizeof(stack));
     for(int i=1;i<=n;i++){
         g[i].clear();
     }
}

void Tarjan(int u){
     stack[Top++]=u;
     instack[u]=true;
     low[u]=dfn[u]=++Index;
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
          ++Bcnt;
          int v;
          do{
              v=stack[--Top];
              instack[v]=0;
              belong[v]=Bcnt;
          }while(u!=v);
     }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d%d",&n,&m),n+m){
             int a,b;
             init_tarjan();
             for(int i=0;i<m;i++){
                 scanf("%d%d",&a,&b);
                 g[a].push_back(b);
             }
             for(int i=1;i<=n;i++){
                  if(!dfn[i])Tarjan(i);
             }
             if(1==Bcnt)puts("Yes");
             else puts("No");

        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
