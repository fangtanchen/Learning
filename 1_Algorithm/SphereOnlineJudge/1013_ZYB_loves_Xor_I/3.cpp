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

struct Node{
    int ch[2];
    int cnt;
    Node(){
        ch[0]=ch[1]=-1;
        cnt=0;
    }
};

const int MAXN=1e5;
const int MODU=998244353;

int A[MAXN];
Node trie[MAXN];
int cnt_nodes;
int T,N;

void Insert(int rt,int x,int depth){
    if(depth>=30){
        return;
    }
    int kk=x&0x1;
    if(-1==trie[rt].ch[kk]){
        trie[cnt_nodes].ch[0]=trie[cnt_nodes].ch[1]=-1;
        trie[cnt_nodes].cnt=0;
        trie[rt].ch[kk]=cnt_nodes++;
    }
    trie[trie[rt].ch[kk]].cnt+=1;
    Insert(trie[rt].ch[kk],x>>1,depth+1);
}

int ans;
int Query(int rt,int x,int k){
    int ret=0;
    int lowbit=x&0x1;
    int v=lowbit^1;
    if(-1!=trie[rt].ch[v]){
        ret+=(trie[trie[rt].ch[v]].cnt*k);
        ret%=MODU;
    }
    if(-1!=trie[rt].ch[lowbit]){
         ret+=Query(trie[rt].ch[lowbit],x>>1,k<<1);
    }
    ret%=MODU;
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        memset(trie,-1,sizeof(trie));
        cnt_nodes=1;
        int root=0;
        trie[root].ch[0]=trie[root].ch[1]=-1;
        trie[root].cnt=0;

         ans=0;
         scanf("%d",&N);
         for(int ni=0;ni<N;ni++){
             int a;
             scanf("%d",&a);
             ans+=Query(root,a,1);
             ans%=MODU;
             Insert(root,a,0);
         }
         printf("Case #%d: %d\n",ti,(ans*2)%MODU);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
