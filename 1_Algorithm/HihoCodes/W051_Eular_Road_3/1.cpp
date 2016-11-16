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
const int MAXN=25;
const int MAXM=1e5+10;

int N;
int first[MAXM],adj[MAXM],to[MAXM],top;
int fac2[MAXN];
int path[MAXM];
int path_len;

void Init(){
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(to,-1,sizeof(to));
    top=0;
    fac2[0]=1;
    for(int i=1;i<MAXN;i++){
        fac2[i]=2*fac2[i-1];
    }
    path_len=0;
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}

void Del(int u,int v){
    if(to[first[u]]==v){
        first[u]=adj[first[u]];
        return;
    }
    for(int pa=first[u],pos=adj[first[u]];pos!=-1;
            pa=pos,pos=adj[pos]){
        if(to[pos]==v) {
            adj[pa]=adj[pos];
            return;
        }
    }
}

void DFS(int u){
    int pos;
    while(pos=first[u]){
        int v=to[pos];
        Del(u,v);
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
    scanf("%d",&N);
    int high=fac2[N-1];
    for(int i=0;i<fac2[N];i++){
        int u=i>>1;
        int v=i;
        if(v>=high)v-=high;
        Add(u,v);
    }
    DFS(1);



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
