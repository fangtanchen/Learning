#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1010;
const int MAXM=10010;

int first[MAXN],adj[MAXM],to[MAXM],top;
int path[MAXM],path_len;
int N,M;

void Init(){
     memset(first,-1,sizeof(first));
     memset(to,-1,sizeof(to));
     memset(adj,-1,sizeof(adj));
     top=0;
     path_len=0;
}

void Add(int u,int v){
     adj[top]=first[u];
     to[top]=v;
     first[u]=top++;
}

void Del(int u,int v){
    int pos=first[u];
    if(to[pos]==v){
        first[u]=adj[pos];
        return;
    }
    int pa;
    for(pa=pos,pos=adj[pos];pos!=-1;pa=pos,pos=adj[pos]){
         int tmp=to[pos];
         if(v==tmp){
             adj[pa]=adj[pos];
             return;
         }
    }
}

void DFS(int u){
    int pos;
    while((pos=first[u])!=-1){
        int v=to[pos];
        Del(u,v);
        Del(v,u);
        DFS(v);
    }
    path[path_len++]=u;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);
    for(int mi=0;mi<M;mi++){
        int u,v;
        scanf("%d%d",&u,&v);
        Add(u,v);
        Add(v,u);
    }
    DFS(1);
    printf("%d",path[0]);
    for(int i=1;i<path_len;i++){
         printf(" %d",path[i]);
    }
    printf("\n");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
