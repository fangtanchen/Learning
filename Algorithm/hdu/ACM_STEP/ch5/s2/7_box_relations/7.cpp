#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAXN 1010
#define MAXE 2020

int inx[MAXE], iny[MAXE], inz[MAXE];
int rex[MAXE], rey[MAXE], rez[MAXE];
vector<int> mx[MAXE], my[MAXE], mz[MAXE];
int N, R;

void init(){
	memset(inx, 0, sizeof(inx));
	memset(iny, 0, sizeof(iny));
	memset(inz, 0, sizeof(inz));

	for(int i=2*N;i>=1;i--){
		mx[i].clear();
		my[i].clear();
		mz[i].clear();
	}
}

bool solve(int in[], vector<int> map[], int ans[]){
	queue<int> qe;
	int maxi=2*N;
	for(int i=1;i<=maxi;i++){
		if(in[i]==0){
			qe.push(i);
		}
	}
	int num=0;
	while(!qe.empty()){
		int tp=qe.front();
		qe.pop();
		ans[tp]=num++;
		int maxi=map[tp].size()-1;
		for(int i=0;i<=maxi;i++){
			int temp=map[tp][i];
			in[temp]--;
			if(0==in[temp]){
				qe.push(temp);
			}
		}
	}
	if(num==2*N)return true;
	else return false;

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int casei=1;
	while(scanf("%d%d", &N, &R), N+R){
		init();
		for(int ni=1;ni<=N;ni++){
			inx[ni+N]++;
			iny[ni+N]++;
			inz[ni+N]++;
			mx[ni].push_back(ni+N);
			my[ni].push_back(ni+N);
			mz[ni].push_back(ni+N);
		}
		char s[5];
		int a, b;
		for(int ni=1;ni<=R;ni++){
			scanf("%s%d%d", s, &a, &b);
			switch(s[0]){
				case 'I':
					inx[b+N]++;
					inx[a+N]++;
					mx[a].push_back(b+N);
					mx[b].push_back(a+N);
					iny[b+N]++;
					iny[a+N]++;
					my[a].push_back(b+N);
					my[b].push_back(a+N);
					inz[b+N]++;
					inz[a+N]++;
					mz[a].push_back(b+N);
					mz[b].push_back(a+N);
					break;
				case 'X':
					inx[b]++;
					mx[a+N].push_back(b);
					break;
				case 'Y':
					iny[b]++;
					my[a+N].push_back(b);
					break;
				case 'Z':
					inz[b]++;
					mz[a+N].push_back(b);
					break;
				default:
					break;
			}
		}
		bool flag=true;
		if(!solve(inx, mx, rex))flag=false;
		if(!solve(iny, my, rey))flag=false;
		if(!solve(inz, mz, rez))flag=false;
		if(flag){
			printf("Case %d: POSSIBLE\n", casei++);
			for(int i=1;i<=N;i++){
				printf("%d %d %d %d %d %d\n", 
						rex[i], rey[i], rez[i], 
						rex[i+N], rey[i+N], rez[i+N] );
			}
		}else{
			printf("Case %d: IMPOSSIBLE\n", casei++);
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
