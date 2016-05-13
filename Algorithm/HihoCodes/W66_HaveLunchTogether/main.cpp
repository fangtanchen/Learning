#include <iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//#define ONLINE_JUDGE
//#define USER_DEBUG
#ifndef ONLINE_JUDGE
#pragma warning(disable:3399)
#endif

int N,M;
char map[101][101];
int step[101][101];

bool inMap(int x, int y){
	return (1<=x&&x<=N&&1<=y&&y<=M)
	&&(map[x][y]=='.'||map[x][y]=='S');
}

const int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
vector<pair<int, int> > seq;

void BFS(int startX, int startY){
	step[startX][startY]=0;
	seq.push_back(make_pair(startX,startY));
	
	int i=0;
	while(i<(int)seq.size()){
		for(int dr=0;dr<4;++dr){
			int tempX=seq[i].first+dir[dr][0];
			int tempY=seq[i].second+dir[dr][1];
			
			if(inMap(tempX,tempY)
			&&step[tempX][tempY]==INT_MAX){
				step[tempX][tempY]=step[seq[i].first][seq[i].second]+1;
				if(map[tempX][tempY]!='S'){
					seq.push_back(make_pair(tempX,tempY));
				}
			}
		}
		++i;
	}
	return ;
	
}


int main(int argc, char** argv) {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int startX,startY;
	startX=startY=0;
	cin>>N>>M;
	
	//input the map
	for(int i=1;i<=N;i++){
		scanf("%s",map[i]+1);
	}
	
	//find the start point
	{
		int flag=1;
		for(int i=1;flag&&(i<=N);i++){
			for(int j=1;j<=M;j++){
				if(map[i][j]=='H'){
					startX=i;
					startY=j;
					flag=0;
					break;
				}
			}
		}
	}
	//memset(step,INT_MAX,sizeof(step));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			step[i][j]=INT_MAX;
		}
	}
	BFS(startX,startY);
	
	int ret=INT_MAX;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(map[i][j]=='S'&&step[i][j]!=0){
				if(map[i-1][j]=='S'&&step[i-1][j]!=0
				&&ret>step[i][j]+step[i-1][j])
					ret=step[i][j]+step[i-1][j];
				
				if(map[i][j-1]=='S'&&step[i][j-1]!=0
				&&ret>step[i][j]+step[i][j-1])
					ret=step[i][j]+step[i][j-1];
			}
		}
	}
	cout<<ret<<endl;
	#ifndef ONLINE_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif
	return 0;
}
