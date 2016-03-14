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
	int T;
	for(scanf("%d", &T);T--;){
		int n, m;
		scanf("%d%d", &n, &m);
		int cnt=0;
		while(m!=n){
			if(m>n){
				int temp=m;
				m=n;
				n=temp;
			}
			n=n-m;
			cnt++;
		}
		printf("%d\n", cnt+1);

	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
