#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


#define MAX 10

typedef struct TrieNode{
	int cnt;
	TrieNode* node[MAX];
}TrieNode;

int N;
int ans;
TrieNode* root;
int init(){
	ans=1;
	root=(TrieNode*)malloc(sizeof(TrieNode));
	for(int i=0;i<MAX;i++){
		root->node[i]=NULL;
	}
	return 0;
}

int InsertNode(TrieNode* rt, char* s){
	if(s[0]==0){
		rt->cnt++;
		if(ans<rt->cnt){
			ans=rt->cnt;
		}
		return 0;
	}
	
	int temp=s[0]-'0';
	if(rt->node[temp]==NULL){
		TrieNode* q=(TrieNode*)malloc(sizeof(TrieNode));
		q->cnt=0;
		for(int i=0;i<MAX;i++){
			q->node[i]=NULL;
		}
		rt->node[temp]=q;
	}
	InsertNode(rt->node[temp], s+1);
	
	return 0;
}

int FreeNode(TrieNode* rt){
	for(int i=0;i<MAX;i++){
		if(rt->node[i]!=NULL){
			FreeNode(rt->node[i]);
			rt->node[i]=NULL;
		}
	}
	free(rt);
	return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%d", &N))	{
		init();
		char str[40];
		while(N--){
			scanf("%s", str);
			int st=0;
			int len=strlen(str);
			for(st=0;st<len;st++){
				if(str[st]!='0'){
					break;
				}
			}
			if(st==len)st--;
			InsertNode(root, str+st);
		}
		printf("%d\n", ans);
		FreeNode(root);
		root=NULL;
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
