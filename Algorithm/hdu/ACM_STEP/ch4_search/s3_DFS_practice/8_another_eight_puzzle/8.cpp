#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


bool cf[10][10]={
		{0}, 
		{0, 0, 	1, 	1, 	1, 	0, 	0, 	0, 	0, }, 
		{0, 1, 	0, 	1, 	0, 	1, 	1, 	0, 	0, }, 
		{0, 1, 	1, 	0, 	1, 	1, 	1, 	1, 	0, }, 
		{0, 1, 	0, 	1, 	0, 	0, 	1, 	1, 	0, }, 
		{0, 0, 	1, 	1, 	0, 	0, 	1, 	0, 	1, }, 
		{0, 0, 	1, 	1, 	1, 	1, 	0, 	1, 	1, }, 
		{0, 0, 	0, 	1, 	1, 	0, 	1, 	0, 	1, }, 
		{0, 0, 	0, 	0, 	0, 	1, 	1, 	1, 	0, }, 
};
int filled[10];
bool visited[10];
int P_cnt=0;
int path[10];
//int path[10];

bool Check(int cur){
	for(int i=1;i<=8;i++){
		if((cf[cur][i])&&(filled[i])
			&&(1==abs(filled[i]-filled[cur]))){
			return false;
		}
	}
	return true;
}

int DFS(int cur){
	if(cur==9){
		for(int i=1;i<=8;i++){
			path[i]=filled[i];
		}
		P_cnt++;
		return 0;
	}
	if((filled[cur])){
		if(Check(cur)){
			DFS(cur+1);
		}
		return 0;
	}
	for(int i=1;(i<=8)&&(P_cnt<2);i++)	{
		if(visited[i])continue;
		filled[cur]=i;
		if(Check(cur)){
			visited[i]=true;
			DFS(cur+1);
			visited[i]=false;	
		}
		filled[cur]=0;
	}	
	return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	scanf("%d", &T);
	int casei=1;
	while(casei<=T){
		memset(visited, false, sizeof(visited));
		P_cnt=0;
		for(int i=1;i<=8;i++){
			scanf("%d", &filled[i]);
			if(filled[i]){
				visited[filled[i]]=true;
			}
		}
		
		DFS(1);

		printf("Case %d: ", casei++);
		if(P_cnt==0)printf("No answer\n");
		else if(P_cnt>1)printf("Not unique\n");
		else{
			printf("%d", path[1]);
			for(int i=2;i<=8;i++){
				printf(" %d", path[i]);
			}
			printf("\n");
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
