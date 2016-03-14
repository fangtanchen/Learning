#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

struct Node{
	double m;
	int e;
};

struct Node nodes[55];

int cmp(struct Node &a, Node &b){
	if(a.e<b.e){
		return false;
	}else if(a.e==b.e){
		if(a.m<b.m){
			return false;
		}
	}
	return true;	
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int Q;
	for(scanf("%d", &Q);Q--;){
		int N;
		scanf("%d", &N);
		memset(nodes, 0, sizeof(nodes));
		for(int ni=0;ni<N;ni++){
			scanf("%lf%d", &nodes[ni].m, &nodes[ni].e);
		}
		int ans=0;
		for(int ri=0;ri<N;ri++){
			for(int ci=ri+1;ci<=N;ci++){
				for(int di=ci+1;di<=N+1;di++){
					double tempm=nodes[ri].m+nodes[ci].m+nodes[di].m;
					int tempe=nodes[ri].e+nodes[ci].e+nodes[di].e;
					if(fmod(tempm, 5.0)<1e-2){
						if(tempe>ans)ans=tempe;
					}
				}
			}
		}
		printf("%d\n", ans);

	}
	

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
