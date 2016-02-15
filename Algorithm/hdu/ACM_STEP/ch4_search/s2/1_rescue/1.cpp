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
		int step;
		CPos(int a,int b, int c){
			ri=a;
			ci=b;
			step=c;
		}
		CPos(){
			ri=0;
			ci=0;
			step=-1;
		}
};

bool operator > (const CPos &t1, const CPos &t2){
	return t1.step>t2.step;
}

int N,M;
char map[202][202];
bool visited[202][202];
const int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};


bool inMap(int ri, int ci){
	return ((ri>=1)&&(ri<=N)&&(ci>=1)&&(ci<=M))
		&&(map[ri][ci]!='#');
}

int BFS(int startri,int startci){

	priority_queue< CPos, vector<CPos>, greater<CPos> > qe;
	qe.push(CPos(startri,startci,0));
	while(!qe.empty()){
		CPos now_pos=qe.top();
		qe.pop();
		for(int di=0;di<4;di++){
			int temp_ri=now_pos.ri+dir[di][0];
			int temp_ci=now_pos.ci+dir[di][1];
			if(inMap(temp_ri,temp_ci)
			&&(!visited[temp_ri][temp_ci])){
				visited[temp_ri][temp_ci]=true;
				int temp_step=now_pos.step+1;
				if(map[temp_ri][temp_ci]=='x'){
					temp_step++;
				}else if(map[temp_ri][temp_ci]=='a'){
					return temp_step;
				}
				qe.push(CPos(temp_ri,temp_ci,temp_step));
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

	while(EOF!=scanf("%d%d",&N,&M)){
		memset(map,'#',sizeof(map));
		memset(visited,false,sizeof(visited));

		int startr=0,startc=0;
		for(int ni=1;ni<=N;ni++){
			scanf("%s",map[ni]+1);
			map[ni][M+1]='#';

			if(startr&&startc)continue;
			for(int mi=1;mi<=M;mi++){
				if(map[ni][mi]=='r'){
					startr=ni;
					startc=mi;
				}
			}
		}
		int res=BFS(startr,startc);
		if(res==-1){
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		}else{
			printf("%d\n",res);
		}

#ifdef U_DEBUG1
for(int ni=0;ni<=N+1;ni++){
	for(int mi=0;mi<=M+1;mi++){
		printf("%c",map[ni][mi]);
	}
	printf("\n");
}
printf("\n");
#endif
	}


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
