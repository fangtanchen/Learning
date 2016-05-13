#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAX_N 26

typedef struct TrieNode{
	TrieNode* node[MAX_N];
	int cnt;
}TrieNode;

//struct TrieNode* root;

TrieNode* InitTrieNode(TrieNode* rt){
	rt = (TrieNode*)malloc(sizeof(TrieNode));
	rt->cnt = 0;
	for (int i = 0; i<MAX_N; i++){
		rt->node[i] = NULL;
	}
	return rt;
}

int InsertTrieNode(TrieNode* rt, char* s){
	if (s[0] == 0)return 0;
	int temp = s[0] - 'a';
	if (rt->node[temp] == NULL){
		TrieNode* q = (TrieNode*)malloc(sizeof(TrieNode));
		q->cnt = 1;
		for (int qi = 0; qi<MAX_N; qi++){
			q->node[qi] = NULL;
		}
		rt->node[temp] = q;
	}
	else{
		rt->node[temp]->cnt++;
	}
	InsertTrieNode(rt->node[temp], s + 1);
	return 0;
}

TrieNode* FindTrieNode(TrieNode* rt, char* s){
	if (0 == s[0])return rt;
	int temp = s[0] - 'a';
	if (rt->node[temp] == NULL)return NULL;

	return FindTrieNode(rt->node[temp], s + 1);
}

int FreeTrieNode(TrieNode* rt){
	if (rt == NULL)return 0;
	for (int i = 0; i<MAX_N; i++){
		FreeTrieNode(rt->node[i]);
	}
	free(rt);
	return 0;
}

TrieNode* root;

int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	char s[15];
	root = InitTrieNode(root);
	while (cin.getline(s, 13, '\n'), s[0] != 0){
		InsertTrieNode(root, s);
	}

	while (EOF != scanf("%s", s)){
		TrieNode* q = FindTrieNode(root, s);
		if (q)printf("%d\n", q->cnt);
		else printf("0\n");
	}
	FreeTrieNode(root);

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
