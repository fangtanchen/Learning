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

#define MAX 2011
int fa[MAX];
int gen[MAX]; //0 means x has same gender as fa[x]; 1 means different
bool mark;

int find(int a){
	if(a==fa[a])
		return a;
	int tem=fa[a];
	int root=find(tem);
	fa[a]=root;
	
	gen[a]=(gen[tem]-gen[a])%2;
	
	return root;
}

int merge(int a, int b){
	int pa=fa[a];
	int pb=fa[b];

	fa[pa]=pb;
	gen[pa]=(gen[a]-gen[b]+1)%2;

	return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int N;
	scanf("%d", &N);
	int casei=1;
	while(N--){
		printf("Scenario #%d:\n", casei++);
		int n, m;
		scanf("%d%d", &n, &m);//n bugs, m interactions
		int a, b;
		for(int ni=0;ni<=n;ni++){
			fa[ni]=ni;
			gen[ni]=0;
		}
		mark=true;
		for(int mi=1;mi<=m;mi++){
			scanf("%d%d", &a, &b);
			if(find(a)==find(b)){
				if(gen[a]==gen[b]){
					mark=false;
				}
			}else{
				merge(a, b);
			}
		}
		
		if(!mark){
			printf("Suspicious bugs found!\n");
		}
		else{
			printf("No suspicious bugs found!\n");
		}

		printf("\n");
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
