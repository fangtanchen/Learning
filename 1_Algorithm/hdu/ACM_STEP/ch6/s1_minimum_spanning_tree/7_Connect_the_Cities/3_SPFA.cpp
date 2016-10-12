#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=510;
const int MAXM=25010;
const int MAXK=110;
const int INF=0x3f3f3f3f;

struct Node{
     int i,j,l;
     friend bool operator<(const Node x,const Node y){
         return x.l>y.l;
     }
};

int fa[MAXN];
priority_queue<Node> que;



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int cases,N,M,K;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d%d%d",&N,&M,&K);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
