#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=10010;
const int MAXC=1000010;

int n,m,c;
int vis[MAXN];
int depth[MAXN];
int in[MAXN];
vector<int> G[MAXN];
int fa[MAXN];

int ques[MAXC][2];
vector<int> sta[MAXN];
map<pair<int,int>,int> ans;
map<pair<int,int>,int> len;

void Init(){
     memset(vis,0,sizeof(vis));
     memset(in,0,sizeof(in));
     for(int i=1;i<=n;i++){
         G[i].clear();
         sta[i].clear();
         fa[i]=i;
     }
     ans.clear();
     len.clear();
}

int Find(int x){
    int fx=fa[x];
    if(x==fx)return fx;
    fa[x]=Find(fx);
    return fa[x];
}

void PostOrder(int id){
    vis[id]=1;
    for(int i=sta[id].size()-1;i>=0;i--){
        int k=sta[id][i];
        int a=id,b=k;
        if(a>b)swap(a,b);
        if(vis[k]==1){
            ans[make_pair(a,b)]=k;
        }else if(vis[k]==2){
            int tt=Find(k);
            ans[make_pair(a,b)]=tt;
        }
    }
    for(int i=G[id].size()-1;i>=0;i--){
        int k=G[id][i];
        depth[k]=depth[i]+len[make_pair(id,k)];
        PostOrder(k);
        fa[k]=id;
    }
    vis[id]=2;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    while(EOF!=scanf("%d%d%d",&n,&m,&c)){
        Init();
        for(int t=0;t<m;t++){
             int i,j,k;
             scanf("%d%d%d",&i,&j,&k);
             if(i>j)swap(i,j);
             in[j]++;
             G[i].push_back(j);
             len[make_pair(i,j)]=k;
        }
        for(int i=0;i<c;i++){
            int a,b;
             scanf("%d%d",&a,&b);
             if(a>b)swap(a,b);
             ques[i][0]=a;ques[i][1]=b;
             if(a==b){
                 ans[make_pair(a,b)]=a;
             }else{
                 sta[a].push_back(b);
                 sta[b].push_back(a);
             }
        }
        for(int i=1;i<=n;i++){
            if(in[i]==0) {
                memset(vis,0,sizeof(vis));
                depth[i]=0;
                PostOrder(i);
            }
        }
        for(int i=0;i<c;i++){
             int a=ques[i][0],b=ques[i][1];
             if(ans[make_pair(a,b)]==0){
                 printf("Not connected\n");
             }else{
                 printf("%d\n",depth[a]+depth[b]-2*depth[ans[make_pair(a,b)]]);
             }
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
