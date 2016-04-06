#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

bool visited[14];
const int MAX_NUM=9;
int path[4][4];
int map[5][5];

int ans=0;


int DFS(int root){
	if(9==root){
		bool flag=true;
		for(int ri=0;ri<3;ri++){
			if(((map[ri][0]+map[ri][1]+map[ri][2]!=15)
				||(map[0][ri]+map[1][ri]+map[2][ri]!=15))){
				return 0;
			}
		}
		if((map[0][0]+map[2][2]!=10)||(map[0][2]+map[2][0]!=10)){
			return 0;
		}
		ans++;
		for(int ri=0;ri<3;ri++){
			for(int ci=0;ci<3;ci++){
				path[ri][ci]=map[ri][ci];
			}
		}
		return 0;
	}
	if(ans>1)return 0;

	int ri=root/3;
	int ci=root%3;
	if(map[ri][ci]){
		DFS(root+1);
	}else{
		for(int i=1;(i<10)&&(ans<=1);i++){
			if(!visited[i]){
				visited[i]=true;
				map[ri][ci]=i;
				DFS(root+1);
				visited[i]=false;
				map[ri][ci]=0;
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
		
	ans=0;
	memset(visited, false, sizeof(visited));
	for(int ri=0;ri<3;ri++){
		for(int ci=0;ci<3;ci++){
			scanf("%d", &map[ri][ci]);
			if(map[ri][ci]){
				visited[map[ri][ci]]=true;
			}
		}
	}
	for(int ri=0;ri<3;ri++){
		for(int ci=0;ci<3;ci++){
			if(map[ri][ci]){
				visited[map[ri][ci]]=true;
				map[2-ri][2-ci]=10-map[ri][ci];
				visited[map[2-ri][2-ci]]=true;
			}
		}
	}

	map[1][1]=5;
	visited[5]=true;
	DFS(0);
	if(ans==1){
		for(int ri=0;ri<3;ri++){
			printf("%d", path[ri][0]);
			for(int ci=1;ci<3;ci++){
				printf(" %d", path[ri][ci]);
			}
			printf("\n");
		}
	}else{
		printf("Too Many\n");
	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
