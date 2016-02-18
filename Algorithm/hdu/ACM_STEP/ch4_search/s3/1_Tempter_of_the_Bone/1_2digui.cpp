#include<iostream>
#include<cstdio>
#include<stack>
#include<cmath>
using namespace std;

class CPos{
	public:
		int ri;
		int ci;
		int ti;
};

#define MAX_SIZE 10
char map[MAX_SIZE][MAX_SIZE];
//bool visited[MAX_SIZE][MAX_SIZE];
bool ans;
int st_ri,st_ci,end_ri,end_ci;
int N,M,T;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool InMap(int ri,int ci){
	return ((ri>=1)&&(ri<=N)&&(ci>=1)
			&&(ci<=M)&&(map[ri][ci]!='X'));
}

int DFS(int ri,int ci,int ti){
	if(ans)return 0;
	if((ri==end_ri)&&(ci==end_ci)){
		if(ti==T){
			ans=true;
		}
		return 1;
	}
	int kkp=T-ti-abs(ri-end_ri)	-abs(ci-end_ci);
	if((kkp<0)&&(kkp%2))return 0;


	map[ri][ci]='X';
	for(int di=0;di<4;di++){
		int temp_ri=ri+dir[di][0];
		int temp_ci=ci+dir[di][1];
		int temp_ti=ti+1;
		if(InMap(temp_ri,temp_ci))
			DFS(temp_ri,temp_ci,temp_ti);
	}
	map[ri][ci]='.';
	return 0;
}

int main(){
	while(EOF!=scanf("%d%d%d",&N,&M,&T),N||M||T){
		st_ri=st_ci=end_ri=end_ci=0;
		for(int ni=1;ni<=N;ni++){
			scanf("%s",map[ni]+1);
			if((st_ri||st_ci)&&(end_ri||end_ci))
			  continue;
			for(int mi=1;mi<=M;mi++){
				if('S'==map[ni][mi]){
					st_ri=ni;
					st_ci=mi;
				}else if('D'==map[ni][mi]){
					end_ri=ni;
					end_ci=mi;
				}
			}
		}
		ans=false;
		DFS(st_ri,st_ci,0);
		if(ans)printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

