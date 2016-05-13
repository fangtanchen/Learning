#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

bool visited[15][15];
const int dir[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},
					{1,2},{1,-2},{-1,2},{-1,-2}};

class CPos{
	public:
		int ri;
		int ci;
		int step;
		CPos(int a,int b,int c){
			ri=a;
			ci=b;
			step=c;
		}
};

bool InMap(int s0,int s1){
	return ((s0>=1)&&(s0<=8)&&(s1>=1)&&(s1<=8));
}

int BFS(int *st, int *end){
	if((st[0]==end[0])
	&&(st[1]==end[1]))
	  return 0;

	vector<CPos> qe;
	qe.push_back(CPos(st[0],st[1],0));
	int qi=0;
	while(qi<(int)qe.size()){
		for(int di=0;di<8;di++){
			int temp_ri=qe[qi].ri+dir[di][0];
			int temp_ci=qe[qi].ci+dir[di][1];
			int temp_step=qe[qi].step+1;
			
			if(InMap(temp_ri,temp_ci)
			&&(!visited[temp_ri][temp_ci])){
				
				visited[temp_ri][temp_ci]=true;
				qe.push_back(CPos(temp_ri,temp_ci,temp_step));
				if((temp_ri==end[0])
				&&(temp_ci==end[1])){
					return temp_step;
				}
			}

		}
		qi++;
	}

	return -1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	char sa[5],sb[5];
	memset(sa,0,sizeof(sa));
	memset(sb,0,sizeof(sb));
	while(EOF!=scanf("%2c %2c",sa,sb)){
		getchar();
#ifdef U_DEBUG1
	printf("%s %s\n",sa,sb);
#endif
		int ia[2]={sa[0]-'a'+1,sa[1]-'0'};
		int ib[2]={sb[0]-'a'+1,sb[1]-'0'};
		memset(visited,false,sizeof(visited));

		int res=BFS(ia,ib);
		printf("To get from %s to %s takes %d knight moves.\n",
					sa,sb,res);

	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
