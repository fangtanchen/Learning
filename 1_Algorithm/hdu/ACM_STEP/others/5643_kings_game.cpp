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

int f[2][5002];
int ans[5002];
int si, di;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	memset(f, 0, sizeof(f));
	memset(ans, 0, sizeof(ans));
	si=0;
	di=1;
	for(int ni=2;ni<=5000;ni++){
		for(int ki=1;ki<=5000;ki++){
			f[di][ki]=(f[si][ki+1]+ki)%ni;
		}
		ans[ni]=f[di][1];
		si=1-si;
		di=1-di;
	}
		
	int T=0;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n]+1);

	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
