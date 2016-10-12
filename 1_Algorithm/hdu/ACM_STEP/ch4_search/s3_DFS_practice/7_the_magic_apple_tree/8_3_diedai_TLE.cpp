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

vector<int> seq;
int apples[20003];
bool visited[20003];

int DFS(int root){
	seq.push_back(root);
	
	while(!seq.empty()){
		int np=seq.back();
		if(out[np]==0){
			seq.pop_back();
			continue;
		}
		if(visited[np]){
			seq.pop_back();
			vector<int>	 tmp;
			for(int i=0;i<out[np];i++){
				tmp.push_back(apples[map[np][i]]);
			}
			sort(tmp.begin(), tmp.end());
			apples[np]=tmp[(1+out[np])/2-1];
			continue;
		}
		visited[np]=true;
		for(int i=0;i<out[np];i++){
			if(0==apples[map[np][i]]){
				seq.push_back(map[np][i]);
			}
		}	
	}
	return 0;
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
		memset(visited, false, sizeof(visited));
		memset(apples, 0, sizeof(apples));
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
		for(ni=1;ni<=N;ni++){
			if(0==out[ni]){
				apples[ni]=ni;
			}
		}
//		if(N==1){
//			printf("1\n");
//			continue;
//		}
		DFS(rooti);
		printf("%d\n", apples[rooti]);
	}

	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
