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

int f[1000010]={1, 2};
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	for(int ni=2;ni<=1000000;ni++){
		f[ni]=(f[ni-1]+f[ni-2])%3;
	}

	int n;
	while(EOF!=scanf("%d", &n)){
		if(f[n])printf("no\n");
		else printf("yes\n");
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
