#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=100010;


struct Node{
    int u,v,w;
    Node(){
        u=v=w=0;
    }
};

Node edge[MAXN];
bool enable[MAXN];

bool vis[MAXN];
vector<pair<int,int> > G[MAXN];
long long int fst[MAXN],snd[MAXN];
int in[MAXN];
int pa[MAXN];
long long int sum[MAXN];
int N,Q,K;



void Init(){
    for(int i=1;i<=N;i++){
        G[i].clear();
    }
    memset(in,0,sizeof(in));
    memset(fst,0,sizeof(fst));
    memset(snd,0,sizeof(snd));
    memset(enable,true,sizeof(enable));
    memset(vis,false,sizeof(vis));
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=N;i++){
        pa[i]=i;
    }
}


int Find(int x){
     if(x==pa[x])return x;
     pa[x]=Find(pa[x]);
     return pa[x];
}


long long int PostTraverse(int u){
    int len=G[u].size();
    if(0==len)return 0;
    int max1=0,max2=0;
    for(int i=0;i<len;i++){
         int v=G[u][i].first;
         int w=G[u][i].second;
         PostTraverse(v);
         int temp=fst[v]+w;
         if(temp>max1){
             max2=max1;
             max1=temp;
         }else if(temp>max2){
              max2=temp;
         }
    }
    fst[u]=max1;
    if(len>1)snd[u]=max2;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    Init();
    for(int i=1;i<N;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
        G[edge[i].u].push_back(make_pair(edge[i].v,edge[i].w));
        in[edge[i].v]++;
    }

     for(int i=1;i<=N;i++){
         if(0==in[i]){
            PostTraverse(i);
         }
     }

    cin>>Q;
    while(Q--){
        memset(enable,true,sizeof(enable));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=N;i++){
            pa[i]=i;
        }
         cin>>K;
         int d;
         while(K--){
             cin>>d;
             enable[d]=false;
         }
         for(int i=1;i<N;i++){
             if(enable[i]){
                 int px=Find(edge[i].u);
                 int py=Find(edge[i].v);
                 pa[py]=px;
             }
         }
         long long int ans=0;
         for(int i=1;i<=N;i++){
             int fa=Find(i);
             if(sum[fa]<fst[i]+snd[i]){
                 sum[fa]=fst[i]+snd[i];
             }
         }
         for(int i=1;i<=N;i++){
              ans+=sum[i];
         }
         cout<<ans<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
