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

#define MAXN 1000010
#define MAXM 510

int map[MAXM][MAXM];
int tree[MAXN];
int n, r;
int midnum;

int lowbit(int k){
	return k&-k;
} 

void init(){
	memset(tree, 0, sizeof(tree));
}

int add(int x, int a){
	while(x<MAXN){
		tree[x]+=a;
		x+=lowbit(x);
	}
	return 0;
}

int query(int x){
	int sum=0;
	while(x>0){
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}

int bin(){
	int lr=1, rt=MAXN;
	while(lr<rt){
		int mid=(lr+rt)/2;
		if(query(mid)<midnum)lr=mid+1;
		else rt=mid;
	}
	return lr-1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%d%d", &n, &r), n||r){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d", map[i]+j);
				map[i][j]++;
			}
		}

		for(int j=2*r+1;j>0;j--){
			for(int i=2*r;i>=0;i++){
				add(map[i][j], 1);
			}
		}

		int min0=1, min1=r+1, min2=2*r+1;
		int max2=n-2*r, max1=n-r, max0=n;
		int tempi1, tempi2, tempj1, tempj2;
		midnum=(min2*min2)/2+1;

		for(int i=min1;i<=max1;){
			//downside
			tempi1=i-1-r;
			tempi2=i+r;
			for(int k=min0;k<=min2;k++){
				add(map[tempi1][k], -1);
				add(map[tempi2][k], 1);
			}
			map[i][min1]=bin();

			// right
			//
			tempi1=i-r;tempi2=i+r;
			for(int j=r+2;j<=max1;j++){
				tempj1=j-1-r;tempj2=j+r;
				for(int k=tempi1;k<=tempi2;k++){
					add(map[k][tempj1], -1);
					add(map[k][tempj2], 1);
				}
				map[i][j]=bin();
			}
			i++;
			if(i>max1)break;

			//down
			tempi1=i-1-r;tempi2=i+r;
			for(int j=max2;j<=max0;j++){
				add(map[tempi1][j], -1);
				add(map[tempi2][j], 1);
			}
			map[i][max1]=bin();

			//left
			tempi1=i-r, tempi2=i+r;
			for(int j=max1-1;j>=min1;j--){
				tempj1=j+1+r, tempj2=j-r;
				for(int k=tempi1;k<=tempi2;k++){
					add(map[k][tempj1], -1);
					add(map[k][tempj2], 1);
				}
				map[i][j]=bin();
			}
			i++;
		}
		for(int i=min1;i<=max1;i++){
			printf("%d", map[i][min1]-1);
			for(int j=min1+1;j<=max1;j++){
				printf(" %d", map[i][j]-1);
			}
			printf("\n");
		}
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
