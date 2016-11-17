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
const int MAXN=20050;
const int MAXM=2e5+10;

struct Point{
    int x,y;
    Point(int a=0,int b=0){
        x=a;y=b;
    }
};

int first[MAXN],to[MAXM],adj[MAXM],top;
int parent[MAXN],dfn[MAXN],low[MAXN];
bool vis[MAXN];
int N,M;
int anspt[MAXN];
int anspt_cnt;
Point pt[MAXM];
int pt_cnt;


void Init(){
    memset(first,-1,sizeof(first));
    memset(to,-1,sizeof(to));
    memset(adj,-1,sizeof(adj));
    top=0;
    memset(parent,0,sizeof(parent));
    memset(vis,false,sizeof(vis));
    memset(dfn,0x3f,sizeof(dfn));
    memset(low,0x3f,sizeof(low));
    memset(anspt,0,sizeof(anspt));
    anspt_cnt=0;
    pt_cnt=0;
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}

void DFS(int u){
    static int counter=1;
    low[u]=dfn[u]=counter++;
    vis[u]=true;
    int numchild=0;
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(!vis[v]){
            numchild++;
            parent[v]=u;
            DFS(v);
            low[u]=min(low[u],low[v]);
            if((parent[u]==0)&&(numchild>1)){
                anspt[u]=1;
            }
            if(parent[u]&&(low[v]>=dfn[u])){
                anspt[u]=1;
            }

            if(low[v]>dfn[u]){
                pt[pt_cnt].x=min(u,v);
                pt[pt_cnt].y=max(u,v);
                pt_cnt++;
            }
        }else if(parent[u]!=v){
             low[u]=min(low[u],dfn[v]);
        }
    }
}

bool cmp(const Point& p1,const Point &p2){
    if(p1.x<p2.x)return true;
    else if(p1.x==p2.x && (p1.y<p2.y))
        return true;
    return false;
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
    }
    DFS(1);
    sort(anspt,anspt+anspt_cnt);
    sort(pt,pt+pt_cnt,cmp);
    anspt_cnt=0;
    for(int i=1;i<=N;i++){
        if(anspt[i]){
            if(anspt_cnt)printf(" ");
            printf("%d",i);
            anspt_cnt++;
        }
    }
    if(anspt_cnt==0)printf("Null");
    printf("\n");
    for(int i=0;i<pt_cnt;i++){
         printf("%d %d\n",pt[i].x,pt[i].y);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
