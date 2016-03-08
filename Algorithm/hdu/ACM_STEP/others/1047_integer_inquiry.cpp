#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)a
#endif

using namespace std;

char ans[500];
char a[500];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int N;
	scanf("%d", &N);
	while(N--){
		memset(ans, 0, sizeof(ans));
		int ans_len=1;
		if(EOF!=scanf("%s", a), (strlen(a)==1)&&(a[0]=='0')){
			if(!a[0])continue;
			int len=strlen(a);
		}
		
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
