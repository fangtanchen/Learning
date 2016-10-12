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

#define MAXM 100010
#define MAXN 10010

int n, m;
vector<int> g[MAXN];
int Bcnt;
int top;
int index;
int low[MAXN], dfn[MAXN];
bool instack[MAXN];
int belong[MAXN], stack[MAXN];

void init(){
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(instack, 0, sizeof(instack));
	for(int i=0;i<=n;i++){
		g[i].clear();
	}
	Bcnt=top=index=0;
}

void Tarjan(int u){
	stack[Top++]=u;
	instack[u]=1;
	low[u]=dfn[u]=++index;
	for(int i=g[u].size()-1;i>=0;i--){
		int v=g[u][i];
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u], low[v]);
		}else if(instack[v]){
			low[u]=min(low[u], low[v]);
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
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d", &n, &m), n+m){
		init();
		for(int i=0;i<m;i++){
			int x, y;
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
		}
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				Tarjan(i);
			}
		}
		printf("%s\n", Bcnt==1?"Yes":"No");
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
