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


int T;
int N, Q;
int pa[10010];
int cnt[10010];

int init(){
	for(int ni=1;ni<=N;ni++){
		pa[ni]=ni;
	}
	memset(cnt, 0, sizeof(cnt));

}

int find(int x){
	if(x==pa[x])return x;
	int root=pa[x];
	while(root!=pa[root]){
		root=pa[root];
	}
	int j=x;
	while(j!=root){
		int temp=pa[j];
		pa[j]=root;
		j=temp;
	}
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
					for(int i=1;i<=N;i++){
						if(find(i)==fA){
							cnt[i]++;
						}
					}
					pa[fA]=fB;
				}
				
			}else{
				int p;
				scanf("%d", &p);
				int fp=find(p);
				int tt=0;
				for(int i=1;i<=N;i++){
					if(find(i)==fp){
						tt++;
					}
				}
				printf("%d %d %d\n", fp, tt, cnt[p]);
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
