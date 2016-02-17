#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>


using namespace std;

class CPos{
	public:
		int ri;
		int ci;
		int cnt;
		CPos(int r,int c,int s){
			ri=r;
			ci=c;
			cnt=s;
		}
};

bool operator > (const CPos &t1, const CPos &t2){
	return t1.cnt>t2.cnt;
}

int N,M;
char map[202][202];
bool visited[202][202];
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

bool inMap(int ri, int ci){
	if((ri>=1&&ri<=N)&&((ci>=1)&&(ci<=M))
	&&(map[ri][ci]!='#'))
		return true;
	else
		return false;
}

int BFS(int start_ri, int start_ci){
	priority_queue< CPos, vector<CPos>, greater<CPos> > q;
	
	q.push(CPos(start_ri, start_ci,0));
	while(!q.empty()){
		CPos now_pos=q.top();
		q.pop();
		for(int di=0;di<4;di++){
			int temp_ri=now_pos.ri+dir[di][0];
			int temp_ci=now_pos.ci+dir[di][1];
			if(inMap(temp_ri,temp_ci)
			&&(!visited[temp_ri][temp_ci])){
				visited[temp_ri][temp_ci]=true;
				int temp_cnt=now_pos.cnt+1;
				if(map[temp_ri][temp_ci]=='x'){
					temp_cnt++;
				}else if(map[temp_ri][temp_ci]=='a'){
					return temp_cnt;
				}
				q.push(CPos(temp_ri,temp_ci,temp_cnt));
			}
		}
	}
	return -1;
}


int main(){
	while(EOF!=scanf("%d%d",&N,&M)){
		memset(map,'#',sizeof(map));
		memset(visited,false,sizeof(visited));

		int start_ri=0,start_ci=0;
		for(int ni=1;ni<=N;ni++){
			scanf("%s",map[ni]+1);
			map[ni][M+1]='#';
			if(start_ri||start_ci)continue;
			for(int mi=1;mi<=M;mi++){
				if(map[ni][mi]=='r'){
					start_ri=ni;
					start_ci=mi;
				}
			}
		}
		int res=BFS(start_ri,start_ci);
		if(res==-1){
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		}else{
			printf("%d\n",res);
		}

	}
	
	return 0;
}
