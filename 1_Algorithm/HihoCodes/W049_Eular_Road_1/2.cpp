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

int first[MAXN],adj[MAXM],to[MAXM],top;
int degree[MAXN];
int N,M;

void Init(){
     memset(first,-1,sizeof(first));
     memset(adj,-1,sizeof(adj));
     memset(to,-1,sizeof(to));
     top=0;
     memset(degree,0,sizeof(degree));
}

void Add(int u,int v){
     adj[top]=first[u];
     to[top]=v;
     first[u]=top++;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    Init();
    for(int mi=0;mi<M;mi++){
         int u,v;
         scanf("%d%d",&u,&v);
         //Add(u,v);
         //Add(v,u);
         degree[u]++;
         degree[v]++;
    }
    int ans=0;
    for(int ni=1;ni<=N;ni++){
        if(degree[ni]%2) ans++;
    }
    if(ans==0||ans==2){
         printf("Full\n");
    }else{
        printf("Part\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
