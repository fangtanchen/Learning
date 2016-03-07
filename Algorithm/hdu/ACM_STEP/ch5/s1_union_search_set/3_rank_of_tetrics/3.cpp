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

vector<int> map[10010];
queue<int> qe;
int N, M;
int in[10010];
int pa[10010];
int a[10010];
int b[10010];
char c[10010];
bool visited[10010];

int scan(){
	int ch;
	while ((ch = getchar()), ch<'0' || ch>'9'){
		;
	}
	int num = ch - 48;
	while ((ch = getchar()), (ch >= '0') && (ch <= '9')){
		num = num * 10 + ch - 48;
	}
	return num;
}

void init(){
	memset(in, 0, sizeof(in));
	memset(visited, 0, sizeof(visited));
	for (int ni = 0; ni < N; ni++){
		pa[ni] = ni;
		map[ni].clear();
	}
	while (!qe.empty()){
		qe.pop();
	}
}

int find(int x){
	if (x == pa[x])return x;
	int temp = x;
	int root = pa[x];
	while (root != pa[root]){
		root = pa[root];
	}
	int j = x;
	while (j != root){
		temp = pa[j];
		pa[j] = root;
		j = temp;
	}
	return root;
}

int merge(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if (fx == fy)
		return 0;
	pa[fx] = fy;
	return 1;
}

int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	while (EOF != scanf("%d%d", &N, &M)){
		init();
		int pnum = N;
		for (int mi = 0; mi < M; mi++){
			a[mi] = scan();
			c[mi] = getchar();
			b[mi] = scan();
			if (c[mi] == '='){
				pnum -= merge(a[mi], b[mi]);
			}
		}

		for (int mi = 0; mi < M; mi++){
			int fa = find(a[mi]);
			int fb = find(b[mi]);
			if (c[mi] == '>'){
				in[fb]++;
				map[fa].push_back(fb);
			}
			else if (c[mi] == '<'){
				in[fa]++;
				map[fb].push_back(fa);
			}
		}
		int cnt = 0;
		bool stan = true;
		for (int i = 0; i < N; i++){
			int fi = find(i);
			if ((0 == in[fi])&&(!visited[fi])){
				visited[fi] = true;
				qe.push(fi);
				cnt++;
			}
		}
		if (stan && (cnt>1)){
			stan = false;
		}

		while (!(qe.empty())){
			int temp = qe.front();
			qe.pop();
			pnum--;
			
			int cnt = 0;
			for (int i = map[temp].size() - 1; i >= 0; i--){
				int kk = find(map[temp][i]);
				in[kk]--;
				if ((!visited[kk]) && (0 == in[kk])){
					visited[kk] = true;
					qe.push(kk);
					cnt++;
				}
			}
			if (stan && (cnt > 1)){
				stan = false;
			}

		}

		if (pnum){
			printf("CONFLICT\n");
		}
		else if (stan){
			printf("OK\n");
		}
		else{
			printf("UNCERTAIN\n");
		}
	}

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
