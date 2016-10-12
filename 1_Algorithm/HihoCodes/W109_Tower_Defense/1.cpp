#include<iostream>
#include<cstdio>
#include<cstring>
<<<<<<< HEAD
#include<vector>
=======
//#include<vector>
>>>>>>> 80aaca46760270e9c10b4e8e4eb506756fe7411a
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
<<<<<<< HEAD
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

Node trees[MAXN];
vector<int> G[MAXN];
int in[MAXN];
int N;

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
    int sum=0;
    int tmp_min=INF;
    for(int i=G[id].size()-1;i>=0;i--){
        int child=G[id][i];
        PostOrder(child);
        sum=sum+trees[child].pay-trees[child].ret;
        tmp_min=min(tmp_min,trees[child].ret);
    }
    sum+=tmp_min;
    trees[id].pay=sum+trees[id].pi-trees[id].qi;
    trees[id].ret=tmp_min;
}
=======
>>>>>>> 80aaca46760270e9c10b4e8e4eb506756fe7411a

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
<<<<<<< HEAD
    cin.sync_with_stdio(false);
    cin>>N;
    Init();
    for(int i=1;i<=N;i++){
         cin>>trees[i].pi>>trees[i].qi;
    }
    for(int i=1;i<N;i++){
         int a,b;
         cin>>a>>b;
         G[a].push_back(b);
         in[b]++;
    }
    for(int i=1;i<=N;i++){
        if(!in[i]){
            PostOrder(i);
            printf("%d\n",trees[i].pay);
        }
    }
=======
>>>>>>> 80aaca46760270e9c10b4e8e4eb506756fe7411a

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
