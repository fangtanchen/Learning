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
#define MAXC 26
#define MAXN 1010
#define MAXM 1000010



struct TrieNode{
     TrieNode *nodes[MAXC];
     TrieNode *trie;
     bool bleaf;
};


int c2n[257];
char str[MAXM];
int N;
const int nodesize=sizeof(TrieNode);
TrieNode *root;
queue<TrieNode*> qe;

void Init(){
    for(int i='a';i<='z';i++){
        c2n[i]=i-'a';
    }
    root=(TrieNode*)malloc(nodesize);
    root->bleaf=false;
    root->trie=root;
    for(int i=0;i<MAXC;i++){
         root->nodes[i]=NULL;
    }
    while(!qe.empty()){
         qe.pop();
    }
}

void InsertNodes(char *s, TrieNode *rt){
     if(*s==0){
         rt->bleaf=true;
         return;
     }
     int tt=c2n[*s];
     if(rt->nodes[tt]==NULL){
         TrieNode *q=(TrieNode*)malloc(nodesize);
         q->trie=NULL;
         for(int i=0;i<MAXC;i++){
              q->nodes[i]=NULL;
         }
         q->bleaf=false;
         rt->nodes[tt]=q;
     }
     InsertNodes(s+1,rt->nodes[tt]);
     return ;
}

void FreeNode(TrieNode *rt){
    for(int i=0;i<MAXC;i++){
        FreeNode(rt->nodes[i]);
        rt->nodes[i]=NULL;
    }
    free(rt);
}

void CreateGraph(){
    root->trie=root;
    for(int i=0;i<MAXC;i++){
        if(root->nodes[i]){
            root->nodes[i]->trie=root;
            qe.push(root->nodes[i]);
        }else{
             root->nodes[i]=root;
        }
    }
     while(!qe.empty()){
         TrieNode* q=qe.front();
         qe.pop();
         for(int i=0;i<MAXC;i++){
             if(q->nodes[i]){
                 q->nodes[i]->trie=q->trie->nodes[i];
                 q->nodes[i]->bleaf=(q->nodes[i]->bleaf)
                     ||(q->nodes[i]->trie->bleaf);
                 qe.push(q->nodes[i]);
             }else{
                  q->nodes[i]=q->trie->nodes[i];
             }
         }
     }
}

bool SearchGraph(char *s){
    TrieNode* q=root;
    for(int i=0;s[i];i++){
        int tt=c2n[s[i]];
        q=q->nodes[tt];
        if(q->bleaf)return true;
    }
    return false;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d",&N);
    for(int i=0;i<N;i++){
         scanf("%s",str);
         InsertNodes(str,root);
    }
    CreateGraph();
    scanf("%s",str);
    if(SearchGraph(str))printf("YES\n");
    else printf("NO\n");



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
