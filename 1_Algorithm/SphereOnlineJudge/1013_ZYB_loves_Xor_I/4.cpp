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
const int MAXN=5e5;
const int MODU=998244353;

struct Node{
    int ch[2];
    int cnt;
}tree[MAXN];

int N,T,ans;
int cnt_nodes;

void Insert(int rt,int x,int depth){
    if(depth>=30)return;
    int bit=x&0x01;
    if(-1==trie[rt].ch[bit])
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
         scanf("%d",&N);
         int root=0;
         cnt_nodes=1;
         int ans=0;
         for(int ni=0;ni<N;ni++){
             int a;
             scanf("%d",&a);
             ans+=Query(root,a,1);
             ans%=MODU;
             Insert(root,a,0);
         }
         printf("Case #%d: %d\n",ti,ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
