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

struct Node{
	int num;
	int ri;
	int ci;
};

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	for(scanf("%d", &T);T--;){
		int k;
		bool flag=true;
		scanf("%d", &k);
		Node nodes[11];
		for(int i=0;i<k;i++)
		{
			int temp;
			scanf("%d", &temp);
			if(temp>9||temp==0||!flag){
				flag=false;
				continue;
			}
			nodes[i].num=temp;
			nodes[i].ri=(temp-1)/3;
			nodes[i].ci=(temp-1)%3;
		}
		if(k<4||(!flag)){
			printf("invalid\n");
			continue;
		}
		bool visited[10];
		memset(visited, false, sizeof(visited));

		visited[nodes[0].num]=true;
		for(int i=1;i<k;i++){
			if(!flag || (visited[nodes[i].num])){
				flag=false;
				break;
			}
			visited[nodes[i].num]=true;
			int sumx=nodes[i].ri+nodes[i-1].ri;
			int sumy=nodes[i].ci+nodes[i-1].ci;
			if((sumx%2==0)&&(sumy%2==0)){
				int temp=(sumx/2)*3+(sumy/2)+1;
				if(!visited[temp]){
					flag=false;
					break;
				}
			}
		}
		if(flag){
			printf("valid\n");
		}
		else{
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
