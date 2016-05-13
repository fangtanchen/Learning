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


int K;
bool flag;
bool visited[100];

void init(){
	flag=true;
	memset(visited, false, sizeof(visited));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	for(scanf("%d", &T); T--;){

		init();
		scanf("%d", &K);
		int pathx[100];
		int pathy[100];
		int path[100];
		for(int i=0;i<K;i++){
			scanf("%d", path+i);
			if(K>9)continue;
			if(path[i]>9){
				flag=false;
				continue;
			}
			pathx[i]=(path[i]-1)/3+1;
			pathy[i]=(path[i]-1)%3+1;
		}
		if(K<4||K>9||!flag){
			printf("invalid\n");
			continue;
		}
		visited[path[0]]=true;
		for(int i=1;i<K;i++){
			int j=i-1;
			int numi=path[i];
			int numj=path[j];
			if(visited[numi]){
				flag=false;
				break;
			}
			if(!flag)break;
			if(((pathx[i]+pathx[j])%2==0)&&((pathy[i]+pathy[j])%2==0)){
				int midx=(pathx[i]+pathx[j])/2;
				int midy=(pathy[i]+pathy[j])/2;
				int temp=(midx-1)*3+midy;
				if(!visited[temp]){
					flag=false;
					break;
				}
			}
			visited[numi]=true;
		}
		
		if(flag){
			printf("valid\n");
		}else{
			printf("invalid\n");
		}	
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
