#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAXT 110
char optype[10]="+-*/xy";
int numtype[10];
bool visited[10];
char opstack[10];
int numstack[10];

void Init(){
	memset(visited, false, sizeof(visited))；
}

bool MakeNum(int level){
	if(4==level){
		return MakeOp(0);
	}
	for(int i=0;i<4;i++){
		numstack[level]=numtype[i];
		if(!visited[i]){
			visited[i]=true;
			if(MakeNum(level+1))return true;
			visited[i]=false;
		}
	}
	return false;

}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
