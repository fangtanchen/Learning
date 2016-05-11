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


int pre[1000];

int find(int x){
	int r=x;
	while(r!=pre[r]){
		r=pre[r];
	}
	int xi=x;
	while(xi!=r){
		int temp=pre[xi];
		pre[xi]=r;
		xi=temp;
	}
	return r;
}

void join(int x, int y){
	int fx=pre[x];
	int fy=pre[y];
	if(fx!=fy){
		pre[fx]=fy;
	}
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
