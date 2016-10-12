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
const int MAXN=1000010;
const int MAXO=2000020;

struct Node{
     int l,r;
     int minweight;
     Node *lch,*rch,*fa;

     Node(int weight,int a,int b){
         minweight=weight;
         lch=rch=fa=NULL;
         l=a;
         r=b;
     }
};

Node nodes[MAXP];
int numnodes;
int N,Q;

void GenerateTree(int st,int )

int DFS(,int len){
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=1;i<=N;i++){

    }
    numnodes=N;
    DFS(1,N);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
