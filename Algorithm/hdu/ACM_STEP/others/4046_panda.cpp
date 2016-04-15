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
#define MAXN 50010
#define MAXM 10010

int tree[MAXN];

int lowbit(int k){
	return k&-k;
}

int add(int k,  int a){
	while(k<MAXN){
		tree[k]+=a;
		k+=lowbit(k);
	}
	return 0;
}

int query(int k){
	int sum=0;
	while(k>0){
		sum+=tree[k];
		k-=lowbit(k);
	}
	return sum;
}

char le[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int T;
	scanf("%d", &T);
	for(int i=1;i<=T;i++){
		printf("Case %d:\n", i);
		int N, M;
		scanf("%d%d", &N, &M);
		scanf("%s", le);
		memset(tree, 0, sizeof(tree));
		for(int i=2;i<N;i++){
			if(le[i]=='w'&&(le[i-1]=='b)
					&&(le[i-2]=='w')){

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
