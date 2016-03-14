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
int cnt=0;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	for(scanf("%d", &T);T--;){
		int n, m;
		scanf("%d%d", &n, &m);
		int ans=0;
		while(m){
			ans=ans+n/m;
			n=n%m;
			if(m>n){
				int temp=m;
				m=n;
				n=temp;
			}
		}
		printf("%d\n", ans);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
