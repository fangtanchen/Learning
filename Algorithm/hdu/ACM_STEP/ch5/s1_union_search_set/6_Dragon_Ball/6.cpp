#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif



using namespace std;


int T;
int N, Q;
int pa[10010];
int cnt[10010];
int total[10010];

int init(){
	for(int ni=1;ni<=N;ni++){
		pa[ni]=ni;
		total[ni]=1;
	}
	memset(cnt, 0, sizeof(cnt));

}

int find(int x){
	if(x==pa[x])return x;

	int root=find(pa[x]);
	cnt[x]=cnt[x]+cnt[pa[x]];
	pa[x]=root;
	return root;
}

int merge(int x,  int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)return 0;
	pa[fx]=fy;
	return 1;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	scanf("%d", &T);
	int casei=1;
	while(T--){
		printf("Case %d:\n", casei++);
		scanf("%d%d", &N, &Q);
		init();
		while(Q--){
			char c;
			getchar();
			scanf("%c", &c);
			if(c=='T'){
				int A, B;
				scanf("%d%d", &A, &B);
				int fA=find(A);
				int fB=find(B);
				if(fA!=fB){
					pa[fA]=fB;
					cnt[fA]++;
					total[fB]+=total[fA];
				}
				
			}else{
				int p;
				scanf("%d", &p);
				int fp=find(p);
				int tt=0;
				printf("%d %d %d\n", fp, total[fp], cnt[p]);
			}
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
