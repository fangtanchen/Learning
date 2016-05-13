#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<queue>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

class CPos{
	public:
		int ri;
		int ci;
		int magic;
		int step;
		CPos(int a,int b,int c,int d){
			ri=a;
			ci=b;
			magic=c;
			step=d;
		}
		CPos(const CPos &p){
			ri=p.ri;
			ci=p.ci;
			magic=p.magic;
			step=p.step;
		}
		CPos(){};
};

bool operator > (const CPos &p1, const CPos &p2){
	return p1.step>p2.step;
}



#define MAX_SIZE 82
int N,M,T,P;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool InMap(int ri,int ci,int magic){
	return ((ri>=1)&&(ri<=N)&&(ci>=1)&&(ci<=M)
		  &&(magic>=0)&&(magic<=P)&&(map[ri][ci]!='#'));
}

int BFS(int st_ri,int st_ci){
	CPos st(st_ri,st_ci,P,0);
	priority_queue<CPos, vector<CPos>,greater<CPos> > qe;
	qe.push(st);
	visited[P][st_ri][st_ci]=true;
	while(!qe.empty()){
		CPos now_pos(qe.top());
		qe.pop();
		if(map[now_pos.ri][now_pos.ci]=='L'){
			return now_pos.step;
		}
		
		//int temp_step=now_pos.step+1;
		for(int di=0;di<4;di++){
			int temp_ri=now_pos.ri+dir[di][0];
			int temp_ci=now_pos.ci+dir[di][1];
			
			//if walk
			if((map[now_pos.ri][now_pos.ci]!='@')
			&&(map[temp_ri][temp_ci]!='@')){
				int temp_step=now_pos.step+2;
				int temp_magic=now_pos.magic;
				if(InMap(temp_ri,temp_ci,temp_magic)
				&&(!visited[temp_magic][temp_ri][temp_ci])){
					visited[temp_magic][temp_ri][temp_ci]=true;
					qe.push(CPos(temp_ri,temp_ci,temp_magic,temp_step));
				}
			
			}
			//if fly
			{
				int temp_step=now_pos.step+1;
				int temp_magic=now_pos.magic-1;
				if(InMap(temp_ri,temp_ci,temp_magic)
				&&(!visited[temp_magic][temp_ri][temp_ci])){
					visited[temp_magic][temp_ri][temp_ci]=true;
					qe.push(CPos(temp_ri,temp_ci,temp_magic,temp_step));
				}
			}
		}

	}
	
	return -1;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int casei=1;
	while(EOF!=scanf("%d%d%d%d",&N,&M,&T,&P)){
		printf("Case %d:\n",casei++);
		int st_ri=0,st_ci=0;
		for(int ni=1;ni<=N;ni++){
			scanf("%s",map[ni]+1);
			map[ni][M+1]=0;
			if(st_ri||st_ci)continue;
			for(int mi=1;mi<=M;mi++){
				if('Y'==map[ni][mi]){
					st_ri=ni;
					st_ci=mi;
					break;
				}
			}
		}
		memset(visited,false,sizeof(visited));
		int res=BFS(st_ri,st_ci);
		if(res>=0&&res<=T){
			printf("Yes, Yifenfei will kill Lemon at %d sec.\n",res);
		}else{
			printf("Poor Yifenfei, he has to wait another ten thousand years.\n");
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
