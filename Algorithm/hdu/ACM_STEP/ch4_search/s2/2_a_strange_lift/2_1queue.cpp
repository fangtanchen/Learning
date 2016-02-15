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

int N,A,B;
int map[220];
bool visited[220];
const int dir[2]={1,-1};

int InMap(int n){
	return ((n>=1)&&(n<=N));
}

int BFS(int start, int end){
	if(start==end)return 0;

	queue<pair<int, int> > qe;
	qe.push(make_pair(start,0));
//	int cnt=0;
	while(!qe.empty()){
		pair<int, int> pos=qe.front();
		qe.pop();
		//cnt++;
		{
			for(int di=0;di<2;di++){
				int temp_pos=pos.first+dir[di]*map[pos.first];
				int temp_cnt=pos.second+1;
				if(InMap(temp_pos)&&(!visited[temp_pos])){
					visited[temp_pos]=true;
					qe.push(make_pair(temp_pos,temp_cnt));
					if(temp_pos==end){
						return temp_cnt;
					}
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

	while(scanf("%d",&N)!=EOF,N){
		scanf("%d%d",&A,&B);
		
		memset(map,0,sizeof(map));
		memset(visited,false,sizeof(visited));

		for(int i=1;i<=N;i++){
			scanf("%d",&map[i]);
		}
		

		int res=BFS(A,B);
		printf("%d\n",res);
	}


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
