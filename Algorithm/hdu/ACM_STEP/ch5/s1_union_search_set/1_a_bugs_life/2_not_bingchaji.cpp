#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define SIZE 2005
vector<int> map[SIZE];
bool ans;
int sex[SIZE];

int DFS(int root){
	int cmax=map[root].size();
	for(int ci=0;(ci<cmax)&&ans;ci++){
		int ch=map[root][ci];
		if(0==sex[ch]){
			sex[ch]=3-sex[root];
			DFS(ch);
		}else{
			if(sex[ch]==sex[root]){
				ans=false;
				return 0;
			}
		}
	}

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
		scanf("%d%d", &n, &m);
		ans=true;
		memset(sex, 0, sizeof(sex));
		for(int i=0;i<=n;i++){
			map[i].clear();
		}
		int a, b;
		for(int mi=1;mi<=m;mi++){
			scanf("%d%d", &a, &b);
			map[a].push_back(b);
			map[b].push_back(a);
		}

		for(int ni=1;(ni<=n)&&ans;ni++){
			if(0==sex[ni]){
				sex[ni]=1;
				DFS(ni);
			}
		}
		if(ans)printf("No suspicious bugs found!\n\n");
		else  printf("Suspicious bugs found!\n\n");
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
