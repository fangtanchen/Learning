#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAX 502

int in[MAX];
vector<int> map[MAX];
int m, n;
priority_queue<int, vector<int>, greater<int> > qe;

void init(){
	memset(in, 0, sizeof(in));
	for(int i=0;i<=n;i++){
		map[i].clear();
	}
	while(!qe.empty()){
		qe.pop();
	}
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	while(EOF!=scanf("%d%d", &n, &m)){
		init();
		int a, b;
		for(int mi=1;mi<=m;mi++){
			scanf("%d%d", &a, &b);
			map[a].push_back(b);
			in[b]++;
		}
		for(int i=1;i<=n;i++){
			if(in[i]==0){
				qe.push(i);
			}
		}
		int temp=qe.top();
		qe.pop();
		printf("%d", temp);
		for(int i=map[temp].size()-1;i>=0;i--){
			int t=map[temp][i];
			in[t]--;
			if(in[t]==0){
				qe.push(t);
			}
		}
		while(!qe.empty()){
			int temp=qe.top();
			qe.pop();
			printf(" %d", temp);
			for(int i=map[temp].size()-1;i>=0;i--){
				int t=map[temp][i];
				in[t]--;
				if(in[t]==0){
					qe.push(t);
				}
			}
		}
		printf("\n");

	}


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
