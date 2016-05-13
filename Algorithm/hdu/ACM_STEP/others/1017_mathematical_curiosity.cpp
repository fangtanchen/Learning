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

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int N;
	scanf("%d", &N);
	while(N--){
		int n, m;
		int casei=1;
		while(EOF!=scanf("%d%d", &n, &m), n||m){
			printf("Case %d: ", casei++);
			long long sum=0;
			int num=0;
			for(int a=1;a<n;a++){
				for(int b=a+1;b<n;b++){
					sum=(a*a+b*b+m);
					if(sum%(a*b)==0)num++;
				}
			}
			printf("%d\n", num);
		}
		if(N)printf("\n");
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
