#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+20;
const int MAXM=5e5+10;

int T,N,M;
int top,adj[MAXM],first[MAXN],to[MAXM];
int in[MAXN];
bool vis[MAXN];
queue<int> qe;

void Init(){
    while(!qe.empty())qe.pop();
     memset(vis,false,sizeof(vis));
     memset(in,0,sizeof(in));
     top=0;
     memset(adj,-1,sizeof(adj));
     memset(first,-1,sizeof(first));
     memset(to,-1,sizeof(to));
}

int Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top;
    top++;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
        Init();
         scanf("%d%d",&N,&M);
         for(int i=1;i<=M;i++){
              int u,v;
              scanf("%d%d",&u,&v);
              Add(u,v);
              in[v]++;
         }
         int sta=0;
         for(int i=1;i<=N;i++){
             if(in[i]==0) {
                 qe.push(i);
                 sta++;
             };
         }
         while(!qe.empty()){
             int now=qe.front() ;
             qe.pop();
             for(int pos=first[now];pos!=-1;pos=adj[pos]){
                  int nex=to[pos];
                  in[nex]--;
                  if(in[nex]==0){
                      qe.push(nex);
                      sta++;
                  }
             }
         }
         if(sta==N)printf("Correct\n");
         else printf("Wrong\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
