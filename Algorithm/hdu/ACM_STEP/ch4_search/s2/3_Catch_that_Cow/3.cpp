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

#define SIZE 200020
bool visited[SIZE];
const int dir[3][2]={{1,0},{0,1},{0,-1}};
int BFS(int start,int end){

	if(start==end)return 0;

	vector<pair<int,int> > qe;
	qe.push_back(make_pair(start,0));
	int i=0;
	while(i<(int)qe.size()){
		for(int di=0;di<3;di++){
			int temp_pos=qe[i].first*(1+dir[di][0])+dir[di][1];
			int temp_cnt=qe[i].second+1;
			if((temp_pos>=0)&&(temp_pos<SIZE)&&(!visited[temp_pos])){
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
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int N,K;
	while(EOF!=scanf("%d%d",&N,&K)){
		memset(visited,false,sizeof(visited));
		int res=BFS(N,K);
		printf("%d\n",res);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
