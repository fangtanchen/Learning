#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;
const int MAXM=5010;

int first[MAXN],adj[2*MAXM],to[2*MAXM],top;
int mp[MAXN][MAXN];
int path[2*MAXM];
int deg[MAXN];
int path_len;
int N,M;

void Init(){
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(to,-1,sizeof(to));
    top=0;
    memset(mp,0,sizeof(mp));
    path_len=0;
    memset(deg,0,sizeof(deg));
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}


void DFS(int u){
    for(int pos=first[u];pos!=-1;){
        int v=to[pos];
        if(mp[u][v]){
            mp[u][v]--;
            mp[v][u]--;
            DFS(v);
            pos=first[u];
        }else{
             pos=adj[pos];
        }
    }
    path[path_len++]=u;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    Init();
    for(int i=0;i<M;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        Add(u,v);
        Add(v,u);
        mp[u][v]++;
        mp[v][u]++;
        deg[u]++;
        deg[v]++;
    }
    int st=1;
    for(int i=1;i<=N;i++){
        if(deg[i]%2){
            st=i;
            break;
        }
    }
    DFS(st);
    printf("%d",path[path_len-1]);
    for(int i=path_len-2;i>=0;i--){
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
