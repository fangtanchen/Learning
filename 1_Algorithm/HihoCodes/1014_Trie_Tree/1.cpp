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

#define MAXC 26

struct Node{
    Node *nodes[MAXC];
    bool bleaf;
    int cnt;
};

Node *root;

void init(){
    root=(Node*)malloc(sizeof(Node));
    for(int i=0;i<MAXC;i++){
        root->nodes[i]=NULL;
    }
    root->cnt=0;
    root->bleaf=false;
}

bool Insert(Node *rt,char *s){
    if(0==s[0]){
        rt->bleaf=true;
        return true;
    }
     int temp=*s-'a';
     if(!rt->nodes[temp]){
         rt->nodes[temp]=(Node*)malloc(sizeof(Node));
         rt->nodes[temp]->bleaf=false;
         rt->nodes[temp]->cnt=0;
         for(int i=0;i<MAXC;i++)
             rt->nodes[temp]->nodes[i]=NULL;
     }
     rt->nodes[temp]->cnt++;
     Insert(rt->nodes[temp],s+1);

     return true;
}

int Search(Node *rt, char *s){
    if(s[0]==0)return rt->cnt;
    int temp=s[0]-'a';
    if(rt->nodes[temp]){
        return Search(rt->nodes[temp],s+1);
    }
    return 0;
}

void Free(Node *rt){
    for(int i=0;i<MAXC;i++){
        if(rt->nodes[i]){
            Free(rt->nodes[i]);
            rt->nodes[i]=NULL;
        }
    }
     free(rt);
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int n;
    scanf("%d",&n);
    char s[100];
    init();
    for(int i=0;i<n;i++){
         scanf("%s",s);
         Insert(root,s);
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
         scanf("%s",s);
         printf("%d\n",Search(root,s));
    }
    Free(root);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
