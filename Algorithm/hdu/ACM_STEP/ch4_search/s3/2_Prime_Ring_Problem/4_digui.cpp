#include<iostream>
#include<cstdio>
#include<cstring>


int n;
int prime_table[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int map[]={
		0,0,1,1,0,1,0,1,0,0,
		0,1,0,1,0,0,0,1,0,1,
		0,0,0,1,0,0,0,0,0,1,
		0,1,0,0,0,0,0,1,0,0,
		0,1,0,1,0,0,0,1,0,0
};
#define MAX_SIZE 33
bool visited[MAX_SIZE];
int path[MAX_SIZE];

int DFS(int root,int level){
	path[level]=root;
	if(level==n){
		if(map[root+1]){
			printf("%d",path[1]);
			for(int i=2;i<=n;i++){
				printf(" %d",path[i]);
			}
			printf("\n");
		}
		return 0;
	}
	
	for(int ni=2;ni<=n;ni++){
		if(!visited[ni]&&map[ni+root]){
			visited[ni]=true;
			DFS(ni,level+1);
			visited[ni]=false;
		}
	}

	return 0;
}

int main(){
	int casei=1;
	while(EOF!=scanf("%d",&n)){
		printf("Case %d:\n",casei++);
		if(n>1&&(n%2)){
			;
		}else{
			memset(visited,0,sizeof(visited));
			visited[1]=true;
			DFS(1,1);
		}

		printf("\n");
	}
	
	return 0;
}

