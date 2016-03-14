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

int f[1020];
int N, M;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%d%d", &N, &M)){
		for(int i=1;i<=N;i++){
			f[i]=i;
		}
		M--;
		while(next_permutation(f+1, f+N+1)){
			M--;
			if(M==0){
				printf("%d", f[1]);
				for(int i=2;i<=N;i++){
					printf(" %d", f[i]);
				}
				printf("\n");
				break;
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
