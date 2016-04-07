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

#define MAXN 26

struct Node{
    struct Node *nodes[MAXN];
    bool bleaf;
    Node(){
        for(int i=0;i<MAXN;i++){
            nodes=NULL;
        }
        bleaf=false;
    }
};

Node *root;
char path[250];
void init(){
    root=(Node*)malloc(sizeof(Node));
    for(int i=0;i<MAXN;i++)
        root->nodes[i]=NULL;
    root->bleaf=false;
}

bool Search(char* s, struct Node root){
    if(*s==0)return root.bleaf;

    int temp=s[0]-'a';
    if(!(root.nodes[temp]))
        return Search(s+1,root.nodes[temp]);
    return false;
}

bool Traverse(struct Node root, int pi){
    if(root.bleaf){
        path[pi]=0;
        printf("%s\n",path);
    }
    for(int i=0;i<MAXN;i++){
        if(root.nodes[i]){
            path[pi]=i+'a';
            Traverse(root.nodes[i],pi+1);
        }
    }
    return true;
}

int Insert(char* s, Node* root){
    if(0==*s){
        root->bleaf=true;
        return 0;
    }
    if((*s)>='A'&&(*s)<='Z'){
        s[0]=s[0]+32;
    }
    int temp=s[0]-'a';
    if(!root->nodes[temp]){
        root->nodes[temp]=new Node();
        root->nodes[temp].val=temp;
    }
    Insert(s+1,root->nodes[temp]);
    return 0;
}

int Free(Node* root){
    if(!root)return 0;
    for(int i=0;i<MAX;i++){
        if(root->nodes[i]){
            Free(root->nodes[i]);
            root->nodes[i]=NULL;
        }
    }
    free(root);
    return 0;
}

char in[250];

void scan(){
    int ch;
    while((ch=getchar()),
            !((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))){
        ;
    }
    int ini=0;
    in[ini++]=ch;
    while(ch=getchar(),
            (ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
         in[ini++]=ch;
    }
    in[ini]=0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

    init();
    while(scan()){
        if(in[0]==0)break;
        Insert(in,rt);
    }
    Traverse(rt,0);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
