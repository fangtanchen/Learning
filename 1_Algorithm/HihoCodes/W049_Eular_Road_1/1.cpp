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
const int MAXN=1e4+10;
const int MAXM=1e5+10;

int N,M;
int top,first[MAXN],to[MAXM],adj[MAXM];
bool vis[MAXM];
int tail,head;
int qe[MAXM];
int degree[MAXN];
int fa[MAXN];

void Init(){
    top=0;
    memset(first,-1,sizeof(first));
    memset(to,-1,sizeof(to));
    memset(adj,-1,sizeof(adj));
    memset(vis,false,sizeof(vis));
    head=tail=0;
    memset(degree,0,sizeof(degree));
    for(int i=1;i<MAXN;i++){
        fa[i]=i;
    }
}

bool Empty(){
    return head==tail;
}
int Pop(){
    if(head==tail){
        printf("the queue is empty\n");
        return 0;
    }
    int ret=qe[head];
    head=(head+1)%MAXM;
    return ret;
}
int Push(int x){
    if((tail+2)%MAXM==head){
        printf("the queue is full\n");
        return 0;
    }
     qe[tail]=x;
     tail=(tail+1)%MAXM;
     return 0;
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
     first[u]=top++;
}

int Find(int x){
    if(x==fa[x])return x;
    fa[x]=Find(fa[x]);
    return fa[x];
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
         degree[u]++;
         degree[v]++;
         int fu=Find(u),fv=Find(v);
         if(fu<fv)fa[fv]=fu;
         else if(fu>fv)fa[fu]=fv;
    }
    int cnt=0;
    for(int i=1;i<=N;i++){
         if(i==Find(i)){
             cnt++;
             if(cnt>1)break;
         }
    }
    if(cnt>1){
         printf("Part\n");
         return 0;
    }
    cnt=0;
    for(int i=1;i<=N;i++){
        if(degree[i]&1){
            cnt++;
        }
    }
    if(cnt==0||cnt==2){
         printf("Full\n");
    }else{
        printf("Part\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
