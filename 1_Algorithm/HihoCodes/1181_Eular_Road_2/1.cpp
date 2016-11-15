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
const int MAXN=1005;
const int MAXM=20010;

int first[MAXN],to[MAXM],adj[MAXM],top;
int N,M;
int path[MAXM];
int path_len;

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
    int tmp=to[first[u]];
    if(tmp==v){
        first[u]=adj[first[u]];
        return;
    }
    for(int pa=first[u],pos=adj[pa];pos!=-1;pa=pos,pos=adj[pos]){
        int tmp=to[pos];
        if(v==tmp){
            adj[pa]=adj[pos];
            return;
        }
    }
}


void DFS(int u){
    for(int pos=first[u];pos!=-1;pos=first[u]){
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
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);
    for(int mi=1;mi<=M;mi++){
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
//		system("out.txt");
	#endif

	return 0;
}
