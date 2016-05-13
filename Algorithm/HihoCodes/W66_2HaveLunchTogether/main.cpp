#include <iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#pragma warning(disable:3399)
#endif

int M,N;
char map[101][101];

int step[101] [101];
vector< pair<int, int> > seq;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

bool InMap(int x,int y){
	if((x>=1&&x<=N&&y>=1&&y<=M)
	&&(map[x][y]=='S'||map[x][y]=='.'))
		return true;
	else
		return false;
}


void BFS(int startX, int startY){
	step[startX][startY]=0;
	seq.push_back(make_pair(startX,startY));
	int i=0;
	while(i<(int)seq.size()){
		for(int diri=0;diri<4;diri++){
			int tempX=seq[i].first+dir[diri][0];
			int tempY=seq[i].second+dir[diri][1];
			if(InMap(tempX,tempY)&&step[tempX][tempY]==-1){
				step[tempX][tempY]=step[seq[i].first][seq[i].second]+1;
				if(map[tempX][tempY]!='S'){
					seq.push_back(make_pair(tempX,tempY));
				}
			}
		}
		i++;
	}
	
	return;
}

int main(int argc, char** argv) {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin) ;
		freopen("out.txt","w",stdout);
	#endif
	
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		scanf("%s",map[i]+1);
	}
	
	int startX,startY;
	{
		int flag=1;
		for(int i=1;flag&&i<=N;i++){
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
	
	memset(step,-1,sizeof(step));
	
	BFS(startX,startY);
	
	unsigned int ret=0xFFFFFFFF;
	//cout<<ret<<endl;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if('S'==map[i][j]&&-1!=step[i][j]){
				if(map[i-1][j]=='S'&&-1!=step[i-1][j]
				&&ret>step[i][j]+step[i-1][j]){
					ret=step[i][j]+step[i-1][j];
				}
				if(map[i][j-1]=='S'&&-1!=step[i][j-1]
				&&ret>step[i][j]+step[i][j-1]){
					ret=step[i][j]+step[i][j-1];
				}
			}
		}
	}
	if(ret<0xFFFFFFFF){
		cout<<ret<<endl;
	}
	else cout<<"Hi and Ho will not have lunch."<<endl;
	
	#ifndef ONLINE_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif
	return 0;
}
