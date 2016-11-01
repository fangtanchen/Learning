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
const int MAXN=1e5+10;
const int MAXM=5e5+10;
const int MODN=142857;

int N,M,K;
int A[MAXN];
int top,first[MAXN],adj[MAXM],to[MAXM];
int in[MAXN];
queue<int> qe;

void Init(){
    while(!qe.empty())qe.pop();
    memset(A,0,sizeof(A));
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(to,-1,sizeof(to));
    top=0;
    memset(in,0,sizeof(in));
}

int Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
     first[u]=top++;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d%d",&N,&M,&K);
    for(int ki=0;ki<K;ki++){
         int si;
         scanf("%d",&si);
         A[si]=1;
    }
    for(int mi=0;mi<M;mi++){
        int u,v;
        scanf("%d%d",&u,&v);
        Add(u,v);
        in[v]++;
    }
    for(int i=1;i<=N;i++){
         if(0==in[i])qe.push(i);
    }
    int ans=0;
    while(!qe.empty()){
        int now=qe.front();
        ans=(A[now]+ans)%MODN;
        qe.pop();
        for(int pos=first[now];pos!=-1;pos=adj[pos]){
            int nex=to[pos];
            A[nex]=(A[nex]+A[now])%MODN;
            in[nex]--;
            if(in[nex]==0){
                 qe.push(nex);
            }
        }
    }

    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
