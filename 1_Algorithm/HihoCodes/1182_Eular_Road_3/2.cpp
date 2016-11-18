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

int fac2[MAXN];
int first[MAXN],adj[MAXM],to[MAXM],top;
int path[MAXM],path_len;
int N;

void Init(){
    fac2[0]=1;
    for(int i=1;i<MAXN;i++){
        fac2[i]=2*fac2[i-1];
    }
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(to,-1,sizeof(to));
    top=0;
    path_len=0;
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}

void Del(int u,int v){
    int pos=first[u],pa;
    if(to[pos]==v){
        first[u]=adj[pos];
        return;
    }
    for(pa=pos,pos=adj[pos];pos!=-1;pa=pos,pos=adj[pos]){
        int tmp=to[pos];
        if(tmp==v){
            adj[pa]=adj[pos];
            return;
        }
    }
}

void DFS(int u){
    int pos;
    while((pos=first[u]),pos!=-1){
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
    if(N==1){
        printf("01\n");
        return 0;
    }
    int high=fac2[N-1];
    for(int ni=0;ni<fac2[N];ni++){
         int u=ni>>1;
         int v=ni;
         if(v>=high)v-=high;
         Add(u,v);
    }
    DFS(0);
    high=fac2[N-2];
    for(int i=0;i<fac2[N];i++){
         if(path[i]&high)printf("1");
         else printf("0");
    }
    printf("\n");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
