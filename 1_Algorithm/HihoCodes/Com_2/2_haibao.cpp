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
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	bool bv[5];
	int cnt;
	int pa;
};

Node nodes[1001];


int Judge(Node a, Node b){//judge liandai
	if(((a.x1>=b.x2))
		||(a.x2<=b.x1)
		||(a.y1>=b.y2)
		||(a.y2<=b.y1)){
		return 0;
	}
	return 1;
}


bool Fugai(Node a, Node b){//judge a is below b
	
	if((a.x1<=b.x1)&&(a.y1<=b.y1)
		&&(a.x2>=b.x2)&&(a.y2>=b.y2))
		return true;
	return false;
}

bool InMap(int x1, int y1, Node n){
	if((x1>=n.x1)&&(x1<=n.x3)
		&&(y1>=n.y1)&&(y1<=n.y2)){
		return true;
	}
	return false;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int W, H, N;
	scanf("%d%d%d", &W, &H, &N);

	memset(dp, 0, sizeof(dp));

	int a, b, c, d;
	for(int i=1;i<=N;i++){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(a>c){
			int temp=a;a=c;c=temp;
		}
		if(b>d){
			int temp=b;	b=d;d=temp;
		}
		nodes[i].x1=a;nodes[i].y1=b;
		nodes[i].x2=a;nodes[i].y2=d;
		nodes[i].x3=c;nodes[i].y3=b;
		nodes[i].x4=c;nodes[i].y2=d;
		nodes[i].cnt=1;
		nodes[i].pa=i;
	}

	for(int i=N;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			if(InMap(nodes[i].x1, nodes[i].y1, nodes[j])){
				
			}
		}
	}

	printf("%d %d\n", cnt, cnt_index);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
