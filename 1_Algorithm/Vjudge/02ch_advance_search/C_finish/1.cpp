#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<set>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=22;


set<int> G[21];
bool vis[MAXN];
int path[MAXN],pathlen;
int path_cnt;
int st;

void DFS(int u,int pi){
    path[pi]=u;
    if(pi==20&&u==st){
        printf("%d: ",++path_cnt);
        for(int i=0;i<=20;i++){
            printf(" %d",path[i]);
        }
        printf("\n");
        return;
    }
    if(vis[u])return;
    vis[u]=true;
    set<int>::iterator it;
    for(it=G[u].begin();it!=G[u].end();++it){
        int v=*it;
        DFS(v,pi+1);
    }
    vis[u]=false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    for(int i=1;i<=20;i++){
        for(int j=1;j<=3;j++){
            int a;
            scanf("%d",&a);
            G[i].insert(a);
        }
    }
    while(scanf("%d",&st),st){
        memset(vis,false,sizeof(vis));
        path_cnt=0;
         DFS(st,0);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
