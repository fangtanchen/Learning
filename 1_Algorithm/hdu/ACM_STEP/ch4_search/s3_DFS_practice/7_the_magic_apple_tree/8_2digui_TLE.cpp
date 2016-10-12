#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int N;
vector<int> map[20003];
int in[20003], out[20004];

char c;
inline void scan(int &x){
	while((c=getchar()), c<'0'||c>'9')
		;
	x=c-'0';
	while((c=getchar()), ((c>='0')&&(c<='9'))){
		x=x*10+c-'0';
	}
}

int DFS(int root){
	if(out[root]==0){
		return root;
	}
	vector<int> record;
	for(int i=0;i<out[root];i++){
		record.push_back(DFS(map[root][i]));
	}
	sort(record.begin(), record.end());
	return record[(1+out[root])/2-1];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int temp, i, ni;
	while(EOF!=scanf("%d", &N)){
		for(i=1;i<=N;i++){
			map[i].clear();
		}
		memset(in, 0, sizeof(in));
		for(ni=1;ni<=N;ni++){
			scan(out[ni]);
			for(i=1;i<=out[ni];i++){
				scan(temp);
				map[ni].push_back(temp);
				in[temp]++;
			}
		}
		int rooti=0;
		for(ni=1;ni<=N;ni++){
			if(0==in[ni]){
				rooti=ni;
				break;
			}
		}

		printf("%d\n", DFS(rooti));
	}

	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
