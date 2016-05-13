#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
//#include<queue>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

class CPath{
	public:
		int ri;
		int ci;
		int num;
		int pn;//means previous path number before (ci,ri) in the queue
		int ti;
		CPath(int a,int b, int c, int d,int e){
			ri=a;
			ci=b;
			num=c;
			pn=d;
			ti=e;
		}
		CPath(){}
};

#define MAX_SIZE 10
int N,M,T;
char map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE][2];
int st_ri,st_ci;
int res;
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int InMap(int ri,int ci,int ti){
	return (ri<=N)&&(ri>=1)&&(ci>=1)
		&&(ci<=M)&&(ti<=T)&&(map[ri][ci]!='#');
}

int BFS(vector<CPath> &path){
//	vector<CPath> path;
	CPath st(st_ri,st_ci,0,0,0);
	visited[st_ri][st_ci][0]=true;
	path.push_back(st);

	int pi=0;
	while(pi<(int)path.size()){
		if(map[path[pi].ri][path[pi].ci]=='E'
		&&(path[pi].num)){
		//&&(visited[path[pi].ri][path[pi].ci][1])){//condition error
			int kk=pi;
			for(int tt=path.size()-1;tt>=0;tt--){
				if(tt==kk){
					kk=path[kk].pn;
				}else{
					path.erase(path.begin()+tt);
				}
			}

			return path.size();
		}
		
		int temp_num=path[pi].num;
		int temp_pn=pi;
		int temp_ti=path[pi].ti+1;
		for(int di=0;di<4;di++){
			int temp_ri=path[pi].ri+dir[di][0];
			int temp_ci=path[pi].ci+dir[di][1];
			if(InMap(temp_ri,temp_ci,temp_ti)){
				if(path[pi].num==1){					
					if(!visited[temp_ri][temp_ci][1]){
						visited[temp_ri][temp_ci][1]=true;			
						path.push_back(CPath(temp_ri,temp_ci,
										1,temp_pn,temp_ti));
					}
				}else{
					if(!visited[temp_ri][temp_ci][0]){
						temp_num=((map[temp_ri][temp_ci]=='J')?1:0);
						if(!visited[temp_ri][temp_ci][temp_num]){
							visited[temp_ri][temp_ci][temp_num]=true;
							path.push_back(CPath(temp_ri,temp_ci,
										temp_num,temp_pn,temp_ti));
						}
					}			
				}
			}
		}

		pi++;
	}

	return -1;

}

int DFS(int level){
	if(level>=res){
		return 0;
	}

	memset(visited,false,sizeof(visited));
	vector<CPath> path;
	int ret_res=BFS(path);
	#ifdef U_DEBUG
		printf("11\n");
		for(int ii=0;ii<path.size();ii++){
			printf("%d %d %d %d %d\n",path[ii].ri,path[ii].ci,
						path[ii].pn,path[ii].num,path[ii].ti);
		}
		printf("\n\n");
	#endif
	if(ret_res<0){
		if(level<res)
		  res=level;
		return level;
	}
	int pathi_max=path.size()-1;
	for(int i=1;i<pathi_max;i++){
		char store_ch=map[path[i].ri][path[i].ci];
		map[path[i].ri][path[i].ci]='#';
		DFS(level+1);
		map[path[i].ri][path[i].ci]=store_ch;
	}
	return 0;
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
		st_ri=st_ci=0;
		for(int ri=1;ri<=N;ri++){
			scanf("%s",map[ri]+1);
			if(st_ri||st_ci)continue;
			for(int ci=1;ci<=M;ci++){
				if(map[ri][ci]=='S'){
					st_ri=ri;
					st_ci=ci;
				}
			}
		}
		res=4;
		DFS(0);
		printf("%d\n",res);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
