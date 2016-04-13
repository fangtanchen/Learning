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

#define MAX_N 26

typedef struct TrieNode{
	TrieNode* node[MAX_N];
	int cnt;

	TrieNode(){
		cnt = 1;
		for (int i = 0; i < MAX_N; i++){
			node[i] = NULL;
		}
	}
}TrieNode;

TrieNode* rt;

TrieNode* InitNode(){
	rt = (TrieNode*)malloc(sizeof(TrieNode));
	rt->cnt = 1;
	for (int i = 0; i < MAX_N; i++){
		rt->node[i] = NULL;
	}
	return rt;
}

int InsertNode(char* s){
	int len = strlen(s);
	TrieNode* nq = rt;
	TrieNode* p;
	for (int si = 0; si < len; si++){
		int temp = s[si] - 'a';
		if (nq->node[temp] == NULL){
			p = (TrieNode*)malloc(sizeof(TrieNode));
			p->cnt = 1;
			for (int i = 0; i < MAX_N; i++){
				p->node[i] = NULL;
			}
			nq->node[temp] = p;
		}
		else{
			nq->node[temp]->cnt++;
		}
		nq = nq->node[temp];
	}
	return 0;
}

TrieNode* FindNode( char* s){
	int len = strlen(s);
	TrieNode* nq = rt;
	for (int si = 0; si < len; si++){
		int temp = s[si] - 'a';
		if (nq->node[temp] == NULL){
			return NULL;
		}
		else{
			nq = nq->node[temp];
		}
	}
	return nq;
}

int FreeNode(TrieNode* rt){
	if (rt == NULL)return 0;
	for (int i = 0; i < MAX_N; i++){
			FreeNode(rt->node[i]);
	}
	free(rt);
	return 0;
}

int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	char s[15];
	InitNode();
	while (gets(s), strcmp(s, "")){
		InsertNode(s);
	}

	while (gets(s)!=NULL){
		TrieNode* q = FindNode(s);
		if (!q)printf("0\n");
		else printf("%d\n", q->cnt);
	}
	//FreeNode(rt);

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
