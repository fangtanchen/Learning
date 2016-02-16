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

int N,M,T;

int BFS(){

}

int DFS(int level, char* map[]){
	vector<pair<int, int> > path;

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int C;
	scanf("%d",&C);
	while(C--){
		scanf("%d%d%d",&N,&M,&T);
		char map[10][10];
		for(int ri=1;ri<=N;ri++){
			scanf("%s",map[ri]+1);
		}
		DFS(0,map);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
