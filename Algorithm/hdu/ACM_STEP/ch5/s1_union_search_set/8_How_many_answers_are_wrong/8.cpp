#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int N, M;
int sum[200010];
int pa[200010];

int init(){
	memset(sum, 0, sizeof(sum));
	for(int ni=N+1;ni>=0;ni--){
		pa[ni]=ni;
	}
}

int find(int x){
	if(x==pa[x])return x;
	int temp=pa[x];
	pa[x]=find(pa[x]);
	sum[x]+=sum[temp];
	return pa[x];
}

int merge(int fa, int fb, int a, int b, int v){
	if(fa>fb){
		pa[fa]=fb;
		sum[fa]=sum[b]-v-sum[a];
	}else{
		pa[fb]=fa;
		sum[fb]=sum[a]+v-sum[b];
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%d%d", &N, &M)){
		init();
		int a, b, v;
		int res=0;
		for(int mi=0;mi<M;mi++){
			scanf("%d%d%d", &a, &b, &v);
			if(a>b){
				int temp=a;
				a=b;
				b=temp;
			}
			b=b+1;
			int fa=find(a);
			int fb=find(b);
			if(fa==fb){
				if(sum[b]!=(sum[a]+v)){
					res++;
				}
			}else{
				merge(fa, fb, a, b, v);
			}
		}
		printf("%d\n", res);

	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
