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

#define MAX 1002
char path[2*MAX+3];
char ans[2*MAX+3];
int ans_cnt;
const int dir[2][2]={{1, 0}, {0, 1}};
char w[5]="DR";
bool visited[MAX];
int map[MAX][MAX];
int mzero[MAX][MAX];
int n;

void init(){
	ans_cnt=10000000;
	memset(ans, 0, sizeof(ans));
	memset(path, 0, sizeof(path));
	memset(visited, false, sizeof(visited));
	memset(mzero, 0, sizeof(mzero));
}

bool InMap(int ri, int ci){
	return (ri>=1)&&(ri<=n)&&(ci>=1)&&(ci<=n);
}

int DFS(int ri, int ci, int mu, int cnt){
	if((ri==n)&&(ci==n)){
		if(cnt<ans_cnt){
			ans_cnt=cnt;
			path[ri+ci-2]=0;
			strcpy(ans, path);
		}
		return 0;
	}

	for(int di=0;di<2;di++){
		int tempx=ri+dir[di][0];
		int tempy=ci+dir[di][1];
		if(InMap(tempx, tempy)){
			int tempmu=mu*map[tempx][tempy];
			int kk=0;
			while(tempmu%10==0){
				kk++;
				tempmu/=10;
			}
			int tempcnt=cnt+kk+mzero[tempx][tempy];
			path[ri+ci-2]=w[di];
			DFS(tempx, tempy, tempmu, tempcnt);
		}
	}
	return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	while(EOF!=scanf("%d", &n)){
		init();
		for(int ri=1;ri<=n;ri++){
			for(int ci=1;ci<=n;ci++){
				scanf("%d", map[ri]+ci);
				while(map[ri][ci]%10==0){
					mzero[ri][ci]++;
					map[ri][ci]/=10;
				}
			}
		}
		DFS(1, 1, map[1][1], mzero[1][1]);
		printf("%d\n", ans_cnt);
		printf("%s\n", ans);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
