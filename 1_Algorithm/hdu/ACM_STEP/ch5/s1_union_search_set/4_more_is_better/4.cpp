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


#define MAX_SIZE 10000010

int n;
int pa[200020];
int cnt[200020];
int ha[MAX_SIZE];

void init(){
	memset(cnt, 0, sizeof(cnt));
	memset(ha, -1, sizeof(ha));
	for(int ni=1;ni<200020;ni++){
		pa[ni]=ni;
	}
}

int find(int x){
	if(x==pa[x])return x;
	int root=pa[x];
	while(root!=pa[root]){
		root=pa[root];
	}
	int no=x;
	while(no!=root){
		int temp=pa[no];
		pa[no]=root;
		no=temp;
	}
	return root;
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
	//	freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%d", &n)){
		init();
	
		int a, b;
		int ha_len=1;
		for(int ni=0;ni<n;ni++)		{
			scanf("%d%d", &a, &b);
			if(-1==ha[a]){
				ha[a]=ha_len++;
			}
			if(-1==ha[b]){
				ha[b]=ha_len++;
			}
			merge(ha[a], ha[b]);
		}
		for(int ni=1;ni<ha_len;ni++){
			int fa=find(ni);
			cnt[fa]++;
		}
		int max=1;
		for(int ni=1;ni<ha_len;ni++){
			if(max<cnt[ni]){
				max=cnt[ni];
			}
		}
		printf("%d\n", max);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
