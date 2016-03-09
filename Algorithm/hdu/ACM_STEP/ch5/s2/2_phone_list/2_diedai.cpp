#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAX_N 10

typedef struct TrieNode{
	TrieNode* node[MAX_N];
	bool b_leaf;
}TrieNode;

TrieNode* root;
bool ans = true;

int Init(){
	root = (TrieNode*)malloc(sizeof(TrieNode));
	root->b_leaf = false;
	for (int i = 0; i < MAX_N; i++){
		root->node[i] = NULL;
	}
	ans = true;
	return 0;
}

int InsertNode(TrieNode* rt, char* s){
	if (s[0] == 0){
		{
			rt->b_leaf = true;
		}
		return 0;
	}
	int len = strlen(s);
	TrieNode* np = rt;
	for (int si = 0; si < len; si++){
		int temp = s[si] - '0';
		if (np->node[temp] == NULL){
			TrieNode* q = (TrieNode*)malloc(sizeof(TrieNode));
			q->b_leaf = false;
			for (int i = 0; i < MAX_N; i++){
				q->node[i] = NULL;
			}
			np->node[temp] = q;
		}
		np = np->node[temp];
	}
	np->b_leaf = true;
	return 0;
}


int FreeNode(TrieNode* rt){
	for (int i = 0; i < MAX_N; i++){
		if (rt->node[i] != NULL){
			FreeNode(rt->node[i]);
			rt->node[i] = NULL;
		}
	}
	free(rt);
	return 0;
}



TrieNode* FindNode(TrieNode* rt, char* s){
	
	if (false == ans || rt->b_leaf == true){
		ans = false;
		return 0;
	}
	int len = strlen(s);
	TrieNode* np = rt;
	for (int i = 0; i < len; i++){
		int temp = s[i] - '0';
		if (np->b_leaf == true){
			ans = false;
			return 0;
		}
		if (np->node[temp] == NULL){
			return 0;
		}
		np=np->node[temp];
	}
	{
		ans = false;
		np->b_leaf = true;

		for (int i = 0; i < MAX_N; i++){
			if (np->node[i] != NULL){
				FreeNode(np->node[i]);
				np->node[i] = NULL;
			}
		}
	}

	return NULL;
}





int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--){
		int n;
		scanf("%d", &n);
		Init();
		while (n--){
			char ph[15];
			scanf("%s", ph);
			if (!ans)continue;
  			(FindNode(root, ph));
			if(ans){
				InsertNode(root, ph);
			}
		}
		if (ans)printf("YES\n");
		else printf("NO\n");
		FreeNode(root);
		root = NULL;
	}


#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
