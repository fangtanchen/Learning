#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAX_SIZE 55

int n;
int p[4];
char map[MAX_SIZE][MAX_SIZE];
int step[4][MAX_SIZE];


void BFS(int pi){
	int st_pos=p[pi];
	char color=map[st_pos][st_pos];
	bool visited[MAX_SIZE];

	memset(visited,false,sizeof(visited));
	visited[st_pos]=true;
	step[pi][st_pos]=0;

	vector<int> qe;
	qe.push_back(st_pos);
	int qi=0;
	while(qi<(int)qe.size()){
		int now_pos=qe[qi];
		for(int ni=1;ni<=n;ni++){
			if((!visited[ni])&&(map[now_pos][ni]==color)){
				visited[ni]=true;
				qe.push_back(ni);
				step[pi][ni]=step[pi][now_pos]+1;
			}
		}
		qi++;
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%d",&n),n){
		//getchar();
		for(int ni=1;ni<=3;ni++){
			scanf("%d",&p[ni]);
			//getchar();	
		}
		getchar();
		for(int ni=1;ni<=n;ni++){
			cin.getline(map[ni]+1,MAX_SIZE,'\n');
			for(int nj=1;nj<=n;nj++){
				map[ni][nj]=map[ni][2*nj-1];
			}
		}
		

		memset(step,-1,sizeof(step));
//		memset(visited,false,sizeof(visited));
		for(int pi=1;pi<=3;pi++){
			BFS(pi);
		}
		int sum=100000000;
		for(int ni=1;ni<=n;ni++){
			if((step[1][ni]>=0)&&(step[2][ni]>=0)
			&&(step[3][ni]>=0)){
				int temp=step[1][ni]+step[2][ni]+step[3][ni];
				if(sum>temp)sum=temp;
			}
		}

		if(sum==100000000){
			printf("impossible\n");
		}else{
			printf("%d\n",sum);
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}


