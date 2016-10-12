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
const int MAXM=100010;
const int MAXC=10010;

struct Node{
    int u,v,c;
    Node(){
         u=v=c=0;
    }
}edges[MAXM];

int N,M;
bool bloop[MAXN];
bool bchosen[MAXM];
int cost[MAXN];
int fa[MAXN];

void Init(){
    memset(bloop,false,sizeof(bloop));
    memset(bchosen,false,sizeof(bchosen));
    memset(edges,0,sizeof(edges));
    memset(cost,0,sizeof(cost));
    for(int i=0;i<MAXN;i++){
         fa[i]=i;
    }
}

int Find(int x){
     if(x==fa[x])return x;
     fa[x]=Find(fa[x]);
     return fa[x];
}

bool cmp(Node x,Node y){
    return x.c>y.c;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    while(cin>>N>>M,N||M){
        Init();
        for(int mi=0;mi<M;mi++){
            cin>>edges[mi].u>>edges[mi].v>>edges[mi].c;
        }
        sort(edges,edges+M,cmp);
        for(int mi=0;mi<M;mi++){
             int pa=Find(edges[mi].u);
             int pb=Find(edges[mi].v);
             if(pa>pb)swap(pa,pb);
             if((pa==pb)&&(!bloop[pa])){
                 cost[pa]+=edges[mi].c;
                 bloop[pa]=true;
             }
             if((pa!=pb)&&((!bloop[pa])||(!bloop[pb]))){
                 fa[pb]=pa;
                 cost[pa]=cost[pa]+cost[pb]+edges[mi].c;
                 if(bloop[pb])bloop[pa]=true;
             }
             //bchosen[mi]=true;
        }
/*        for(int mi=0;mi<M;mi++){
             if(bchosen[mi])continue;
             int pa=Find(edges[mi].u);
             if(!bloop[pa]){
                 bloop[pa]=true;
                 cost[pa]+=edges[mi].c;
             }
        }
        */
        int ret=0;
        memset(bloop,false,sizeof(bloop));
        for(int i=0;i<N;i++){
            int pa=Find(i);
            if(bloop[pa])continue;
            ret+=cost[pa];
            bloop[pa]=true;
        }
        cout<<ret<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
