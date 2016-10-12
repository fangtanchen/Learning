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

int N, M;
int pa[50010];
int dist[50010];

int init(){
	memset(dist, 0, sizeof(dist));
	for(int i=1;i<=N;i++){
		pa[i]=i;
	}
}

int find(int x){
	if(x==pa[x])return x;
	int root=find(pa[x]);
	dist[x]=(dist[pa[x]]+dist[x]+300)%300;
	pa[x]=root;
	return root;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	while(EOF!=scanf("%d%d", &N, &M)){
		int R=0;
		init();
		for(int mi=1;mi<=M;mi++){
			int A, B, X;
			scanf("%d%d%d", &A, &B, &X);
			int fA=find(A);
			int fB=find(B);
			if(fA==fB){//judge the true or false;
				if((dist[B]-dist[A]+300)%300!=X){
//					int temp=(dist[B]-dist[A]+300)%300;
//					printf("%d %d %d\n", A, B,temp);
					R++;
				}
			}else{//merge the subtrees
				pa[fB]=fA;
				dist[fB]=(X+dist[A]-dist[B]+600)%300;
			}
		}
		printf("%d\n", R);
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
