#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<queue>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e6+10;
const int MAXS=26;

char str[MAXN];
int T,N;
int root=0;

struct UNode{
    static int tot;
    int nxt[MAXS];
    int fail;
    int count;
    void newnode(){
        memset(nxt,-1,sizeof(nxt));
        fail=-1;
        count=0;
    }
}nodes[MAXN];

int UNode::tot=0;

void Add(char s[]){
    int p=root;
    for(int i=0;s[i];i++){
        int k=s[i]-'a';
        if(nodes[p].nxt[k]==-1){
            nodes[++UNode::tot].newnode();
            nodes[p].nxt[k]=UNode::tot;
        }
        p=nodes[p].nxt[k];
    }
    nodes[p].count+=1;
}

void GetFail(){
    queue<int> Q;
    Q.push(root);
    nodes[root].fail=root;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int j=0;j<26;j++){
            if(nodes[u].nxt[j]==-1)continue;
            int v=nodes[u].nxt[j];
            if(u==root)nodes[v].fail=root;
            else{
                int p=nodes[u].fail;
                while(p!=root&&nodes[p].nxt[j]==-1)
                    p=nodes[p].fail;
                nodes[v].fail=(nodes[p].nxt[j]==-1?root:nodes[p].nxt[j]);
            }
            Q.push(v);
        }
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         scanf("%d",&N);
         nodes[root].newnode();
         UNode::tot=0;
         for(int i=0;i<N;i++){
             char s[100];
             scanf("%s",s);
             Add(s);
         }
         GetFail();
         scanf("%s",str);
         int p=root;
         int ans=0;
         for(int i=0;str[i];i++){
             int k=str[i]-'a';
             while((p!=root)&&(nodes[p].nxt[k]==-1)){
                 p=nodes[p].fail;
                 if(nodes[p].count>0){
                     ans+=nodes[p].count;
                     nodes[p].count=-1;
                 }
             }
             p=(nodes[p].nxt[k]==-1?root:nodes[p].nxt[k]);
             if(nodes[p].count>0){
                  ans+=nodes[p].count;
                  nodes[p].count=-1;
             }
         }
         printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
