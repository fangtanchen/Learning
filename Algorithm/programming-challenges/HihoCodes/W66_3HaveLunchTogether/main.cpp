#include <iostream>
#include<cstdio>
#include<cstring>
#include<vector>

//#define RD_STREAM
//#define USER_DEBUG

#ifdef RD_STREAM
#pragma warning(disable:3399)
#endif

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char map[105][105];
int step[105][105];//step[i][j]表示 到点(i, j)的最小步数 
int n,m;
vector< pair<int, int> > seq;

bool InMap(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m
	&&(map[x][y]=='.'||map[x][y]=='S'))
		return true;
	else 
		return false;
}

int BFS(int startx,int starty){
	step[startx][starty]=0;
	seq.push_back(make_pair(startx,starty));
	int seqi=0;
	while(seqi<(int)seq.size()){	
		int tempx,tempy;
		for(int diri=0;diri<4;diri++){
			tempx=seq[seqi].first+dir[diri][0];
			tempy=seq[seqi].second+dir[diri][1];
			if(InMap(tempx,tempy)&&step[tempx][tempy]==-1){
				step[tempx][tempy]=
				1+step[seq[seqi].first][seq[seqi].second];
				if('.'==map[tempx][tempy]){
					seq.push_back(make_pair(tempx,tempy));
				}
			}
		}
		seqi++;
	}
	#ifdef USER_DEBUG
		cout<<"\n\nthe results of BFS:"<<endl;
		for(int ri=1;ri<=n;ri++){
			for(int ci=1;ci<=m;ci++){
				printf("%4d  ",step[ri][ci]);
			}
			cout<<endl;
		}
	#endif
	return 0;
}


int main(int argc, char** argv) {
	#ifdef RD_STREAM
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	//int n,m;
	cin>>n>>m;
	for(int ri=1;ri<=n;ri++){
		scanf("%s",map[ri]+1);
	}
	int startx,starty;
	int flag=0;
	for(int ri=1;ri<=n;ri++){
		if(flag)break;
		for(int ci=1;ci<=m;ci++){
			if('H'==map[ri][ci]){
				startx=ri;
				starty=ci;
				flag=1;
				break;
			}
		}		
	}
	#ifdef USER_DEBUG
		for(int ri=1;ri<=n;ri++)
		{
			for(int ci=1;ci<=m;ci++){
				printf("%c", map[ri][ci]);
			}
			printf("\n");
		}
		
		//printf("startx:%d  starty:%d\n",startx, starty);
	#endif
	
	memset(step,-1,sizeof(step));
	BFS(startx,starty);
	
	unsigned int res=0xFFFFFFFF;
	for(int ri=1;ri<=n;ri++){
		for(int ci=1;ci<=m;ci++){
			if(map[ri][ci]=='S'&&step[ri][ci]!=-1){
				if(map[ri+1][ci]=='S'&&step[ri+1][ci]!=-1
				&&res>step[ri][ci]+step[ri+1][ci]){
					res=step[ri][ci]+step[ri+1][ci];	
				}
				else if(map[ri][ci+1]=='S'&&step[ri][ci+1]!=-1
				&&res>step[ri][ci]+step[ri][ci+1]){
					res=step[ri][ci]+step[ri][ci+1];
				}				
			}
		}
	}
	if(res<0xFFFFFFFF){
		cout<<res<<endl;
	}
	else 
		cout<<"Hi and Ho will not have lunch."<<endl;
	
	#ifdef RD_STREAM
		fclose(stdin);
		fclose(stdout);
		system("out.txt");	
	#endif
	return 0;
}
