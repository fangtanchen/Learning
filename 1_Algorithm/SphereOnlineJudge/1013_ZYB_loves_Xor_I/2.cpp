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

Node trie[MAXN];
int cnt_nodes;
int T,N;

void Insert(int rt,int x){
    if(0==x)return;
    int kk=x&0x1;
    if(-1==trie[rt].ch[kk]){
        trie[rt].ch[kk]=cnt_nodes++;
        trie[trie[rt].ch[kk]].cnt=0;
        trie[trie[rt].ch[kk]].ch[0]=-1;
        trie[trie[rt].ch[kk]].ch[1]=-1;
    }
    trie[trie[rt].ch[kk]].cnt+=1;
    Insert(trie[rt].ch[kk],x>>1);
}

int ans;
void Query(int rt,int k){
    if((-1!=trie[rt].ch[0])&&(-1!=trie[rt].ch[1])){
        long long int tmp=trie[trie[rt].ch[0]].cnt
            *trie[trie[rt].ch[1]].cnt;
        tmp=tmp*(1<<k)%MODU;
        ans=(2*tmp+ans)%MODU;
        ans%=MODU;
    }
    if(-1!=trie[rt].ch[0]){
        Query(trie[rt].ch[0],k+1);
    }
    if(-1!=trie[rt].ch[1]){
        Query(trie[rt].ch[1],k+1);
    }
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

         scanf("%d",&N);
         int cnt0=0;
         for(int ni=0;ni<N;ni++){
             int a;
             scanf("%d",&a);
             if(0==a){
                 cnt0++;
                 continue;
             }
             Insert(root,a);
         }
         int rt=0;
         while(-1!=trie[rt].ch[1]){
             if(-1==trie[rt].ch[0]){
                 trie[cnt_nodes].ch[0]=trie[cnt_nodes].ch[1]=-1;
                 trie[cnt_nodes].cnt=0;
                 trie[rt].ch[0]=cnt_nodes++;
             }
             trie[trie[rt].ch[0]].cnt+=cnt0;
             rt=trie[rt].ch[0];
         }
         ans=0;
         Query(root,0);
         printf("Case #%d: %d\n",ti,ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
