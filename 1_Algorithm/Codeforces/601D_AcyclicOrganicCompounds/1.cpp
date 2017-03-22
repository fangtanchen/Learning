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
const int MAXN=3e5+10;

struct node{
    struct node *nxt[26];
    int ed;
    node(){
        ed=0;
        memset(nxt,0,sizeof(nxt));
    }
}*tr[MAXN*2];

int sz[MAXN],df[MAXN],c[MAXN];
char str[MAXN];
vector<int> e[MAXN];
int N;

void merge(node *u, int fu,node *v){
    if((!u->ed)&&(v->ed)){
        u->ed=1;
        df[fu]++;
    }
    for(int i=0;i<26;i++){
        if(v->nxt[i]==NULL)continue;
        if(u->nxt[i]==NULL)u->nxt[i]=new node();
        merge(u->nxt[i],fu,v->nxt[i]);
    }
    delete v;
}

void merge(int u,int v){
    if(sz[u]<sz[v]){
        swap(tr[u],tr[v]);
        swap(sz[u],sz[v]);
        df[u]=df[v];
    }
    merge(tr[u],u,tr[v]);
}

void dfs(int u,int fa){
    tr[u]=new node();sz[u]=1;
    for(int i=0;i<(int)e[u].size();i++){
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u);
        merge(u,v);
    }
    node *tmp=new node();
    tr[u]->ed=1;
    tmp->nxt[str[u]-'a']=tr[u];
    tr[u]=tmp;
    sz[u]++;df[u]++;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;i++){
         cin>>c[i];
    }
    cin>>(str+1);
    for(int i=1;i<N;i++){
         int u,v;
         cin>>u>>v;
         e[u].push_back(v);
         e[v].push_back(u);
    }
    dfs(1,0);
    int ans=0;
    int cnt=0;
    for(int i=1;i<=N;i++){
        if(ans<df[i]+c[i]) {
            ans=df[i]+c[i];
            cnt=0;
        }
        if(ans==df[i]+c[i])cnt++;
    }
    printf("%d\n%d\n",ans,cnt);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
