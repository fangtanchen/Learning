#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int lift[220];
bool visited[220];
const int dir[2]={-1,1};
int N,A,B;

int InMap(int n){
	return ((n>=1)&&(n<=N));
}

int BFS(int start,int end){
	if(start==end){
		return 0;
	}
	vector< pair<int,int> > qe;
	qe.push_back(make_pair(start,0));
	int i=0;
	while(i<(int)qe.size()){
		for(int di=0;di<2;di++){
			int temp_pos=qe[i].first+dir[di]*lift[qe[i].first];
			int temp_cnt=qe[i].second+1;
			if(InMap(temp_pos)
			&&(!visited[temp_pos])){
				visited[temp_pos]=true;
				qe.push_back(make_pair(temp_pos,temp_cnt));
				if(temp_pos==end){
					return temp_cnt;
				}
			}
		}
		i++;
	}

	return -1;
}

int main(){

	
	while(EOF!=scanf("%d",&N),N){
		scanf("%d%d",&A,&B);
		
		
		memset(visited,false,sizeof(visited));

		for(int ni=1;ni<=N;ni++){
			scanf("%d",&lift[ni]);
		}
		int res=BFS(A,B);
		printf("%d\n",res);
	}

	return 0;
}


