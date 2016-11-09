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
const int MAXN=310;
const int MAXM=20010;

int pt_first[MAXN],pt_adj[MAXM],pt_tox[MAXM],pt_toy[MAXM],pt_top;
int first[MAXN],adj[MAXM],to[MAXM],top;
bool color[MAXN];
int num_color[MAXN];
bool vis[MAXN];
int mp[MAXN];
int N,K;

void Init(){
    memset(pt_first,-1,sizeof(pt_first));
    memset(pt_tox,-1,sizeof(pt_tox));
    memset(pt_toy,-1,sizeof(pt_toy));
    memset(pt_adj,-1,sizeof(pt_adj));
    pt_top=0;

    memset(first,-1,sizeof(first));
    memset(to,-1,sizeof(to));
    memset(adj,-1,sizeof(adj));
    top=0;
    memset(color,false,sizeof(color));
    memset(vis,false,sizeof(vis));
    memset(mp,-1,sizeof(mp));
    memset(num_color,0,sizeof(num_color));
}

void AddPoint(int type,int x,int y){
    pt_adj[pt_top]=pt_first[type];
    pt_tox[pt_top]=x;
    pt_toy[pt_top]=y;
     pt_first[type]=pt_top++;
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
     first[u]=top++;
}

int FindPath(int u){
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(vis[v])continue;
        vis[v]=true;
        if((-1==mp[v])||FindPath(mp[v])){
            mp[u]=v;
            mp[v]=u;
            return 1;
        }
    }
    return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
        while(2==scanf("%d%d",&N,&K),(N||K)){
            Init();
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    int type;
                    scanf("%d",&type);
                    AddPoint(type,i,j);
                    num_color[type]++;
                }
            }
            int ans_cnt=0;
            for(int ci=1;ci<=50;ci++){
                if(0==num_color[ci])continue;
                memset(first,-1,sizeof(first));
                memset(to,-1,sizeof(to));
                memset(adj,-1,sizeof(adj));
                memset(mp,-1,sizeof(mp));

                top=0;
                for(int pos=pt_first[ci];pos!=-1;pos=pt_adj[pos]){
                    int x=pt_tox[pos];
                    int y=pt_toy[pos]+100;
                    Add(x,y);
                    Add(y,x);
                }
                int ans=0;
                for(int i=1;i<=N;i++){
                    if(mp[i]==-1){
                        memset(vis,false,sizeof(vis));
                        vis[i]=true;
                        ans+=FindPath(i);
                    }
                }
                if(ans>K){
                     if(ans_cnt>0)printf(" ");
                     printf("%d",ci);
                     ans_cnt++;
                }
            }
            if(0==ans_cnt)printf("-1");
            printf("\n");
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
