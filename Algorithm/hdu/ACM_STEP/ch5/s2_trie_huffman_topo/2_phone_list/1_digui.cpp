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
	int temp = s[0] - '0';
	if (rt->node[temp] == NULL){
		TrieNode* p= (TrieNode*)malloc(sizeof(TrieNode));
		rt->node[temp] = p;
		p->b_leaf = false;
		for (int i = 0; i < MAX_N; i++){
			p->node[i] = NULL;
		}
	}
	InsertNode(rt->node[temp], s + 1);
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

	if (s[0] == 0 ){
		ans = false;
		rt->b_leaf = true;
		
		for (int i = 0; i < MAX_N; i++){
			if (rt->node[i] != NULL){
				FreeNode(rt->node[i]);
				rt->node[i] = NULL;
			}
		}
		return 0;
	}
	
	int temp = s[0] - '0';
	if (rt->node[temp]!=NULL)
		FindNode(rt->node[temp], s + 1);
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
