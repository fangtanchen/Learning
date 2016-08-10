#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e4+10;
const int INF=0x1fffffff;
struct Node{
    int pi;
    int qi;
    int pay;
    int ret;
    Node(){
        pi=qi=pay=ret=0;
    }
};

struct Record{
    int qt;
    int pt;
};

Node trees[MAXN];
Record rec[MAXN];
vector<int> G[MAXN];
int in[MAXN];
int N;

int cmp(Record x,Record y){
    return x.qt>y.qt;
}

void Init(){
    memset(in,0,sizeof(in));
    for(int i=0;i<MAXN;i++){
        G[i].clear();
    }
}
void PostOrder(int id){
    if(G[id].size()==0){
        trees[id].pay=trees[id].pi;
        trees[id].ret=trees[id].qi;
        return;
    }
    for(int i=G[id].size()-1;i>=0;i--){
        int child=G[id][i];
        PostOrder(child);
    }
    for(int i=0;i<G[id].size();i++){
         int child=G[id][i];
         rec[i].pt=trees[child].pay;
         rec[i].qt=trees[child].ret;
    }
    sort(rec,rec+G[id].size(),cmp);
    int wallet=INF;
    int min_wallet=INF;
    wallet-=trees[id].pi;
    if(min_wallet>wallet){
        min_wallet=wallet;
    }
    wallet+=trees[id].qi;
    for(int i=0;i<G[id].size();i++){
        wallet-=rec[i].pt;
        if(min_wallet>wallet){
             min_wallet=wallet;
        }
        wallet+=rec[i].qt;
    }
    trees[id].pay=INF-min_wallet;
    trees[id].ret=wallet-min_wallet;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
//    cin.sync_with_stdio(false);
    Init();
    cin>>N;
    for(int i=1;i<=N;i++){
         cin>>trees[i].pi>>trees[i].qi;
    }
    for(int i=1;i<N;i++){
         int a,b;
         cin>>a>>b;
         if(a>b)swap(a,b);
         G[a].push_back(b);
         in[b]++;
    }
    for(int i=1;i<=N;i++){
        if(!in[i]){
            PostOrder(i);
            printf("%d\n",trees[i].pay);
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}

