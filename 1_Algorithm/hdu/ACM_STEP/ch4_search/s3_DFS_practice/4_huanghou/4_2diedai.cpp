#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

#define MAX_SIZE 20
int N;
int ans;
int ca[MAX_SIZE];
int cb[MAX_SIZE];
int cc[MAX_SIZE];

bool Check(int ri, int ci){
	if(ri>N)return false;
	int flag=true;
	for(int i=1;i<ri;i++){
		if(ci==ca[i]
		||(ri-ci==cb[i])
		||(ri+ci==cc[i])){
			flag=false;
		}
	}
	return flag;
}

int DFS(){
	vector<pair<int,int> > seq;
	for(int ci=1;ci<=N;ci++){
		seq.push_back(make_pair(1,ci));
		bool visited[MAX_SIZE];
		memset(visited,false, sizeof(visited));
		while(!seq.empty()){
			pair<int, int> np(seq.back());
			if(visited[np.first]||(np.first==N)){
				if(np.first==N)	ans++;
				visited[np.first]=false;
				seq.pop_back();
				continue;
			}

			visited[np.first]=true;
			int temp_ri=np.first+1;
			ca[np.first]=np.second;
			cb[np.first]=np.first-np.second;
			cc[np.first]=np.first+np.second;
			for(int temp_ci=1;temp_ci<=N;temp_ci++){
				if(Check(temp_ri,temp_ci)){
					seq.push_back(make_pair(temp_ri,temp_ci));
				}
			}

		}
	}


	return 0;
}

int main(){
	int f[15];
	for(N=1;N<=10;N++){
		ans=0;
		DFS();
		f[N]=ans;
	}
	while(EOF!=scanf("%d",&N),N){
		printf("%d\n",f[N]);
	}

	return 0;
}
