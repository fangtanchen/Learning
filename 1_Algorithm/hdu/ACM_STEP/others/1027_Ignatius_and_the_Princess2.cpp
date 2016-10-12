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

#define MAX 1020

bool visited[1020];
int path[1020];
int limit[30];
int N, M;
int cnt;

int init(){
	cnt=0;
	memset(path, 0, sizeof(path));
	memset(visited, false, sizeof(visited));

	return 0;
}


int DFS(int level){
	if(cnt>=M)return 0;

	if(level==N+1){
		cnt++;
		if(cnt==M){
			printf("%d", path[1]);
			for(int i=2;i<=N;i++){
				printf(" %d", path[i]);
			}
			printf("\n");
		}
		return 0;
	}
	int pp=N-level+1;
	if((pp<=8)&&(cnt+limit[pp]<M)){
		cnt=cnt+limit[pp];
		return 0;
	}
	for(int i=1;(i<=N)&&(cnt<M);i++){
		if(!visited[i])	{
			visited[i]=true;
			path[level]=i;
			DFS(level+1);
			visited[i]=false;
		}
	}
	
	return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	limit[1]=1;
	limit[0]=0;
	for(int i=2;i<10;i++){
		limit[i]=i*limit[i-1];
	}
	while(EOF!=scanf("%d%d", &N, &M)){
		init();
		DFS(1);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
