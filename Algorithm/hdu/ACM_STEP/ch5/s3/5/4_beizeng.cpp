#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXL=15;
const int MAXN=1e4+10;
const int MAXC=1e6+10;

int fa[MAXN];
int anc[MAXN][MAXL];
int depth[MAXN];
int len[MAXN];
int in[MAXN];

vector<pair<int,int> > G[MAXN];

int n,m,c;

void Init(){
    for(int i=0;i<MAXN;i++){
        G[i].clear();
        fa[i]=i;
    }
    memset(anc,0,sizeof(anc));
    memset(depth,0,sizeof(depth));
    memset(in,0,sizeof(in));
    memset(len,0,sizeof(len));
}

void Build(int id){
    while(anc[id][0]){
        id=anc[id][0];
    }
    queue<int> qe;
    qe.push(id);
    depth[id]=1;
    len[id]=1;
    while(!qe.empty()){
        int p=qe.front();
        qe.pop();
        for(int i=1;i<MAXL;i++){
            anc[p][i]=anc[anc[p][i-1]][i-1];
        }
        vector<pair<int,int> >::iterator it;
        for(it=G[p].begin();it!=G[p].end();it++){
            int k=(*it).first;
            len[k]=len[p]+(*it).second;
            depth[k]=depth[id]+1;
            qe.push(k);
        }
    }
}

int LCA(int p,int q){
    if(depth[p]<depth[q]){
        swap(p,q);
    }
    for(int i=MAXL-1;i>=0;i--){
        if(depth[anc[p][i]]>=depth[q]){
            p=anc[p][i];
        }
    }
    if(p==q)return p;
    for(int i=MAXL-1;i>=0;i--){
        if(anc[p][i]!=anc[q][i]){
             p=anc[p][i];
             q=anc[q][i];
        }
    }
    return anc[p][0];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    while(~scanf("%d%d%d",&n,&m,&c)){
        Init();
        for(int t=0;t<m;t++){
            int i,j,k;
            scanf("%d%d%d",&i,&j,&k);
            in[j]++;
            anc[j][0]=i;
            G[i].push_back(make_pair(j,k));
        }
        for(int i=1;i<=n;i++){
            if(!in[i]){
                Build(i);
            }
        }
        for(int i=0;i<c;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a==b){
                 printf("0\n");
                 continue;
            }
            int k=LCA(a,b);
            if(k<=0)printf("Not connected\n");
            else{
                printf("%d\n",len[a]+len[b]-2*len[k]);
            }
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
