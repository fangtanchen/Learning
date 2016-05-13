#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<stack>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAX_SIZE 10

int N,M,T;
bool visited[ MAX_SIZE ][MAX_SIZE ];
char map[MAX_SIZE ][MAX_SIZE ];
int st_ri,st_ci;
int end_ri,end_ci;
bool ans;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};


class CPos{
	public:
		int ri;
		int ci;
		int ti;
		CPos(){}
		CPos(const CPos &p){
			ri=p.ri;ci=p.ci;ti=p.ti;
		}
		CPos(int a,int b,int c){
			ri=a;ci=b;ti=c;
		}
};

bool InMap(int ri,int ci){
	return ((ri>=1)&&(ri<=N)&&(ci>=1)&&(ci<=M)
			&&(map[ri][ci]!='X'));
}

int DFS(){
	int ti=0;
	memset(visited,false,sizeof(visited));
	stack<CPos> seq;
	seq.push(CPos(st_ri,st_ci,0));
	//visited[st_ri][st_ci]=true;
	while(!seq.empty()){
		CPos np(seq.top());
		if((np.ti==T)
			&&(map[np.ri][np.ci]=='D')){
			ans=true;
			return 1;
		}

		int kkp=T-np.ti-abs(end_ri-np.ri)-abs(end_ci-np.ci);
		if(visited[np.ri][np.ci]||(kkp<0)||(kkp%2)
		||(np.ti==T)||(map[np.ri][np.ci]=='D')){
			seq.pop();
			visited[np.ri][np.ci]=false;
			continue;
		}

		visited[np.ri][np.ci]=true;

		int temp_ti=np.ti+1;
		for(int di=0;di<4;di++){
			int temp_ri=np.ri+dir[di][0];
			int temp_ci=np.ci+dir[di][1];
			if(InMap(temp_ri,temp_ci)
			&&(!visited[temp_ri][temp_ci])){
				seq.push(CPos(temp_ri,temp_ci,temp_ti));
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
	while(EOF!=scanf("%d%d%d",&N,&M,&T),N||M||T){
		st_ri=st_ci=0;
		end_ri=end_ci=0;
		for(int ni=1;ni<=N;ni++){
			scanf("%s",map[ni]+1);
			if((st_ri||st_ci)&&(end_ri||end_ci))continue;
			for(int mi=1;mi<=M;mi++){
				if(map[ni][mi]=='S'){
					st_ri=ni;
					st_ci=mi;
				}else if(map[ni][mi]=='D'){
					end_ri=ni;
					end_ci=mi;
				}
			}
		}
		ans=false;
		DFS();
		if(ans){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
