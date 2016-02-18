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

int prime_table[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int map[]={
	0,0,1,1,0,1,0,1,0,0,
	0,1,0,1,0,0,0,1,0,1,
	0,0,0,1,0,0,0,0,0,1,
	0,1,0,0,0,0,0,1,0,0,
	0,1,0,1,0,0,0,1,0,0};
#define MAX_SIZE 30
int n;
bool visited[MAX_SIZE];

int DFS(){
	memset(visited,false,sizeof(visited));
	vector<int > seq;
	seq.push_back(1);
	int path[35];
	int pathi=0;
	
	while(!seq.empty()){
		int np=seq.back();
		//backtrace
		if(visited[np]){
			visited[np]=false;
			if(pathi==n){
				if(1==map[1+np]){
					printf("%d",path[0]);
					for(int i=1;i<n;i++){
						printf(" %d",path[i]);
					}
				printf("\n");
				}
			}
			seq.pop_back();
			pathi--;
			continue;
		}
		// satisfy output
		path[pathi++]=np;

		visited[np]=true;
		for(int ni=n;ni>=2;ni--){
			if((0==map[np+ni])
			||(visited[ni]))
			  continue;
			seq.push_back(ni);
		}
	}

	return -1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int casei=1;
	while(EOF!=scanf("%d",&n))	{
		printf("Case %d:\n",casei++);
		if(!(n%2&&n>1))
			DFS();
		printf("\n");
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
