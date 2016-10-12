#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

const int maxn=1111;
bool can[maxn];
vector<int> G[maxn];
bool vis[maxn];

struct Pt{
	int x, y;
	Pt(){}
	Pt(int a, int b){
		x=a;y=b;
	}
	void in(){
		scanf("%d%d", &x, &y);
	}
};

struct P{
	Pt p1, p2;
	void input(){
		p1.in();p2.in();
	}
}p[maxn];

bool pin1(Pt a, P b){
	if((a.x>b.p1.x)
		&&(a.y>b.p1.y)
		&&(a.x<b.p2.x)
		&&(a.y<b.p2.y))
		return true;
	else
		return false;
}

bool over(P a, P b){
	Pt c, d;
	c=Pt(max(a.p1.x, b.p1.x), max(a.p1.y, b.p1.y));
	d=Pt(min(a.p2.x, b.p2.x), min(a.p2.y, b.p2.y));
	if(c.x<d.x&&(c.y<d.y))return true;
	else return false;
}



int DFS(int x){
	if(vis[x])return 0;
	vis[x]=true;
	int ret=1;
	int len=G[x].size();
	for(int i=0;i<len;i++){
		ret+=DFS(G[x][i]);
	}
	return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int w, h, n;
	while(EOF!=scanf("%d%d%d", &w, &h, &n)){
		for(int i=1;i<=n;i++){
			p[i].input();
			G[i].clear();
			can[i]=true;
		}

		for(int i=1;i<=n;i++){
			int flag=0;
			for(int j=i+1;j<=n;j++){
				if((over(p[i], p[j]))){
					G[i].push_back(j);
				}
				if(pin1(p[i].p1, p[j]))flag|=1;
				if(pin1(p[i].p2, p[j]))flag|=2;
				if(pin1(Pt(p[i].p1.x, p[i].p2.y), p[j]))flag|=4;
				if(pin1(Pt(p[i].p2.x, p[i].p1.y), p[j]))flag|=8;
			}
			if(15==flag)can[i]=false;
		}
		int ans1=0, ans2=-1;
		for(int i=1;i<=n;i++){
			if(can[i]){
				memset(vis, false, sizeof(vis));
				int temp=DFS(i);
				if(temp>ans2){
					ans1=i;
					ans2=temp;
				}
			}
		}
		printf("%d %d\n", ans2,  ans1);

	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
