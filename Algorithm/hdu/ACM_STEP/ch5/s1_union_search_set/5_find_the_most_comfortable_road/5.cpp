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

const int maxn=205;
const int maxm=1005;
const int inf=(0x7f7f7f7f);

#define min(a, b) (((a)<(b))?(a):(b))

struct CEdge{
	int s;
	int t;
	int sp;
};

int n, m, q;
int pa[maxn];
struct CEdge edges[maxm];


bool cmp(const CEdge &x, const CEdge &y){
	if(x.sp>y.sp)return false;
	else return true;
}

int find(int x){
	if(x==pa[x])return x;
	pa[x]=find(pa[x]);
	return pa[x];
}

int merge(int x, int y){
	int fx=find(x);
	int fy=find(y);
	pa[fx]=fy;
	return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%d%d", &n, &m)){
		for(int mi=0;mi<m;mi++){
			scanf("%d%d%d", &edges[mi].s, &edges[mi].t, &edges[mi].sp);		
		}
		sort(edges, edges+m, cmp);
		int q;
		scanf("%d", &q);
		while(q--){
			int s, t;
			scanf("%d%d", &s, &t);

			int res=inf;
			for(int mi=0;mi<m;mi++){
				for(int ni=1;ni<=n;ni++){
					pa[ni]=ni;
				}
				for(int mj=mi;mj<m;mj++){
					merge(edges[mj].s, edges[mj].t);
					if(find(s)==find(t)){
						res=min(res, edges[mj].sp-edges[mi].sp);
						break;
					}
				}
			}
			if(inf==res){
				printf("-1\n");
			}else{
				printf("%d\n", res);
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
