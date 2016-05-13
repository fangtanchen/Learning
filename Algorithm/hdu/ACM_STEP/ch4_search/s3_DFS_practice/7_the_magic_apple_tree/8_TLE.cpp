#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

struct SNode{
	int parent;
	int lch;//left children
	int bro;//brother
	int cl_num;
	int apples;
};

int N;
struct SNode nodes[20010];
int rooti=0;
//int record[20010];

int DFS(int cur){
	struct SNode cno=nodes[cur];
	if(cno.apples!=0){
		return 0;
	}
	int chi=cno.lch;
	vector<int> record;
	for(int i=1;i<=cno.cl_num;i++){
		if(0==nodes[chi].apples){
			DFS(chi);
		}
		//record[i]=nodes[chi].apples;
		record.push_back(nodes[chi].apples);
		chi=nodes[chi].bro;
	}
	

	int ppi=(cno.cl_num+1)/2-1;
	sort(record.begin(),record.end());
	nodes[cur].apples=record[ppi];
	return 0;
}
char c;
inline void scan(int &x){
	while((c=getchar()),c<'0'||c>'9')
	  ;
	x=c-'0';
	while((c=getchar()),(c>='0')&&(c<='9')){
		x=x*10+c-'0';
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%d", &N)){
		memset(nodes, 0, sizeof(nodes));
		for(int ni=1;ni<=N;ni++){
			scan(nodes[ni].cl_num);
			int pn=0;
			int temp_n=0;
			for(int i=nodes[ni].cl_num;i>0;i--){
				scan(temp_n);
				nodes[temp_n].parent=ni;
				nodes[temp_n].bro=pn;
				pn=temp_n;
			}
			nodes[ni].lch=temp_n;
			if(0==nodes[ni].cl_num){
				nodes[ni].apples=ni;
			}
		}
		rooti=0;
		for(int ni=1;ni<=N;ni++){
			if(0==nodes[ni].parent){
				rooti=ni;
				break;
			}
		}
		DFS(rooti);
		printf("%d\n", nodes[rooti].apples);
	}

	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
