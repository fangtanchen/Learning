#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


#define MAX_R 1001
#define MAX_C 70

int f[MAX_R][MAX_C];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	memset(f, 0, sizeof(f));
	f[1][0]=1;
	f[2][0]=1;
	for(int pi=3;pi<=MAX_R;pi++){
		int c=0;
		for(int i=0;i<MAX_C;i++){
			f[pi][i]=f[pi-1][i]+f[pi-2][i]+c;
			c=f[pi][i]/10000;
			f[pi][i]%=10000;
		}
	}
	int N;
	scanf("%d", &N);
	while(N--){
		int p;
		scanf("%d", &p);
		int i;
		for(i=MAX_C-1;0==f[p][i];i--)
			;
		printf("%d", f[p][i--]);
		for(;i>=0;i--){
			printf("%04d", f[p][i]);
		}
		printf("\n");
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
