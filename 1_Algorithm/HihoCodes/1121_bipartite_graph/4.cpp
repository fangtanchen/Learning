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
const int MAXN=10010;
const int MAXM=80010;

int top,adj[MAXM],to[MAXM],first[MAXN];
int tag[MAXN];
int vis[MAXN];
int T,N,M;

int head,tail;
int qe[MAXN];

void Init(){
     top=0;
     memset(adj,-1,sizeof(adj));
     memset(to,-1,sizeof(to));
     memset(first,-1,sizeof(first));
     memset(tag,-1,sizeof(tag));
     head=tail=0;
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}


void Clear(){
    head=tail=0;
}

bool IsEmpty(){
    return head==tail;
}

int Top(){
    return qe[head];
}

void Pop(){
    if(head==tail){
        printf("the queue is empty\n");
        return;
    }
    head=(head+1)%MAXN;
    return;
}

void Push(int x){
    if((tail+2)%MAXN==head){
        printf("the queue is full\n");
        return;
    }
    qe[tail]=x;
    tail=(tail+1)%MAXN;
}

bool BFS(int i){
    Clear();
    Push(i);
    tag[i]=0;
    while(!IsEmpty()){
        int now=Top();
        Pop();
        for(int pos=first[now];pos!=-1;pos=adj[pos]){
            int nex=to[pos];
            if(tag[nex]==tag[now]){
                return false;
            }
            if(tag[nex]==-1){
                tag[nex]=1-tag[now];
                Push(nex);
            }
        }
    }
    return true;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
        Init();
        scanf("%d%d",&N,&M);
        for(int mi=0;mi<M;mi++){
            int u,v;
            scanf("%d%d",&u,&v);
            Add(u,v);
            Add(v,u);
        }
        bool flag=true;
        for(int i=1;i<=N;i++){
            if(-1==tag[i]){
                flag=BFS(i);
            }
            if(!flag)break;
        }
        if(flag)printf("Correct\n");
        else printf("Wrong\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
